/*
 * Mother_of_Code.c
 *
 * Created: 30/10/2020 02:47:30 ص
 *  Author: mo
 */ 
#include "SL/SOS/SOS.h"

int main(void)
{
	Uart_Init(Baud9600,OneStopBit,NoParity,EightBits,ASynchronous);
	LCD_init();
	DIO_init(&Dio_configurationB);
	DIO_init(&Dio_configurationC);
	DIO_init(&Dio_configurationD);
	SOS_Init(&TMU_Configuration);

	//SOS_Create_Task(LCD_init,1,0,50);
	SOS_Create_Task(Read_Time_Task,1,1,5);
	//SOS_Create_Task(Display_Task,1,2,10);
	SOS_Create_Task(update_timing,1,4,1);
	SOS_Create_Task(Push_Task1,1,3,2);
	while(1)
	{
	
	
		SOS_Run();
	}

}