/*
 * i2c.c
 *
 * Created: 01/01/2021 07:50:38 م
 *  Author: mo
 */ 
/*
first 7 bytes Master transmit status
second 7 bytes Master recieve status
third 7 bytes Slave transmit status 
fourth seven bytes slave recieve status
*/
#include "i2c.h"
static uint8_t Status_ARR[7];
static uint8_t Mode;
void i2c_intialization(I2c_Config_type* i2c_config)
{
	
	
	
	
}

void Status(void)
{




}
void switch_Mode(uint8_t Mode )
{



} 
void Transmit_data_eightbits(uint8_t data)
{




}
void Transmit_data_32_bits(uint32_t data)
{




}
void Transmit_arr(uint8_t* Ptr_to_arr)
{





}



void Recieve_data(uint8_t* data)
{




}