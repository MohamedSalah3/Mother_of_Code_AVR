/*
 * Tasks.h
 *
 * Created: 30/10/2020 02:21:32 ص
 *  Author: mo
 */ 


#ifndef TASKS_H_
#define TASKS_H_
#include "../../MCAL/ADC/ADC.h"

#include "../../MCAL/PushButtons/pushButton.h"
#include "../../ECUAL/LCD/LCD.h"

void Read_Time_Task(void);
void Push_Task(void);
void Display_Task(void);


#endif /* TASKS_H_ */