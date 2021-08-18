/*
 * Pulse_Counter.c
 *
 *  Created on: Aug 7, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

static uint32_t pulse_count[4] = {0};

void STM32_PLC_Pulse_Count_Set(uint8_t i){
	pulse_count[i]++;
}

uint32_t STM32_PLC_Pulse_Count_Get(uint8_t i){
	return pulse_count[i];
}

void STM32_PLC_Pulse_Count_Reset(){
	memset(pulse_count, 0, sizeof(pulse_count));
}
