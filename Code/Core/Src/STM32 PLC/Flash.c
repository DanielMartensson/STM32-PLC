/*
 * Flash.c
 *
 *  Created on: 13 feb. 2022
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

#define ADDR_FLASH_PAGE_127   ((uint32_t)0x0803F800) /* Base address of Page 127, 2 Kbytes */
#define FLASH_LENGTH_DATA 92
static void read_flash(uint16_t data[], uint8_t length);
static void write_flash(uint16_t value, uint8_t overwrite_index);

union {
	float float_number;
	uint8_t bytes[4];
} float_converter;


void STM32_PLC_Flash_Set_ADC_Gain_For_Configuration_Index_0(uint8_t sdadc, uint8_t gain){
	switch(sdadc){
	case 1:
		write_flash(gain, 0);
		break;
	case 2:
		write_flash(gain, 3);
		break;
	case 3:
		write_flash(gain, 6);
		break;
	}
}

void STM32_PLC_Flash_Set_ADC_Gain_For_Configuration_Index_1(uint8_t sdadc, uint8_t gain){
	switch(sdadc){
	case 1:
		write_flash(gain, 1);
		break;
	case 2:
		write_flash(gain, 4);
		break;
	case 3:
		write_flash(gain, 7);
		break;
	}
}

void STM32_PLC_Flash_Set_ADC_Gain_For_Configuration_Index_2(uint8_t sdadc, uint8_t gain){
	switch(sdadc){
	case 1:
		write_flash(gain, 2);
		break;
	case 2:
		write_flash(gain, 5);
		break;
	case 3:
		write_flash(gain, 8);
		break;
	}
}

void STM32_PLC_Flash_Set_PWM_Prescaler_For_PWM_0_3(uint16_t prescaler){
	write_flash(prescaler, 9);
}

void STM32_PLC_Flash_Set_PWM_Prescaler_For_PWM_4_7(uint16_t prescaler){
	write_flash(prescaler, 10);
}

void STM32_PLC_Flash_Set_Alarm_Enable(bool alarm_A_enabled, bool alarm_B_enabled){
	uint16_t enables = (alarm_A_enabled << 1) | alarm_B_enabled;
	write_flash(enables, 11);
}

void STM32_PLC_Flash_Set_LCD_Calibration(float Scale_X, float Scale_Y, float Bias_X, float Bias_Y){
	float_converter.float_number = Scale_X;
	write_flash((float_converter.bytes[0] << 8) | float_converter.bytes[1], 12);
	write_flash((float_converter.bytes[2] << 8) | float_converter.bytes[3], 13);

	float_converter.float_number = Scale_Y;
	write_flash((float_converter.bytes[0] << 8) | float_converter.bytes[1], 14);
	write_flash((float_converter.bytes[2] << 8) | float_converter.bytes[3], 15);

	float_converter.float_number = Bias_X;
	write_flash((float_converter.bytes[0] << 8) | float_converter.bytes[1], 16);
	write_flash((float_converter.bytes[2] << 8) | float_converter.bytes[3], 17);

	float_converter.float_number = Bias_Y;
	write_flash((float_converter.bytes[0] << 8) | float_converter.bytes[1], 18);
	write_flash((float_converter.bytes[2] << 8) | float_converter.bytes[3], 19);
}

void STM32_PLC_Flash_Set_J1939_This_ECU_Address(uint8_t this_ECU_address){
	write_flash(this_ECU_address, 20);
}

void STM32_PLC_Flash_Set_Analog_Input_Calibration(uint8_t input_index, float scalar, float bias){
	/* Write the scalar value */
	float_converter.float_number = scalar;
	write_flash((float_converter.bytes[0] << 8) | float_converter.bytes[1], 21 + 2*input_index);
	write_flash((float_converter.bytes[2] << 8) | float_converter.bytes[3], 22 + 2*input_index);

	/* Write the bias value */
	float_converter.float_number = bias;
	write_flash((float_converter.bytes[0] << 8) | float_converter.bytes[1], 55 + 2*input_index);
	write_flash((float_converter.bytes[2] << 8) | float_converter.bytes[3], 56 + 2*input_index);
}

void STM32_PLC_Flash_Set_Encoder_Pulses(uint8_t pulses_index, uint16_t pulses){
	write_flash(pulses, 89 + pulses_index);
}

void STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_1(uint8_t *gain_for_configuration_index_0, uint8_t *gain_for_configuration_index_1, uint8_t *gain_for_configuration_index_2){
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);
	*gain_for_configuration_index_0 = data[0] <= 0x7 ? data[0] : 1;
	*gain_for_configuration_index_1 = data[1] <= 0x7 ? data[1] : 1;
	*gain_for_configuration_index_2 = data[2] <= 0x7 ? data[2] : 1;
}

void STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_2(uint8_t *gain_for_configuration_index_0, uint8_t *gain_for_configuration_index_1, uint8_t *gain_for_configuration_index_2){
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);
	*gain_for_configuration_index_0 = data[3] <= 0x7 ? data[3] : 1;
	*gain_for_configuration_index_1 = data[4] <= 0x7 ? data[4] : 1;
	*gain_for_configuration_index_2 = data[5] <= 0x7 ? data[5] : 1;
}

void STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_3(uint8_t *gain_for_configuration_index_0, uint8_t *gain_for_configuration_index_1, uint8_t *gain_for_configuration_index_2){
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);
	*gain_for_configuration_index_0 = data[6] <= 0x7 ? data[6] : 1;
	*gain_for_configuration_index_1 = data[7] <= 0x7 ? data[7] : 1;
	*gain_for_configuration_index_2 = data[8] <= 0x7 ? data[8] : 1;
}

void STM32_PLC_Flash_Get_PWM_Prescalers(uint16_t *prescaler_for_PWM_0_3, uint16_t *prescaler_for_PWM_4_7){
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);
	*prescaler_for_PWM_0_3 = data[9] <= 0xFFFF ? data[9] : 0xFFFF;
	*prescaler_for_PWM_4_7 = data[10] <= 0xFFFF ? data[10] : 0xFFFF;
}

void STM32_PLC_Flash_Get_Alarm_Enables(bool *alarm_A_enabled, bool *alarm_B_enabled){
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);
	uint8_t enables = data[11] <= 0x3 ? data[11] : 0x0;
	*alarm_A_enabled = enables >> 1;
	*alarm_B_enabled = enables & 0b1;
}

void STM32_PLC_Flash_Get_LCD_Calibration(float *Scale_X, float *Scale_Y, float *Bias_X, float *Bias_Y){
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);
	float_converter.bytes[0] = data[12] >> 8;
	float_converter.bytes[1] = data[12];
	float_converter.bytes[2] = data[13] >> 8;
	float_converter.bytes[3] = data[13];
	*Scale_X = float_converter.float_number;

	float_converter.bytes[0] = data[14] >> 8;
	float_converter.bytes[1] = data[14];
	float_converter.bytes[2] = data[15] >> 8;
	float_converter.bytes[3] = data[15];
	*Scale_Y = float_converter.float_number;

	float_converter.bytes[0] = data[16] >> 8;
	float_converter.bytes[1] = data[16];
	float_converter.bytes[2] = data[17] >> 8;
	float_converter.bytes[3] = data[17];
	*Bias_X = float_converter.float_number;

	float_converter.bytes[0] = data[18] >> 8;
	float_converter.bytes[1] = data[18];
	float_converter.bytes[2] = data[19] >> 8;
	float_converter.bytes[3] = data[19];
	*Bias_Y = float_converter.float_number;
}

void STM32_PLC_Flash_Get_J1939_This_ECU_Address(uint8_t *this_ECU_address){
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);
	*this_ECU_address = data[20] <= 0xFF ? data[20] : 0x0;
}

void STM32_PLC_Flash_Get_Analog_Input_Calibration(uint8_t input_index, float *scalar, float *bias){
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);

	/* Get scalar */
	float_converter.bytes[0] = data[21+2*input_index] >> 8;
	float_converter.bytes[1] = data[21+2*input_index];
	float_converter.bytes[2] = data[22+2*input_index] >> 8;
	float_converter.bytes[3] = data[22+2*input_index];
	*scalar = float_converter.float_number;

	/* Get bias */
	float_converter.bytes[0] = data[55+2*input_index] >> 8;
	float_converter.bytes[1] = data[55+2*input_index];
	float_converter.bytes[2] = data[56+2*input_index] >> 8;
	float_converter.bytes[3] = data[56+2*input_index];
	*bias = float_converter.float_number;
}

void STM32_PLC_Flash_Get_Encoder_Pulses(uint8_t pulses_index, uint16_t *pulses){
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);
	*pulses = data[89 + pulses_index];
}


static void read_flash(uint16_t data[], uint8_t length){
	uint32_t address = ADDR_FLASH_PAGE_127;
	for(uint8_t i = 0; i < length; i++){
		data[i] = *(__IO uint16_t*)address;
		address += 2;
	}
}

static void write_flash(uint16_t value, uint8_t overwrite_index){

	/* Create the data */
	uint16_t data[FLASH_LENGTH_DATA];
	read_flash(data, FLASH_LENGTH_DATA);

	/* Overwrite */
	data[overwrite_index] = value;

	/* Unlock */
	HAL_FLASH_Unlock();

	/* Erase */
	FLASH_EraseInitTypeDef eraseInitStruct;
	eraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
	eraseInitStruct.PageAddress = ADDR_FLASH_PAGE_127;
	eraseInitStruct.NbPages     = 1;
	uint32_t PageError = 0;
	if (HAL_FLASHEx_Erase(&eraseInitStruct, &PageError) != HAL_OK)
		Error_Handler();

	/* Write data */
	uint32_t index = 0;
	for(uint8_t i = 0; i < FLASH_LENGTH_DATA; i++){
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, ADDR_FLASH_PAGE_127 + index, data[i]) != HAL_OK)
			Error_Handler();
		index += 2;
	}

	/* Lock */
	HAL_FLASH_Lock();
}
