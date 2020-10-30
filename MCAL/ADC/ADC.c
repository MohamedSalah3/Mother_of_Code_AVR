/*
 * ADC.c
 *
 * Created: 26/10/2020 04:13:09 م
 *  Author: mo
 */ 
#include "ADC.h"
static uint8_t arr_counter_of_ptr=0;
static ptr_to_Fun ADC_R[8]={ADC_Read0,ADC_Read1,ADC_Read2,ADC_Read3,ADC_Read4,ADC_Read5,ADC_Read6,ADC_Read7};
uint16_t u16_ADC_readings_Channel[8];
ERROR_STATUS ADC_INIT(ADC_Cfg_s *ADC_info)
{
	uint8_t ret_error=E_OK;
	
	ADMUX |= (ADC_info->u8_voltage_refrences) ;
	if ((ADC_info ->u8_Channel_Number) != ADC_MULTIPLE_CHANNELS)
	{
		ADMUX &= 0xf0;
		ADMUX |=(ADC_info ->u8_Channel_Number);
	}
	ADMUX |= (ADC_info->u8_ten_bit_arrangment);
	G_interrupt_Enable();
	ADCSRA |= (ADC_info ->u8_polling_interrupt);
	ADC_INT = ADC_read_int;
	ADCSRA |=(ADC_info->u8_Prescaler);
	ADCSRA |= 0x80;/*ADC ENABLE*/
	ADCSRA |= 0x40;//start conversion
	return ret_error;
}
void ADC_Read0(void)
{
	ADC_INIT(&ADC_Cnfiguration0);
	ADCSRA |= 0x40;
	while (!(READBIT(ADCSRA,ADIF)));
	u16_ADC_readings_Channel[0]  = (ADCL + (ADCH << 8));

}
void ADC_Read1(void){
	ADC_INIT(&ADC_Cnfiguration1);
	ADCSRA |= 0x40;
	while (!(READBIT(ADCSRA,ADIF)));
	u16_ADC_readings_Channel[1]  =(ADCL + (ADCH << 8));
}
void ADC_Read2(void){
	ADC_INIT(&ADC_Cnfiguration2);
	ADCSRA |= 0x40;
	while (!(READBIT(ADCSRA,ADIF)));
	u16_ADC_readings_Channel[2]  = (ADCL + (ADCH << 8));
}
void ADC_Read3(void)
{
ADC_INIT(&ADC_Cnfiguration3);
ADCSRA |= 0x40;
while (!(READBIT(ADCSRA,ADIF)));
u16_ADC_readings_Channel[3]  = (ADCL + (ADCH << 8));
}
void ADC_Read4(void)
{
	ADC_INIT(&ADC_Cnfiguration4);
	ADCSRA |= 0x40;
	while (!(READBIT(ADCSRA,ADIF)));
	u16_ADC_readings_Channel[4]  =(ADCL + (ADCH << 8));

}
void ADC_Read5(void)
{
ADC_INIT(&ADC_Cnfiguration5);
ADCSRA |= 0x40;
while (!(READBIT(ADCSRA,ADIF)));
u16_ADC_readings_Channel[5]  = (ADCL + (ADCH << 8));
}

void ADC_Read6(void)
{
	ADC_INIT(&ADC_Cnfiguration6);
	ADCSRA |= 0x40;
	while (!(READBIT(ADCSRA,ADIF)));
	u16_ADC_readings_Channel[6]  = (ADCL + (ADCH << 8));
}
void ADC_Read7(void)
{
ADC_INIT(&ADC_Cnfiguration7);
ADCSRA |= 0x40;
while (!(READBIT(ADCSRA,ADIF)));
u16_ADC_readings_Channel[7]  = (ADCL + (ADCH << 8));
}
void adc_read(void){
	if (arr_counter_of_ptr < 8)
	{
		ADC_R[arr_counter_of_ptr]();
			arr_counter_of_ptr++;
	}else{arr_counter_of_ptr=0;}
}
void ADC_read_int(void)
{


}