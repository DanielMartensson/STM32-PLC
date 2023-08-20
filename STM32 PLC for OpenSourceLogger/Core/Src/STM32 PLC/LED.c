/*
 * LED.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

void STM32_PLC_LED(){
	/* Do a funny blink sequence */
	for(uint8_t i = 0; i < 0x7; i++){
		STM32_PLC_LED_Set(i);
		HAL_Delay(100);
	}
	STM32_PLC_LED_Set(0);
}

/* Select a program number between 0 and 31 e.g 5-bit. 0 is no program activated */
void STM32_PLC_LED_Set(uint8_t binary_value){
	HAL_GPIO_WritePin(LED_USB_GPIO_Port, LED_USB_Pin, binary_value & 0b100);
	HAL_GPIO_WritePin(LED_CAN_GPIO_Port, LED_CAN_Pin, binary_value & 0b010);
	HAL_GPIO_WritePin(LED_ERROR_GPIO_Port, LED_ERROR_Pin, binary_value & 0b001);
}

