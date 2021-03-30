/*
 * i2c_config.h
 *
 * Created: 01/01/2021 07:51:32 م
 *  Author: mo
 */ 
#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

#define MASTER      0
#define SLAVE       1

#define RECIEVE_ONLY 0
#define TRANSMIT_ONLY 1
#define TRANSMIT_AND_RECIEVE 2

#define POOLING     0
#define INTERRUPT   1

#define GENERAL_CALL_DISABLE 0
#define GENERAL_CALL_ENABLE  1

#define SEVEN_BITS_SLA 0
#define TEN_BITS_SLA 1

#define SLA_MASTER 0
typedef struct I2c_Config_type{
uint8_t device_mode;
uint8_t Transmit_Recieve;
uint8_t Slave_address;
uint8_t SLAve_Address_BITS;
uint8_t Pooling_interrupt;
uint8_t clock_rate;  //put your ferq in hz
uint8_t General_call;
}I2c_Config_type;

extern I2c_Config_type I2c_Master_T;
extern I2c_Config_type I2c_Master_R;
extern I2c_Config_type I2c_Slave_T;
extern I2c_Config_type I2c_Slave_R;

#endif /* I2C_CONFIG_H_ */