/*
 * i2c.h
 *
 * Created: 01/01/2021 07:51:19 م
 *  Author: mo
 */ 


#ifndef I2C_H_
#define I2C_H_

#define MASTER_TRANSMITER 0
#define MASTER_RECIEVER   1
#define SLAVE_TRANSMITER  2
#define SLAVE_RECIEVER    3


void i2c_intialization(I2c_Config_type* i2c_config);


void Status(void);


void switch_Mode(uint8_t Mode );


void Transmit_data_eightbits(uint8_t data);


void Transmit_data_32_bits(uint32_t data);


void Transmit_arr(uint8_t* Ptr_to_arr);


void Recieve_data(uint8_t* data);


#endif /* I2C_H_ */