/*
 * i22c_config.c
 *
 * Created: 01/01/2021 07:50:54 م
 *  Author: mo
 */ 
#include "i2c_config.h"

/*****************************************************************************************/
/*                      i2c configuration structures                                     */
/*****************************************************************************************/
I2c_Config_type I2c_Master_T = {
MASTER 
,
TRANSMIT_ONLY 
,
SLA_MASTER 
,
SEVEN_BITS_SLA
,
INTERRUPT
,
100//khz
,
GENERAL_CALL_ENABLE
}

/*****************************************************************************************/
I2c_Config_type I2c_Master_R = {
MASTER 
,
RECIEVE_ONLY 
,
SLA_MASTER 
,
SEVEN_BITS_SLA
,
INTERRUPT
,
100//khz
,
GENERAL_CALL_ENABLE
}

/*****************************************************************************************/
I2c_Config_type I2c_Slave_R = {
SLAVE
,
RECIEVE_ONLY 
,
0x25 
,
SEVEN_BITS_SLA
,
INTERRUPT
,
100//khz
,
GENERAL_CALL_ENABLE
}
/*****************************************************************************************/
I2c_Config_type I2c_Slave_T = {
SLAVE
,
TRANSMIT_ONLY 
,
0x35 
,
SEVEN_BITS_SLA
,
INTERRUPT
,
100//khz
,
GENERAL_CALL_ENABLE
}
/*****************************************************************************************/