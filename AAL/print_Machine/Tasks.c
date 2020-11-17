/*
 * Tasks.c
 *
 * Created: 30/10/2020 02:21:21 ص
 *  Author: mo
 */ 
#include "Tasks.h"
 static uint8_t u8_State_Machine = NO_ACTION;
static  ptr_to_Fun timing_array[3] = {relay0,relay1,relay2};
	 static uint8_t arr_of_ptr = 0;
	static uint16_t counting_arr[3]={0,0,0};
	static uint8_t u8_flag_push = 0;
 uint8_t u8_Init_finished=0;
uint16_t Timing_arr[3]={10,20,30};
static uint8_t stu8_increment=0;

void Display_Task(void)
{
/*	
	static uint8_t u8count=0;
	static uint8_t twoDarr[][32]={"1.Is 5 + 2 = 7 ?  ","2.IS Earth Flat ?",
	"3.Do You like Chocolate? ","4.Do You like Embedded Systems ? ","5.Do You Know My name ? ","6.NO ","7.YES ","8.False Answer!! ","9.Correct Answer!! ","10.Game Over"};
static uint8_t X_value=0;
static uint8_t Y_value=0;

if (u8_Init_finished==1)
{
	if (stu8_increment<10)
	{
		if (u8count < 16)
		{
			X_value=u8count;
			Y_value=0;
		}
		
		else if(u8count >= 16 || twoDarr[stu8_increment][u8count])
		{
			Y_value=1;
			X_value=u8count-16;
		}
		
		if(twoDarr[stu8_increment][u8count])
		{
			LCD_goto_xy(X_value,Y_value);
			LCD_send_char(twoDarr[stu8_increment][u8count++]);
		}
		else if((twoDarr[stu8_increment][u8count]== '\0') && u8count < 32)
			{
			while(u8count <= 32)
				{
					twoDarr[stu8_increment][u8count]=' ';
					u8count++;
				}
			}	else{u8count=0;}
	}
	else{stu8_increment=0;}
	u8_Init_finished=0;

	
	}
*/
		LCD_goto_xy(0,0);
		LCD_send_char('x');



}

void Push_Task(void){	
/*	
static uint8_t u8_Counter=0;
static uint8_t u8_Counter1=0;
	if (pushButtonGetStatus(BTN_0))
	{	
		u8_Counter++;
	}
	if (u8_Counter > 20)
	{
	stu8_increment++;
	u8_Counter=0;
	}
	
	if (pushButtonGetStatus(BTN_1))
	{
		u8_Counter1++;
		//stu8_increment++;
	}
	if (u8_Counter1 > 20)
	{
		stu8_increment--;
		u8_Counter1=0;
	}
	

	*/
DIO_Toggle(GPIOD,BIT4);
}
void Push_Task1(void)
{
u8_flag_push = pushButtonGetStatus(BTN_0);
if (u8_flag_push)
{
	u8_State_Machine=BUTTON_PRESSED;
}
}
void Push_Task2(void){
	DIO_Toggle(GPIOD,BIT2);
}

void Read_Time_Task(void)
{
	static uint8_t st_u16_indix=0;
	adc_read();
//u16_ADC_readings_Channel[st_u16_indix]
if (st_u16_indix <3)
{st_u16_indix++;}
else{st_u16_indix=0;}
Timing_arr[st_u16_indix]=(u16_ADC_readings_Channel[st_u16_indix])*3  ;


}

void relay0(void)
{
/*************************************************************************************/
counting_arr[0] += 1;
/*************************************************************************************/
/*************************************************************************************/
if (counting_arr[0]==Timing_arr[0])
{
	DIO_Toggle(GPIOD,BIT2);
	counting_arr[0]=0;
	relay1();
}
/**************************************************************************************/
	
	
}

void relay1(void)
{
	/*************************************************************************************/
	counting_arr[1] += 1;
	/*************************************************************************************/
	/*************************************************************************************/
	if (counting_arr[1]==Timing_arr[1])
	{DIO_Toggle(GPIOD,BIT2);
		counting_arr[1]=0;
		relay2();
	}
	/**************************************************************************************/
	
	
}

void relay2(void)
{
	/*************************************************************************************/
	counting_arr[2] += 1;
	/*************************************************************************************/
	/*************************************************************************************/
	if (counting_arr[2]==Timing_arr[2])
	{DIO_Toggle(GPIOD,BIT4);
		counting_arr[2]=0;
		relay0();
	}
	/**************************************************************************************/
	
	
}

