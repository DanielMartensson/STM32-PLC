/*
 * PWM.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

static TIM_HandleTypeDef *PWM_TIM_0_3;
static TIM_HandleTypeDef *PWM_TIM_4_7;
static uint16_t PWM[8] = { 0 };

void STM32_PLC_Start_PWM(TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim5) {
	/* See PWM frequencies at PWM_frequency_settings_frame.c */
	if(HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_1)  != HAL_OK)
		Error_Handler();
	if(HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_2)  != HAL_OK)
			Error_Handler();
	if(HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_3)  != HAL_OK)
			Error_Handler();
	if(HAL_TIM_PWM_Start(htim2, TIM_CHANNEL_4)  != HAL_OK)
			Error_Handler();
	if(HAL_TIM_PWM_Start(htim5, TIM_CHANNEL_1)  != HAL_OK)
		Error_Handler();
	if(HAL_TIM_PWM_Start(htim5, TIM_CHANNEL_2)  != HAL_OK)
			Error_Handler();
	if(HAL_TIM_PWM_Start(htim5, TIM_CHANNEL_3)  != HAL_OK)
			Error_Handler();
	if(HAL_TIM_PWM_Start(htim5, TIM_CHANNEL_4)  != HAL_OK)
			Error_Handler();
	PWM_TIM_4_7 = htim2;
	PWM_TIM_0_3 = htim5;
}

void STM32_PLC_PWM_Set(uint8_t i, uint16_t ON_Period) {
	switch (i) {
	case 0:
		PWM_TIM_0_3->Instance->CCR1 = ON_Period;
		PWM[0] = ON_Period;
		break;
	case 1:
		PWM_TIM_0_3->Instance->CCR2 = ON_Period;
		PWM[1] = ON_Period;
		break;
	case 2:
		PWM_TIM_0_3->Instance->CCR3 = ON_Period;
		PWM[2] = ON_Period;
		break;
	case 3:
		PWM_TIM_0_3->Instance->CCR4 = ON_Period;
		PWM[3] = ON_Period;
		break;
	case 4:
		PWM_TIM_4_7->Instance->CCR1 = ON_Period;
		PWM[4] = ON_Period;
		break;
	case 5:
		PWM_TIM_4_7->Instance->CCR2 = ON_Period;
		PWM[5] = ON_Period;
		break;
	case 6:
		PWM_TIM_4_7->Instance->CCR3 = ON_Period;
		PWM[6] = ON_Period;
		break;
	case 7:
		PWM_TIM_4_7->Instance->CCR4 = ON_Period;
		PWM[7] = ON_Period;
		break;
	}
}

uint16_t STM32_PLC_PWM_Get(uint8_t i) {
	return PWM[i];
}

void STM32_PLC_PWM_Reset() {
	for(uint8_t i = 0; i < 8; i++)
		STM32_PLC_PWM_Set(i, 0);
}

void STM32_PLC_PWM0_To_PWM3_Set_Prescaler(uint16_t prescaler) {
	PWM_TIM_0_3->Instance->CNT = 0xFFFF;
	PWM_TIM_0_3->Instance->PSC = prescaler;
}

void STM32_PLC_PWM4_To_PWM7_Set_Prescaler(uint16_t prescaler) {
	PWM_TIM_4_7->Instance->CNT = 0xFFFF;
	PWM_TIM_4_7->Instance->PSC = prescaler;
}

