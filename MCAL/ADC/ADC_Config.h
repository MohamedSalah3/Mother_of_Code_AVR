/*
 * ADC_Config.h
 *
 * Created: 03/10/2020 01:21:57 م
 *  Author: mo
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#include "DIO.h"

typedef struct ADC_Cfg_s{
	uint8_t u8_Channel_Number;
	uint8_t u8_Prescaler;
	uint8_t u8_voltage_refrences;
	uint8_t u8_ten_bit_arrangment;
	uint8_t u8_polling_interrupt;
}ADC_Cfg_s;


/*00000 ADC0
00001 ADC1
00010 ADC2
00011 ADC3 N/A
00100 ADC4
00101 ADC5
00110 ADC6
00111 ADC7 0x*/
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
#define ADC_MULTIPLE_CHANNELS 0xFF
/***********************************************/
#define AREFRENCE  0x00
#define AVCC       0x40
#define INTERNAL_VREF 0xC0
/***********************************************/
#define RIGHT_JUSTFIED 0x20
#define LEFT_JUSTFIED 0x00
#define PRESCALER2      1
#define PRESCALER4      2
#define PRESCALER8      3
#define PRESCALER16     4
#define PRESCALER32	    5
#define PRESCALER64		6
#define PRESCALER128    7
/*********************************************/
#define ADC_INTERRUPT 0x08
#define ADC_POLLING   0x00
extern ADC_Cfg_s ADC_Cnfiguration0;
extern ADC_Cfg_s ADC_Cnfiguration1;
extern ADC_Cfg_s ADC_Cnfiguration2;
extern ADC_Cfg_s ADC_Cnfiguration3;
extern ADC_Cfg_s ADC_Cnfiguration4;
extern ADC_Cfg_s ADC_Cnfiguration5;
extern ADC_Cfg_s ADC_Cnfiguration6;
extern ADC_Cfg_s ADC_Cnfiguration7;

#endif /* ADC_CONFIG_H_ */