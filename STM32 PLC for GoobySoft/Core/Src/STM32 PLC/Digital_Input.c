/*
 * Digital_Input.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

uint16_t STM32_PLC_Digital_Input_Get(uint8_t i) {
	switch (i) {
	case 0:
		return HAL_GPIO_ReadPin(DI0_GPIO_Port, DI0_Pin);
	case 1:
		return HAL_GPIO_ReadPin(DI1_GPIO_Port, DI1_Pin);
	case 2:
		return HAL_GPIO_ReadPin(DI2_GPIO_Port, DI2_Pin);
	case 3:
		return HAL_GPIO_ReadPin(DI3_GPIO_Port, DI3_Pin);
	case 4:
		return HAL_GPIO_ReadPin(DI4_GPIO_Port, DI4_Pin);
	case 5:
		return HAL_GPIO_ReadPin(DI5_GPIO_Port, DI5_Pin);
	case 6:
		return HAL_GPIO_ReadPin(DI6_GPIO_Port, DI6_Pin);
	case 7:
		return HAL_GPIO_ReadPin(DI7_GPIO_Port, DI7_Pin);
	case 8:
		return HAL_GPIO_ReadPin(DI8_GPIO_Port, DI8_Pin);
	case 9:
		return HAL_GPIO_ReadPin(DI9_GPIO_Port, DI9_Pin);
	default:
		return 0;
	}
}
