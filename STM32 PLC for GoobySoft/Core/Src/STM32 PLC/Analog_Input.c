/*
 * Analog_Input.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

static int16_t SDADC1_Single[9];
static int16_t SDADC2_Single[3];
static int16_t SDADC3_Differential[5];
static SDADC_HandleTypeDef* handler_sdadc1;
static SDADC_HandleTypeDef* handler_sdadc2;
static SDADC_HandleTypeDef* handler_sdadc3;
static float bias_list[17] = {0};
static float scalar_list[17] = {1};

void STM32_PLC_Analog_Input(TIM_HandleTypeDef* htim12, TIM_HandleTypeDef* htim13, SDADC_HandleTypeDef* hsdadc1, SDADC_HandleTypeDef* hsdadc2, SDADC_HandleTypeDef* hsdadc3) {
	/*
	 * For TIM12, TIM13
	 * Timer clock: 48 Mhz
	 * Prescaler: 99
	 * Counter: 4800
	 * Update frequency: 100 Hz
	 */
	if(HAL_TIM_OC_Start(htim13, TIM_CHANNEL_1) != HAL_OK) /* TIM13 Channel 1 is trigger source for SDADC1 */
		Error_Handler();
	if(HAL_TIM_OC_Start(htim12, TIM_CHANNEL_1) != HAL_OK) /* TIM12 Channel 1 is trigger source for SDADC2 */
		Error_Handler();
	if(HAL_TIM_OC_Start(htim12, TIM_CHANNEL_2) != HAL_OK) /* TIM12 Channel 2 is trigger source for SDADC3 */
		Error_Handler();
	if (HAL_SDADC_CalibrationStart(hsdadc1, SDADC_CALIBRATION_SEQ_3) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_PollForCalibEvent(hsdadc1, HAL_MAX_DELAY) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_CalibrationStart(hsdadc2, SDADC_CALIBRATION_SEQ_3) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_PollForCalibEvent(hsdadc2, HAL_MAX_DELAY) != HAL_OK)
		Error_Handler();
	if (HAL_SDADC_CalibrationStart(hsdadc3, SDADC_CALIBRATION_SEQ_3) != HAL_OK)
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
	handler_sdadc1 = hsdadc1;
	handler_sdadc2 = hsdadc2;
	handler_sdadc3 = hsdadc3;

	/* Set the gains for the ADC */
	uint8_t gain_for_configuration_index_0, gain_for_configuration_index_1, gain_for_configuration_index_2;
	STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_1(&gain_for_configuration_index_0, &gain_for_configuration_index_1, &gain_for_configuration_index_2);
	STM32_PLC_Analog_Input_Set_Gain(0, SDADC_CONF_INDEX_0, gain_for_configuration_index_0, false);
	STM32_PLC_Analog_Input_Set_Gain(0, SDADC_CONF_INDEX_1, gain_for_configuration_index_1, false);
	STM32_PLC_Analog_Input_Set_Gain(0, SDADC_CONF_INDEX_2, gain_for_configuration_index_2, false);

	STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_2(&gain_for_configuration_index_0, &gain_for_configuration_index_1, &gain_for_configuration_index_2);
	STM32_PLC_Analog_Input_Set_Gain(1, SDADC_CONF_INDEX_0, gain_for_configuration_index_0, false);
	STM32_PLC_Analog_Input_Set_Gain(1, SDADC_CONF_INDEX_1, gain_for_configuration_index_1, false);
	STM32_PLC_Analog_Input_Set_Gain(1, SDADC_CONF_INDEX_2, gain_for_configuration_index_2, false);

	STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_3(&gain_for_configuration_index_0, &gain_for_configuration_index_1, &gain_for_configuration_index_2);
	STM32_PLC_Analog_Input_Set_Gain(2, SDADC_CONF_INDEX_0, gain_for_configuration_index_0, false);
	STM32_PLC_Analog_Input_Set_Gain(2, SDADC_CONF_INDEX_1, gain_for_configuration_index_1, false);
	STM32_PLC_Analog_Input_Set_Gain(2, SDADC_CONF_INDEX_2, gain_for_configuration_index_2, false);

	/* Set calibration */
	float scalar, bias;
	for(uint8_t i = 0; i < 17; i++){
		STM32_PLC_Flash_Get_Analog_Input_Calibration(i, &scalar, &bias);
		STM32_PLC_Analog_Input_Set_Calibration(i, scalar, bias, false);
	}
}

