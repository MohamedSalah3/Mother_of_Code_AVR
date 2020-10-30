/*
 * Tasks.c
 *
 * Created: 30/10/2020 02:21:21 ص
 *  Author: mo
 */ 
#include "Tasks.h"
 uint8_t u8_Init_finished=0;

static uint8_t stu8_increment=0;
void Display_Task(void)
{	static uint8_t u8count=0;
	static uint8_t flag_Null=0;
	static uint8_t twoDarr[][32]={"1.Is 5 + 2 = 7 ?  ","2.IS Earth Flat ?  ",
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
		{while(u8count <= 32){
			twoDarr[stu8_increment][u8count]=' ';
			u8count++;
		}
	}else{u8count=0;}
}else{stu8_increment=0;}
u8_Init_finished=0;

	}

}
void Push_Task(void){	
	
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
	

	
}
void Read_Time_Task(void){
	
		
}