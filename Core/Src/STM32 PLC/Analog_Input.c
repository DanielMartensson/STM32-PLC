/*
 * Analog_Input.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

volatile static int16_t SDADC1_Single[9];
volatile static int16_t SDADC2_Single[3];
volatile static int16_t SDADC3_Differential[5];
static float SDADC_Single_Calibration_Gain[12] = {0};
static float SDADC_Single_Calibration_Bias[12] = {0};
static float SDADC_Differential_Calibration_Gain[5] = {0};
static float SDADC_Differential_Calibration_Bias[5] = {0};
TIM_HandleTypeDef* handler_tim12;
TIM_HandleTypeDef* handler_tim13;
SDADC_HandleTypeDef* handler_sdadc1;
SDADC_HandleTypeDef* handler_sdadc2;
SDADC_HandleTypeDef* handler_sdadc3;

void STM32_PLC_Start_Analog_Input(TIM_HandleTypeDef* htim12, TIM_HandleTypeDef* htim13, SDADC_HandleTypeDef* hsdadc1, SDADC_HandleTypeDef* hsdadc2, SDADC_HandleTypeDef* hsdadc3) {
	/*
	 * For TIM12, TIM13
	 * Timer clock: 48 Mhz
	 * Prescaler: 0
	 * Counter: 48000 (0xbb80)
	 * Update frequency: 1000 Hz
	 */
	HAL_TIM_OC_Start(htim13, TIM_CHANNEL_1); /* TIM13 Channel 1 is trigger source for SDADC1 */
	HAL_TIM_OC_Start(htim12, TIM_CHANNEL_1); /* TIM12 Channel 1 is trigger source for SDADC2 */
	HAL_TIM_OC_Start(htim12, TIM_CHANNEL_2); /* TIM12 Channel 2 is trigger source for SDADC3 */
	if (HAL_SDADC_CalibrationStart(hsdadc1, SDADC_CALIBRATION_SEQ_1) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_PollForCalibEvent(hsdadc1, HAL_MAX_DELAY) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_CalibrationStart(hsdadc2, SDADC_CALIBRATION_SEQ_1) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_PollForCalibEvent(hsdadc2, HAL_MAX_DELAY) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_CalibrationStart(hsdadc3, SDADC_CALIBRATION_SEQ_1) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_PollForCalibEvent(hsdadc3, HAL_MAX_DELAY) != HAL_OK)
		Error_Handler();
	if(HAL_SDADC_InjectedStart_DMA(hsdadc1, (uint32_t*)SDADC1_Single, 9) != HAL_OK)
		Error_Handler();
	if(HAL_SDADC_InjectedStart_DMA(hsdadc2, (uint32_t*)SDADC2_Single, 3) != HAL_OK)
		Error_Handler();
	if(HAL_SDADC_InjectedStart_DMA(hsdadc3, (uint32_t*)SDADC3_Differential, 5) != HAL_OK)
		Error_Handler();


	/* Save */
	handler_tim13 = htim13;
	handler_tim12 = htim12;
	handler_sdadc1 = hsdadc1;
	handler_sdadc2 = hsdadc2;
	handler_sdadc3 = hsdadc3;

}

/* Inline is only for optimization */
static inline int16_t* array_to_pointer(int16_t array[]){
	return array; /* This return the address */
}