void update_timing(void)
{
/*
SOS_Create_Task(Push_Task,1,3,Timing_arr[0]);
SOS_Create_Task(Push_Task1,1,4,Timing_arr[1]);
SOS_Create_Task(Push_Task2,1,5,Timing_arr[2]);
*//*
SOS_Create_Task(Push_Task,1,3,10);
SOS_Create_Task(Push_Task1,1,4,20);
SOS_Create_Task(Push_Task2,1,5,30);
*/

/*************************************************************************************/
if (u8_State_Machine == BUTTON_PRESSED || u8_State_Machine == RELAY0_COUNTING)
{
	DIO_Write(GPIOD,BIT2,HIGH);
	counting_arr[0] += 1;
	
	u8_State_Machine=RELAY0_COUNTING;
}
	    
/*************************************************************************************/
   if (u8_State_Machine==RELAY0_ACTION_DONE)// || u8_State_Machine == RELAY1_COUNTING)
   {
	DIO_Write(GPIOD,BIT3,HIGH);   
	    counting_arr[1] += 1;
	//	u8_State_Machine=RELAY1_COUNTING;
   }
   
/*************************************************************************************/
if (u8_State_Machine == RELAY1_ACTION_DONE )//|| u8_State_Machine == RELAY2_COUNTING)
{
	DIO_Write(GPIOD,BIT4,HIGH);
     counting_arr[2] += 1;
//	 u8_State_Machine=RELAY2_COUNTING;
}

	
/*************************************************************************************/
if (counting_arr[0]==Timing_arr[0])
{
	DIO_Write(GPIOD,BIT2,LOW);
	UartTransmitPooling('A');
	UartTransmitPooling('D');
	UartTransmitPooling('C');
	UartTransmitPooling('0');
	UartTransmitPooling('=');
	uart_transmit_u16(Timing_arr[0]);
	UartTransmitPooling('A');
	UartTransmitPooling('D');
	UartTransmitPooling('C');
	UartTransmitPooling('0');
	UartTransmitPooling('=');
	uart_transmit_u16(counting_arr[0]);
	UartTransmitPooling('\n');
counting_arr[0]=0;
u8_State_Machine=RELAY0_ACTION_DONE;
}
/**************************************************************************************/
if (counting_arr[1]==Timing_arr[1] && u8_State_Machine==RELAY0_ACTION_DONE)
{
	DIO_Write(GPIOD,BIT2,LOW);
DIO_Toggle(GPIOD,BIT3);
UartTransmitPooling(' ');
	UartTransmitPooling('A');
	UartTransmitPooling('D');
	UartTransmitPooling('C');
	UartTransmitPooling('1');
	UartTransmitPooling('=');
	uart_transmit_u16(Timing_arr[1]);
	UartTransmitPooling('A');
	UartTransmitPooling('D');
	UartTransmitPooling('C');
	UartTransmitPooling('1');
	UartTransmitPooling('=');
	uart_transmit_u16(counting_arr[1]);
	UartTransmitPooling('\n');
counting_arr[1]=0;
u8_State_Machine=RELAY1_ACTION_DONE;
}
/**************************************************************************************/
if (counting_arr[2]==Timing_arr[2]&& u8_State_Machine==RELAY1_ACTION_DONE)
{
	DIO_Write(GPIOD,BIT3,LOW);
DIO_Toggle(GPIOD,BIT4);

	UartTransmitPooling(' ');
	UartTransmitPooling('A');
	UartTransmitPooling('D');
	UartTransmitPooling('C');
	UartTransmitPooling('2');
	UartTransmitPooling('=');
	uart_transmit_u16(Timing_arr[2]);
	UartTransmitPooling('A');
	UartTransmitPooling('D');
	UartTransmitPooling('C');
	UartTransmitPooling('2');
	UartTransmitPooling('=');
	uart_transmit_u16(counting_arr[2]);
	UartTransmitPooling('\n');
	counting_arr[2]=0;
u8_State_Machine=RELAY2_ACTION_DONE;
}
if (u8_State_Machine == RELAY2_ACTION_DONE)
{
	u8_State_Machine=NO_ACTION;
}
/***************************************************************************************/
	//timing_array[arr_of_ptr]();

}


void uart_send_sos(void)
{
	
	
	
	
}
