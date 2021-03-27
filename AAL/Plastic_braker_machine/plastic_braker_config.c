/*
 * plastic_braker_config.c
 *
 * Created: 10/11/2020 04:58:25 م
 *  Author: mo
 */ 
#include "plastic_braker_config.h"


DIO_Cfg_s Dio_D_magnetic =
{
	GPIOD,
	BIT2|BIT3,
	INPUT
};
DIO_Cfg_s Dio_B_On_Off =
{
	GPIOB,
	BIT1|BIT2,
	INPUT	
};
	
DIO_Cfg_s Dio_D_ALARM =
{
	GPIOD,
	BIT7,
	OUTPUT		
};
	
	
DIO_Cfg_s Dio_B_MOTOR =
{
		GPIOB,
		BIT4|BIT5|BIT6|BIT7,
		OUTPUT
};
	