void STM32_PLC_Analog_Input_Set_Gain_Offset(uint8_t sdadc, uint8_t configuration_index, uint8_t gain, uint16_t offset) {
	/* Initial */
	SDADC_ConfParamTypeDef ConfParamStruct = {0};
	ConfParamStruct.CommonMode = SDADC_COMMON_MODE_VSSA;
	SDADC_HandleTypeDef *handler;
	uint8_t length_DMA;
	uint32_t *array_DMA;

	/* Stop DMA */
	switch(sdadc){
	case 1:
		/* Stop DMA for SDADC1 */
		if(HAL_SDADC_InjectedStop_DMA(handler_sdadc1) != HAL_OK)
			Error_Handler();
		handler = handler_sdadc1;
		length_DMA = 9;
		array_DMA = (uint32_t*)array_to_pointer((int16_t*)SDADC1_Single);
		ConfParamStruct.InputMode = SDADC_INPUT_MODE_SE_ZERO_REFERENCE;
		break;
	case 2:
		/* Stop DMA for SDADC2 */
		if(HAL_TIM_OC_Stop(handler_tim12, TIM_CHANNEL_1))
			Error_Handler();
		if(HAL_SDADC_InjectedStop_DMA(handler_sdadc2) != HAL_OK)
			Error_Handler();
		handler = handler_sdadc2;
		length_DMA = 3;
		array_DMA = (uint32_t*)array_to_pointer((int16_t*)SDADC2_Single);
		ConfParamStruct.InputMode = SDADC_INPUT_MODE_SE_ZERO_REFERENCE;
		break;
	case 3:
		/* Stop DMA for SDADC3 */
		if(HAL_SDADC_InjectedStop_DMA(handler_sdadc3) != HAL_OK)
			Error_Handler();
		handler = handler_sdadc3;
		length_DMA = 5;
		array_DMA = (uint32_t*)array_to_pointer((int16_t*)SDADC3_Differential);
		ConfParamStruct.InputMode = SDADC_INPUT_MODE_DIFF;
		break;
	default:
		/* Stop DMA for SDADC1 */
		if(HAL_SDADC_InjectedStop_DMA(handler_sdadc1) != HAL_OK)
			Error_Handler();
		handler = handler_sdadc1;
		length_DMA = 9;
		array_DMA = (uint32_t*)array_to_pointer((int16_t*)SDADC1_Single);
		ConfParamStruct.InputMode = SDADC_INPUT_MODE_SE_ZERO_REFERENCE;
		break;
	}

	/* Set gain and offset */
	switch(gain){
	case 0:
		ConfParamStruct.Gain = SDADC_GAIN_1_2;
		break;
	case 1:
		ConfParamStruct.Gain = SDADC_GAIN_1;
		break;
	case 2:
		ConfParamStruct.Gain = SDADC_GAIN_2;
		break;
	case 3:
		ConfParamStruct.Gain = SDADC_GAIN_4;
		break;
	case 4:
		ConfParamStruct.Gain = SDADC_GAIN_8;
		break;
	case 5:
		ConfParamStruct.Gain = SDADC_GAIN_16;
		break;
	case 6:
		ConfParamStruct.Gain = SDADC_GAIN_32;
		break;
	default:
		ConfParamStruct.Gain = SDADC_GAIN_1;
		offset = 0;
		break;
	}
	ConfParamStruct.Offset = offset;

	/* Set calibration */
	if (HAL_SDADC_PrepareChannelConfig(handler, configuration_index, &ConfParamStruct) != HAL_OK)
	    Error_Handler();

	/* Start ADC again */
	if (HAL_SDADC_CalibrationStart(handler, SDADC_CALIBRATION_SEQ_1) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_PollForCalibEvent(handler, HAL_MAX_DELAY) != HAL_OK)
		Error_Handler();
	if(HAL_SDADC_InjectedStart_DMA(handler, array_DMA, length_DMA) != HAL_OK)
		Error_Handler();
}

/* Get ADC0 to ADC11 */
float STM32_PLC_Analog_Input_ADC_Get(uint8_t i) {
	return SDADC_Single_Calibration_Gain[i]*((float)STM32_PLC_Analog_Input_ADC_Get_Raw(i)) + SDADC_Single_Calibration_Bias[i];
}

/* Get raw ADC0 to ADC11 */
uint16_t STM32_PLC_Analog_Input_ADC_Get_Raw(uint8_t i) {
	if(i < 9)
		return SDADC1_Single[i] + 0x8000;
	else
		return SDADC2_Single[i-9] + 0x8000;
}

/* Set calibration ADC0 to ADC11 */
void STM32_PLC_Analog_Input_ADC_Set_Calibration(uint8_t i, float min_value, float max_value, float bias_value) {
	SDADC_Single_Calibration_Gain[i] = (max_value - min_value) / (0xFFFF);
	SDADC_Single_Calibration_Bias[i] = bias_value;
}

/* Get DADC0 to DADC4 */
float STM32_PLC_Analog_Input_DADC_Get(uint8_t i) {
	return SDADC_Differential_Calibration_Gain[i]*((float)STM32_PLC_Analog_Input_DADC_Get_Raw(i)) + SDADC_Differential_Calibration_Bias[i];
}

/* Get raw DADC0 to DADC4 */
int16_t STM32_PLC_Analog_Input_DADC_Get_Raw(uint8_t i) {
	return SDADC3_Differential[i];
}

/* Set calibration DADC0 to DADC4 */
void STM32_PLC_Analog_Input_DADC_Set_Calibration(uint8_t i, float min_value, float max_value, float bias_value) {
	SDADC_Differential_Calibration_Gain[i] = (max_value - min_value) / (0xFFFF);
	SDADC_Differential_Calibration_Bias[i] = bias_value;
}

