/*
 * CAN.c
 *
 *  Created on: Jun 14, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

static CAN_HandleTypeDef *can_handler;
static void Create_CAN_Filter(CAN_HandleTypeDef *hcan);
static void Create_CAN_Interrupt(CAN_HandleTypeDef *hcan);
static uint32_t _IDE = 0;
static uint32_t _ID = 0;
static uint32_t _DLC = 0;
static uint8_t _data[8] = {0};
static bool _is_new_message_for_gooby_soft = false;
static bool _is_new_message_for_open_sae_j1939 = false;

void Callback_Function_Send(uint32_t ID, uint8_t DLC, uint8_t data[]) {
	CAN_TxHeaderTypeDef TxHeader;
	TxHeader.DLC = DLC;
	TxHeader.ExtId = ID;
	TxHeader.StdId = ID;
	TxHeader.IDE = CAN_ID_EXT;
	TxHeader.RTR = CAN_RTR_DATA;                                /* Data frame */
	TxHeader.TransmitGlobalTime = DISABLE;
	STM32_PLC_CAN_Transmit(data, &TxHeader);
}

void Callback_Function_Read(uint32_t* ID, uint8_t data[], bool* is_new_data) {
	/* Slack variables */
	uint32_t IDE = 0;
	uint8_t DLC = 0;
	bool _is_new_data = false;

	/* Read the data */
	STM32_PLC_CAN_Get_ID_Data(&IDE, ID, &DLC, data, &_is_new_data);
	*is_new_data = _is_new_message_for_open_sae_j1939;
	_is_new_message_for_open_sae_j1939 = false;

}

void STM32_PLC_CAN(CAN_HandleTypeDef *hcan) {
	can_handler = hcan;
	Create_CAN_Filter(hcan);
	if (HAL_CAN_Start(hcan) != HAL_OK)
		Error_Handler();
	Create_CAN_Interrupt(hcan);
	CAN_Set_Callback_Functions(Callback_Function_Send, Callback_Function_Read, NULL);
}

HAL_StatusTypeDef STM32_PLC_CAN_Transmit(uint8_t TxData[], CAN_TxHeaderTypeDef *TxHeader) {
	/* Light up the CAN LED */
	uint32_t TxMailbox;
	HAL_StatusTypeDef status = HAL_CAN_AddTxMessage(can_handler, TxHeader, TxData, &TxMailbox);
	return status;
}

void STM32_PLC_CAN_Get_ID_Data(uint32_t *IDE, uint32_t *ID, uint8_t* DLC, uint8_t data[], bool *is_new_message){
	*IDE = _IDE;
	*ID = _ID;
	*DLC = _DLC;
	memcpy(data, _data, 8);
	*is_new_message = _is_new_message_for_gooby_soft;
	_is_new_message_for_gooby_soft = false;
}

/* Interrupt handler that read message */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
	/* This is the message */
	CAN_RxHeaderTypeDef rxHeader = {0};
	if (HAL_CAN_GetRxMessage(can_handler, CAN_RX_FIFO0, &rxHeader, _data) != HAL_OK){
		Error_Handler();
	}
	_IDE = rxHeader.IDE;
	_ID = _IDE == CAN_ID_STD ? rxHeader.StdId : rxHeader.ExtId;
	_DLC = rxHeader.DLC;
	_is_new_message_for_gooby_soft = true;
	_is_new_message_for_open_sae_j1939 = true;

	/* Light up the CAN LED */
	STM32_PLC_LED_Set(LED_CAN_PROCESS);
}

static void Create_CAN_Interrupt(CAN_HandleTypeDef *hcan) {
	/* Don't forget to check NVIC in CAN -> NVIC Settings -> CAN RX0 interrupt */
	if (HAL_CAN_ActivateNotification(hcan, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
			Error_Handler();
}

static void Create_CAN_Filter(CAN_HandleTypeDef *hcan) {
	CAN_FilterTypeDef sFilterConfig;
	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = 0x0000;
	sFilterConfig.FilterIdLow = 0x0000;
	sFilterConfig.FilterMaskIdHigh = 0x0000;
	sFilterConfig.FilterMaskIdLow = 0x0000;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(hcan, &sFilterConfig) != HAL_OK)
		Error_Handler();
}
