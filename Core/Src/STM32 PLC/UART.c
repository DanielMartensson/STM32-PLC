/*
 * UART.c
 *
 *  Created on: Jun 14, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

/* This code is not used in STM32 - But the code works */

static uint8_t pRxData[100];
static uint32_t Size = 100;
static UART_HandleTypeDef* huart;
#define TIME_OUT 100

void STM32_PLC_UART_Start(UART_HandleTypeDef* huart1) {
	huart = huart1;
	HAL_UART_Receive_IT(huart, pRxData, Size);
}

void STM32_PLC_UART_Transmit(uint8_t* pTxData, uint16_t Size) {
	HAL_UART_Transmit(huart, pTxData, Size, TIME_OUT);
}

uint8_t STM32_PLC_UART_Receive(uint8_t* data) {
	memcpy(data, pRxData, Size);
	return sizeof(pRxData);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	HAL_UART_Receive(huart, pRxData, Size, TIME_OUT);
}