void STM32_PLC_Analog_Input_Get_Gain(uint8_t sdadc, uint8_t configuration_index[]) {
	switch(sdadc){
	case 1:
		configuration_index[0] = (handler_sdadc1->Instance->CONF0R >> 20) & 0b111; /* Bits 22:20 GAIN0[2:0]: */
		configuration_index[1] = (handler_sdadc1->Instance->CONF1R >> 20) & 0b111;
		configuration_index[2] = (handler_sdadc1->Instance->CONF2R >> 20) & 0b111;
		break;
	case 2:
		configuration_index[0] = (handler_sdadc2->Instance->CONF0R >> 20) & 0b111; /* Bits 22:20 GAIN0[2:0]: */
		configuration_index[1] = (handler_sdadc2->Instance->CONF1R >> 20) & 0b111;
		configuration_index[2] = (handler_sdadc2->Instance->CONF2R >> 20) & 0b111;
		break;
	case 3:
		configuration_index[0] = (handler_sdadc3->Instance->CONF0R >> 20) & 0b111; /* Bits 22:20 GAIN0[2:0]: */
		configuration_index[1] = (handler_sdadc3->Instance->CONF1R >> 20) & 0b111;
		configuration_index[2] = (handler_sdadc3->Instance->CONF2R >> 20) & 0b111;
		break;
	}
}

void STM32_PLC_Analog_Input_Set_Gain(uint8_t sdadc, uint8_t configuration_index, uint8_t gain, bool save_to_flash) {
	/* Select SDADC handler */
	SDADC_HandleTypeDef *hsdadc;
	switch(sdadc){
	case 0:
		hsdadc = handler_sdadc1;
		break;
	case 1:
		hsdadc = handler_sdadc2;
		break;
	case 2:
		hsdadc = handler_sdadc3;
		break;
	default:
		return;
	}


	/* Stop SDADC */
	hsdadc->Instance->CR2 &= ~SDADC_CR2_ADON;

	/* Set gain */
	switch(configuration_index){
	case SDADC_CONF_INDEX_0:
		hsdadc->Instance->CONF0R &=  ~(0b111 << 20); /* Clear */
		hsdadc->Instance->CONF0R |= gain << 20; 	 /* Bits 22:20 GAIN0[2:0]: */
		if(save_to_flash)
			STM32_PLC_Flash_Set_ADC_Gain_For_Configuration_Index_0(sdadc, gain);
		break;
	case SDADC_CONF_INDEX_1:
		hsdadc->Instance->CONF1R &=  ~(0b111 << 20);
		hsdadc->Instance->CONF1R |= gain << 20;
		if(save_to_flash)
			STM32_PLC_Flash_Set_ADC_Gain_For_Configuration_Index_1(sdadc, gain);
		break;
	case SDADC_CONF_INDEX_2:
		hsdadc->Instance->CONF2R &=  ~(0b111 << 20);
		hsdadc->Instance->CONF2R |= gain << 20;
		if(save_to_flash)
			STM32_PLC_Flash_Set_ADC_Gain_For_Configuration_Index_2(sdadc, gain);
		break;
	}

	/* Start SDADC */
	hsdadc->Instance->CR2 |= SDADC_CR2_ADON;

}

/* Get raw ADC0 to ADC11 */
uint16_t STM32_PLC_Analog_Input_ADC_Get_Raw(uint8_t i) {
	int16_t value = 0;
	switch (i) {
	case 0:
		value = SDADC1_Single[6];
		break;
	case 1:
		value = SDADC1_Single[5];
		break;
	case 2:
		value = SDADC1_Single[4];
		break;
	case 3:
		value = SDADC1_Single[3];
		break;
	case 4:
		value = SDADC1_Single[8];
		break;
	case 5:
		value = SDADC1_Single[7];
		break;
	case 6:
		value = SDADC1_Single[2];
		break;
	case 7:
		value = SDADC1_Single[1];
		break;
	case 8:
		value = SDADC1_Single[0];
		break;
	case 9:
		value = SDADC2_Single[2];
		break;
	case 10:
		value = SDADC2_Single[1];
		break;
	case 11:
		value = SDADC2_Single[0];
		break;
	}
	return value + 0x8000;
}

/* Get calibrated ADC0 to ADC11 */
float STM32_PLC_Analog_Input_ADC_Get_Calibrated(uint8_t i) {
	return scalar_list[i]*((float)STM32_PLC_Analog_Input_ADC_Get_Raw(i)) + bias_list[i];
}

/* Get raw DADC0 to DADC4 */
int16_t STM32_PLC_Analog_Input_DADC_Get_Raw(uint8_t i) {
	int16_t value = 0;
	switch(i){
	case 0:
		value = SDADC3_Differential[4];
		break;
	case 1:
		value = SDADC3_Differential[3];
		break;
	case 2:
		value = SDADC3_Differential[2];
		break;
	case 3:
		value = SDADC3_Differential[1];
		break;
	case 4:
		value = SDADC3_Differential[0];
		break;
	}
	return value;
}

/* Get calibrated DADC0 to DADC4 */
float STM32_PLC_Analog_Input_DADC_Get_Calibrated(uint8_t i) {
	return scalar_list[12+i]*((float)STM32_PLC_Analog_Input_DADC_Get_Raw(i)) + bias_list[12+i];
}

void STM32_PLC_Analog_Input_Set_Calibration(uint8_t input_index, float scalar, float bias, bool save_to_flash){
	scalar_list[input_index] = scalar;
	bias_list[input_index] = bias;
	if(save_to_flash)
		STM32_PLC_Flash_Set_Analog_Input_Calibration(input_index, scalar, bias);
}
