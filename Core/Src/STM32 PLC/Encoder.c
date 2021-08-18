/*
 * Encoder.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

static TIM_HandleTypeDef* tim4_handle;
static TIM_HandleTypeDef* tim19_handle;
static uint16_t encoder_pulses_per_revolution[2] = {0};
static int16_t encoder[2] = {0};

void STM32_PLC_Start_Encoder(TIM_HandleTypeDef* htim4, TIM_HandleTypeDef* htim19) {
	/* Encoder - Prescaler does not effect encoder */
	if(HAL_TIM_Encoder_Start(htim4, TIM_CHANNEL_ALL) != HAL_OK)
		Error_Handler();
	if(HAL_TIM_Encoder_Start(htim19, TIM_CHANNEL_ALL) != HAL_OK)
		Error_Handler();

	/* Save */
	tim4_handle = htim4;
	tim19_handle = htim19;
}

float STM32_PLC_Encoder_Get(uint8_t i) {
	/* Safety */
	if(encoder_pulses_per_revolution[i] == 0)
		encoder_pulses_per_revolution[i] = 1;
	float pulses = (float)encoder_pulses_per_revolution[i];
	return ((float)STM32_PLC_Encoder_Get_Raw(i))/pulses;
}

int16_t STM32_PLC_Encoder_Get_Raw(uint8_t i) {
	if(i == 0)
		encoder[i] += __HAL_TIM_GET_COUNTER(tim4_handle);
	else
		encoder[i] += __HAL_TIM_GET_COUNTER(tim19_handle);
	return encoder[i];
}

void STM32_PLC_Encoder_Set_Pulses_Per_Revolutions(uint8_t i, uint16_t pulses_per_revolution) {
	encoder_pulses_per_revolution[i] = pulses_per_revolution;
}
