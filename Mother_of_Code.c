/*
 * Mother_of_Code.c
 *
 * Created: 30/10/2020 02:47:30 ص
 *  Author: mo
 */
#include "SL/SOS/SOS.h"
#include "ECUAL/SWdelay/softwareDelay.h"
#include "AAL/Plastic_braker_machine/plastic_braker.h"
#include "MCAL/uart_Send.h"
/*Badawy machine init */
static uint8_t u8_plastic_state = NO_ACTION_PLAS;
static uint16_t u16_delay = 0;

void badawy_machine_init(void)
{
	Uart_Init(Baud9600, OneStopBit, NoParity, EightBits, ASynchronous);
	DIO_init(&Dio_configurationB);
	DIO_init(&Dio_configurationC);
	DIO_init(&Dio_configurationD);
	SOS_Init(&TMU_Configuration);
	SOS_Create_Task(Read_Time_Task, 1, 1, 5);
	SOS_Create_Task(update_timing, 1, 4, 1);
	SOS_Create_Task(Push_Task1, 1, 3, 2);
}

void plastic_breaker_loop(void)
{
	static uint8_t on_state = 0, off_state = 0, sw1_state = 0, sw2_state = 0;
	/*check if on pressed*/
	DIO_Read(GPIOB, BIT1, &on_state);
	DIO_Read(GPIOB, BIT2, &off_state);
	DIO_Read(GPIOD, BIT2, &sw1_state);
	DIO_Read(GPIOD, BIT3, &sw2_state);
	if ((on_state == HIGH && off_state == LOW && sw2_state == HIGH && sw1_state == HIGH) && (u8_plastic_state == NO_ACTION_PLAS))
	{
		/*ALARM_START*/
		DIO_Write(GPIOB, BIT4, HIGH);
		u8_plastic_state = FIRST_SAFE_POS;
	}
	if (on_state == LOW && u8_plastic_state == FIRST_SAFE_POS)
	{
		u8_plastic_state = SECOND_SAFE_POS;
	}

	if ((sw2_state == HIGH && sw1_state == HIGH && off_state == LOW && on_state == HIGH) && (u8_plastic_state == SECOND_SAFE_POS))
	{
		/*MOTOR_WORKING_START*/
		//SwDelay_ms(3000);
		u16_delay++;
		DIO_Write(GPIOB, BIT4, LOW);
		DIO_Write(GPIOB, BIT5, HIGH);
		DIO_Write(GPIOB, BIT7, LOW);
		DIO_Write(GPIOB, BIT6, HIGH);
		u8_plastic_state = MOTOR_WORKING_STAR;
	}
	if ((sw2_state == HIGH && sw1_state == HIGH && off_state == LOW && on_state == HIGH) && (u8_plastic_state == SECOND_SAFE_POS) && (u8_plastic_state == MOTOR_WORKING_STAR && u16_delay >= 1000))
	{
		u16_delay = 0;
		/*MOTOR_WORKING_START*/
		//SwDelay_ms(3000);
		DIO_Write(GPIOB, BIT4, LOW);
		DIO_Write(GPIOB, BIT5, HIGH);
		DIO_Write(GPIOB, BIT6, LOW);
		DIO_Write(GPIOB, BIT7, HIGH);
		u8_plastic_state = MOTOR_WORKING_DELTA;
	}

	if (((u8_plastic_state == MOTOR_WORKING_DELTA || u8_plastic_state == MOTOR_WORKING_STAR) && (off_state == HIGH)) || ((u8_plastic_state == MOTOR_WORKING_DELTA || u8_plastic_state == MOTOR_WORKING_STAR) && (sw1_state == LOW || sw2_state == LOW)))
	{

		/*turn off the machine*/
		DIO_Write(GPIOB, BIT4, LOW);
		DIO_Write(GPIOB, BIT5, LOW);
		DIO_Write(GPIOB, BIT6, LOW);
		DIO_Write(GPIOB, BIT7, LOW);
		u8_plastic_state = NO_ACTION_PLAS;
	}
}

void alarm_flashing(void)
{
	if (u8_plastic_state == FIRST_SAFE_POS || u8_plastic_state == SECOND_SAFE_POS)
	{
		DIO_Toggle(GPIOB, BIT4);
	}
}

void debug(void)
{

	UartTransmitPooling('B');
	uart_transmit_u16(PORTB_DATA);
	UartTransmitPooling('C');
	uart_transmit_u16(PORTC_DATA);
	UartTransmitPooling('D');
	uart_transmit_u16(PORTD_DATA);
}
void plastic_breaker_init(void)
{
	Uart_Init(Baud9600, OneStopBit, NoParity, EightBits, ASynchronous);
	init_fun_plastic();
	SOS_Init(&TMU_Configuration);
	SOS_Create_Task(plastic_breaker_loop, 1, 1, 5);
	SOS_Create_Task(alarm_flashing, 1, 2, 100);
	SOS_Create_Task(debug, 1, 3, 10);
}

int main(void)
{
	plastic_breaker_init();
	/*badawy_machine_init();*/

	while (1)
	{
		SOS_Run();
	}
}