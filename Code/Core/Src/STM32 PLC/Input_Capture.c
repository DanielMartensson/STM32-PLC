/*
 * Input_Capture.c
 *
 *  Created on: Aug 7, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

#define LENGTH_ARRAY 100
static uint8_t data_index_for_tim15_channel_2 = 0;
static uint16_t input_capture0[LENGTH_ARRAY] = {0};
static uint16_t input_capture1[LENGTH_ARRAY] = {0};
static uint16_t input_capture2[LENGTH_ARRAY] = {0};
static uint16_t input_capture3[LENGTH_ARRAY] = {0};
static TIM_HandleTypeDef* handler_tim17;
static TIM_HandleTypeDef* handler_tim16;
static TIM_HandleTypeDef* handler_tim15;

void STM32_PLC_Input_Capture(TIM_HandleTypeDef* htim17, TIM_HandleTypeDef* htim16, TIM_HandleTypeDef* htim15) {
	/*
	 * Input capture for measuring frequency
	 * For TIM17 and TIM16 and TIM15
	 * Timer clock: 48 Mhz
	 * Prescaler: 4799
	 * Counter: 65535 (0xffff)
	 * Update frequency: 0.1526 Hz (1/0.1526 = 6.5535 seconds)
	 * Example: For every second, it will count 10000
	 * Lowest frequency measurement: 1/(0xFFFF*0.0001) = 0.1526 Hz
	 * Highest frequency measurement: 1/(1*0.0001) = 10000 Hz
	 */
	if(HAL_TIM_IC_Start_IT(htim15, TIM_CHANNEL_2) != HAL_OK)
		Error_Handler();
	if(HAL_TIM_IC_Start_DMA(htim15, TIM_CHANNEL_1, (uint32_t*)input_capture2, LENGTH_ARRAY) != HAL_OK)
		Error_Handler();
	if(HAL_TIM_IC_Start_DMA(htim16, TIM_CHANNEL_1, (uint32_t*)input_capture1, LENGTH_ARRAY) != HAL_OK)
		Error_Handler();
	if(HAL_TIM_IC_Start_DMA(htim17, TIM_CHANNEL_1, (uint32_t*)input_capture0, LENGTH_ARRAY) != HAL_OK)
		Error_Handler();

	/* Save */
	handler_tim17 = htim17;
	handler_tim16 = htim16;
	handler_tim15 = htim15;
}

static uint16_t compute_period(uint16_t input_capture[], uint8_t left) {
	/* Find the index - i0 and i1 can never be larger than LENGTH_ARRAY and lower than 0 */
	uint8_t a = 2*LENGTH_ARRAY - left;
	uint8_t i0 = (a - 2) % LENGTH_ARRAY;
	uint8_t i1 = (a - 1) % LENGTH_ARRAY;

	/* Check absolute value */
	if(input_capture[i1] > input_capture[i0])
		return input_capture[i1] - input_capture[i0];
	else if(input_capture[i1] < input_capture[i0])
		return input_capture[i1] + 0xFFFF - input_capture[i0];
	else
		return 1;
}


uint16_t STM32_PLC_Input_Capture_Get_Raw(uint8_t i){
	switch(i){
	case 0:
		return compute_period(input_capture0, handler_tim17->hdma[TIM_DMA_ID_CC1]->Instance->CNDTR);
	case 1:
		return compute_period(input_capture1, handler_tim16->hdma[TIM_DMA_ID_CC1]->Instance->CNDTR);
	case 2:
		return compute_period(input_capture2, handler_tim15->hdma[TIM_DMA_ID_CC1]->Instance->CNDTR);
	case 3:
		return compute_period(input_capture3, LENGTH_ARRAY - data_index_for_tim15_channel_2);
	default:
		return 0;
	}
}

float STM32_PLC_Input_Capture_Get_Calibrated(uint8_t i){
	return 1.0f/((float)STM32_PLC_Input_Capture_Get_Raw(i)*0.0001f); /* Converting to Hz */
}


void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	/* This is here because channel 2 does not have DMA */
	if(htim->Instance == TIM15){
		if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2){
			if(data_index_for_tim15_channel_2 >= LENGTH_ARRAY)
				data_index_for_tim15_channel_2 = 0;
			input_capture3[data_index_for_tim15_channel_2++] = htim->Instance->CNT;
		}
	}
}
