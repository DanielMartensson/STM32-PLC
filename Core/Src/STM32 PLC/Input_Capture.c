/*
 * Input_Capture.c
 *
 *  Created on: Aug 7, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

volatile static uint16_t input_capture0[2] = {0};
volatile static uint16_t input_capture1[2] = {0};

void STM32_PLC_Start_Input_Capture(TIM_HandleTypeDef* htim17, TIM_HandleTypeDef* htim16) {
	/*
	 * Input capture for measuring frequency
	 * For TIM17 and TIM16
	 * Timer clock: 48 Mhz
	 * Prescaler: 4799
	 * Counter: 65535 (0xffff)
	 * Update frequency: 0.1526 Hz (1/0.1526 = 6.5535 seconds)
	 * Example: For every second, it will count 10000
	 * Lowest frequency measurement: 1/(0xFFFF*0.0001) = 0.1526 Hz
	 * Highest frequency measurement: 1/(1*0.0001) = 10000 Hz
	 */
	if(HAL_TIM_IC_Start_DMA(htim16, TIM_CHANNEL_1, (uint32_t*)input_capture1, 2) != HAL_OK)
		Error_Handler();
	if(HAL_TIM_IC_Start_DMA(htim17, TIM_CHANNEL_1, (uint32_t*)input_capture0, 2) != HAL_OK)
		Error_Handler();
}

static float compute_frequency(uint16_t input_capture[]) {
	/*
	 * Typical worst case scenarios:
	 * T1: 0xFFFF - T0: 0x0
	 * T1: 0x0    - T0: 0xFFFF
	 * T1: 0x7FFF - T0: 0x7FFF
	 * T1: 0x0	  -	T0: 0x0
	 */
	uint16_t difference;
	if(input_capture[1] > input_capture[0]) {
		difference = input_capture[1] - input_capture[0];
		return (float) 1/(difference*0.0001f);
	} else if(input_capture[1] < input_capture[0]) {
		difference = 0xFFFF - input_capture[1] + input_capture[0] + 1;
		return (float) 1/(difference*0.0001f);
	} else {
		return 1/(65335*0.0001f);
	}
}

float STM32_PLC_Input_Capture_Get(uint8_t i) {
	if(i == 0)
		return compute_frequency((uint16_t*)input_capture0);
	else
		return compute_frequency((uint16_t*)input_capture1);
}

