/*
 * Encoder.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

static TIM_HandleTypeDef* tim4_handle;
static TIM_HandleTypeDef* tim19_handle;
static TIM_HandleTypeDef* tim3_handle;
static uint16_t pulses_list[3] = {1};

void STM32_PLC_Encoder(TIM_HandleTypeDef* htim4, TIM_HandleTypeDef* htim19, TIM_HandleTypeDef* htim3) {
	/* Encoder - Prescaler does not effect encoder */
	if(HAL_TIM_Encoder_Start(htim4, TIM_CHANNEL_ALL) != HAL_OK)
		Error_Handler();
	if(HAL_TIM_Encoder_Start(htim19, TIM_CHANNEL_ALL) != HAL_OK)
		Error_Handler();
	if(HAL_TIM_Encoder_Start(htim3, TIM_CHANNEL_ALL) != HAL_OK)
			Error_Handler();

	/* Save */
	tim4_handle = htim4;
	tim19_handle = htim19;
	tim3_handle = htim3;

	/* Get calibration */
	uint16_t pulses;
	for(uint8_t i = 0; i < 3; i++){
		STM32_PLC_Flash_Get_Encoder_Pulses(i, &pulses);
		STM32_PLC_Encoder_Set_Calibration(i, pulses, false);
	}
}


int16_t STM32_PLC_Encoder_Get_Raw(uint8_t i) {
	switch(i){
	case 0:
		return __HAL_TIM_GET_COUNTER(tim4_handle);
	case 1:
		return __HAL_TIM_GET_COUNTER(tim19_handle);
	case 2:
		return __HAL_TIM_GET_COUNTER(tim3_handle);
	default:
		return 0;
	}
}

float STM32_PLC_Encoder_Get_Calibrated(uint8_t i){
	return (float)(STM32_PLC_Encoder_Get_Raw(i))/((float)pulses_list[i]);
}

void STM32_PLC_Encoder_Set_Calibration(uint8_t pulses_index, uint16_t pulses, bool save_to_flash){
	pulses_list[pulses_index] = pulses;
	if(save_to_flash)
		STM32_PLC_Flash_Set_Encoder_Pulses(pulses_index, pulses);
}

void STM32_PLC_Encoder_Get_Calibration(uint8_t pulses_index, uint16_t *pulses){
	STM32_PLC_Flash_Get_Encoder_Pulses(pulses_index, pulses);
}
