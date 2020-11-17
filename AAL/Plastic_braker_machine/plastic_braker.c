/*
 * plastic_braker.c
 *
 * Created: 10/11/2020 04:47:25 م
 *  Author: mo
 */ 

#include "plastic_braker.h"


void init_fun_plastic(void)
{
/*initialization of magnetic sensor*/
DIO_init(&Dio_D_magnetic);
/*initialization of on off switch*/
DIO_init(&Dio_B_On_Off);
/*initialization of the alarm output*/
DIO_init(&Dio_D_ALARM);
/*initialization of the motor output*/
DIO_init(&Dio_B_MOTOR);
/*****************************************************************EXTERNAL INT INIT FOR SW1,SW2,OFF***************************************/

/*GLOBAL INTERRUPT ENABLE G_interrupt_Enable();*/
/*OFF_SW
 EX_interrupt_enable2();*/
/*SW2
 EX_interrupt_enable1();*/
/*SW1
 EX_interrupt_enable0();
*/


}


void on_switch_int(void)
{



}

void off_switch_int(void)
{
/*Motor_stop*/


}


void sw_int(void)
{
 
if(READBIT(MCUCSR,6))
{	/**if rising edge*/
	/*Motor_start*/
	DIO_Write(GPIOB,BIT5,HIGH);
	CLEAR_BIT(MCUCSR,6);
}
else{
/*if fallen edge*/
DIO_Write(GPIOB,BIT5,HIGH);
/*Motor_stop*/
/*********************************/
SET_BIT(MCUCSR,6);		/*Make it Rising*/
/********************************/
}

}

