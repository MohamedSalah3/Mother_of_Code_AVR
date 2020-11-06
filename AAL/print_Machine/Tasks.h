/*
 * Tasks.h
 *
 * Created: 30/10/2020 02:21:32 ص
 *  Author: mo
 */ 


#ifndef TASKS_H_
#define TASKS_H_
#include "../../MCAL/ADC/ADC.h"
#include "../../Infrastructure/Interrupts Manger/Interrupts.h"
#include "../../MCAL/PushButtons/pushButton.h"
#include "../../ECUAL/LCD/LCD.h"
#include "../../MCAL/uart_Send.h"
void update_timing(void);
void Read_Time_Task(void);
void Push_Task(void);
void Display_Task(void);
void Push_Task1(void);
void Push_Task2(void);
void relay0(void);
void relay1(void);
void relay2(void);
void uart_send_sos(void);
/******************************************************************************************/
/*								State Machine											  */
/******************************************************************************************/
#define NO_ACTION                     0
#define RELAY0_COUNTING               1
#define RELAY1_COUNTING	              2
#define RELAY2_COUNTING               3 
#define RELAY0_ACTION_DONE            4 
#define RELAY1_ACTION_DONE            5
#define RELAY2_ACTION_DONE            6
#define BUTTON_PRESSED 				  7

#endif /* TASKS_H_ */