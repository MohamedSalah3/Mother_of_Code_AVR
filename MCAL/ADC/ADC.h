/*
 * ADC.h
 *
 * Created: 03/10/2020 01:21:38 م
 *  Author: mo
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_Config.h"



ERROR_STATUS ADC_INIT(ADC_Cfg_s *ADC_info);
void ADC_Read0(void);
void ADC_Read1(void);
void ADC_Read2(void);
void ADC_Read3(void);
void ADC_Read4(void);
void ADC_Read5(void);
void ADC_Read6(void);
void ADC_Read7(void);
void adc_read(void);
void ADC_read_int(void);

#endif /* ADC_H_ */