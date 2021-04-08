/*keypad_config.h*/


typedef struct KeyPad_matrix_str{
	uint8_t u8_Channel_Number;
	uint8_t u8_Prescaler;
	uint8_t u8_voltage_refrences;
	uint8_t u8_ten_bit_arrangment;
	uint8_t u8_polling_interrupt;
}KeyPad_matrix_str;





extern KeyPad_matrix_str Keypad;
