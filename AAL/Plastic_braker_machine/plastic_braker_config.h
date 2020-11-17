/*
 * plastic_braker_config.h
 *
 * Created: 10/11/2020 04:59:13 م
 *  Author: mo
 */ 


#ifndef PLASTIC_BRAKER_CONFIG_H_
#define PLASTIC_BRAKER_CONFIG_H_
#include "../../Infrastructure/Interrupts Manger/Interrupts.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/PushButtons/pushButton.h"

extern DIO_Cfg_s Dio_D_magnetic;
extern DIO_Cfg_s Dio_B_On_Off;
extern DIO_Cfg_s Dio_D_ALARM;
extern DIO_Cfg_s Dio_B_MOTOR;

#endif /* PLASTIC_BRAKER_CONFIG_H_ */