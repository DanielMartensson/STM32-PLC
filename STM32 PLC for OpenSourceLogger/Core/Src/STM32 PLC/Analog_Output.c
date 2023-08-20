/*
 * Analog_Output.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

static DAC_HandleTypeDef* hanalog1;
static DAC_HandleTypeDef* hanalog2;

void STM32_PLC_Analog_Output(DAC_HandleTypeDef* hdac1, DAC_HandleTypeDef* hdac2, TIM_HandleTypeDef* htim6) {
	/*
	 * For TIM6
	 * Timer clock: 48 Mhz
	 * Prescaler: 99
	 * Counter: 48000 (0xbb80)
	 * Update frequency: 10 Hz
	 */
	HAL_TIM_Base_Start(htim6);
	if(HAL_DAC_Start(hdac1, DAC1_CHANNEL_1) != HAL_OK)
		Error_Handler();
	if(HAL_DAC_Start(hdac1, DAC1_CHANNEL_2) != HAL_OK)
		Error_Handler();
	if(HAL_DAC_Start(hdac2, DAC2_CHANNEL_1) != HAL_OK)
		Error_Handler();
	hanalog1 = hdac1;
	hanalog2 = hdac2;

	/* Reset */
	STM32_PLC_Analog_Output_Reset();
}

void STM32_PLC_Analog_Output_Set(uint8_t i, uint16_t output) {
	/* Safety */
	if(output > 4095)
		output = 4095;
	switch(i){
	case 0:
		HAL_DAC_SetValue(hanalog1, DAC1_CHANNEL_1, DAC_ALIGN_12B_R, output);
		break;
	case 1:
		HAL_DAC_SetValue(hanalog1, DAC1_CHANNEL_2, DAC_ALIGN_12B_R, output);
		break;
	case 2:
		HAL_DAC_SetValue(hanalog2, DAC2_CHANNEL_1, DAC_ALIGN_12B_R, output);
		break;
	}
}

void STM32_PLC_Analog_Output_Reset() {
	for(uint8_t i = 0; i < 3; i++)
		STM32_PLC_Analog_Output_Set(i, 0);
}

uint16_t STM32_PLC_Analog_Output_Get(uint8_t i) {
	switch(i){
	case 0:
		return HAL_DAC_GetValue(hanalog1, DAC1_CHANNEL_1);
	case 1:
		return HAL_DAC_GetValue(hanalog1, DAC1_CHANNEL_2);
	case 2:
		return HAL_DAC_GetValue(hanalog2, DAC1_CHANNEL_2);
	default:
		return 0;
	}
}
