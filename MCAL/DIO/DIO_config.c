/*
 * DIO_config.c
 *
 * Created: 17/02/2020 03:53:11 م
 *  Author: mo
 */ 

#include "DIO_config.h" 
DIO_Cfg_s Dio_configurationA= {
	GPIOA,
FULL_PORT,
	OUTPUT
};

DIO_Cfg_s Dio_configurationB= {
	GPIOB,
	FULL_PORT,
	OUTPUT
};

DIO_Cfg_s Dio_configurationC= {
	GPIOC,
	BIT4,
	INPUT
};

DIO_Cfg_s Dio_configurationD= {
	GPIOD,
	BIT4|BIT3|BIT2,
	OUTPUT
};
DIO_Cfg_s SPI_Slave_Config= {
	GPIOB,
	BIT4|BIT5|BIT7,
	OUTPUT
};
DIO_Cfg_s SPI_Slave_Config1=
{
GPIOB,
BIT6,
INPUT
};