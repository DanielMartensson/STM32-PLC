/*
 * USB.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

/* Protocol parameters */
#define CAN_BUS_MESSAGE 0
#define PWM_MESSAGE 1
#define ANALOG_OUTPUT_MESSAGE 2
#define SEND_BACK_MEASUREMENT_MESSAGE 3

/* This is a converter for float -> uint8_t or uint8_t -> float */
union{
    float f;
    uint8_t u8[4];
}union_f_u8;


/*
 * This is a "interrupt" function made by me.
 * CDC_ReceiveCallback(Buf, *Len); should always be implemented inside the function
 * static int8_t CDC_Receive_FS(uint8_t* Buf, uint32_t *Len) at usbd_cdc_if.c
 * where a weak empty function named
 * __weak void CDC_ReceiveCallback(uint8_t* receive_buf, uint32_t receive_len){
 *
 * }
 * is there below
 */
void CDC_ReceiveCallback(uint8_t* receive_buf, uint32_t receive_len){
	/*
	 * The protocol:
	 * receive_buf[0] = Determine what type of message
	 * receive_buf[1..receive_len] = The data
	 */
	uint8_t message_type = receive_buf[0];
	uint8_t index = 0;
	CAN_TxHeaderTypeDef TxHeader = {0};
	uint8_t send_data_array[47];
	switch(message_type){
	case CAN_BUS_MESSAGE:
		/*
		 * CAN-bus message for extended ID:
		 * receive_buf[0] = 0                                       0 stands for CAN_BUS_MESSAGE
		 * receive_buf[1] = 0 or 1                                  0 for standard ID, 1 for extended ID
		 * receive_buf[2] = ID MSB                                  Most significant bit
		 * receive_buf[3] = ID                                      Remove this if you are using standard ID
		 * receive_buf[4] = ID                                      Remove this if you are using standard ID
		 * receive_buf[5] = ID LSB                                  Least significant bit
		 * receive_buf[6] = DLC                                     Length of data message
		 * receive_buf[7..7+DLC]                                    Data
		 */
		if(receive_buf[1] == 0){
			TxHeader.IDE = CAN_ID_STD;
			TxHeader.StdId = (receive_buf[2] << 8) | receive_buf[3];
			TxHeader.DLC = receive_buf[4];
			for(uint8_t i = 0; i < receive_buf[4]; i++)
				send_data_array[i] = receive_buf[5 + i];
		}else{
			TxHeader.IDE = CAN_ID_EXT;
			TxHeader.ExtId = (receive_buf[2] << 24) | (receive_buf[3] << 16) | (receive_buf[4] << 8) | receive_buf[5];
			TxHeader.DLC = receive_buf[6];
			for(uint8_t i = 0; i < receive_buf[6]; i++)
				send_data_array[i] = receive_buf[7 + i];
		}
		TxHeader.RTR = CAN_RTR_DATA;                                /* Data frame */
		TxHeader.TransmitGlobalTime = DISABLE;
		STM32_PLC_CAN_Transmit(send_data_array, &TxHeader);
		break;
	case PWM_MESSAGE:
		/* Implement the PWM parameters */
		for(uint8_t i = 0; i < 8; i++){
			STM32_PLC_PWM_Set(i, (receive_buf[index+1] << 8) | receive_buf[index]);
			index += 2;
		}
		break;
	case ANALOG_OUTPUT_MESSAGE:
		/* Implement the analog output parameters */
		for(uint8_t i = 0; i < 3; i++){
			STM32_PLC_Analog_Output_Set(i, (receive_buf[index+1] << 8 ) | receive_buf[index]);
			index += 2;
		}
		break;
	case SEND_BACK_MEASUREMENT_MESSAGE:
		/* Set the type of message */
		send_data_array[index] = SEND_BACK_MEASUREMENT_MESSAGE;
		index++;
		/* Get digital inputs */
		for(uint8_t i = 0; i < 8; i++){
			send_data_array[index] = STM32_PLC_Digital_Input_Get(i);
			index++;
		}
		/* Get ADC values */
		for(uint8_t i = 0; i < 8; i++){
			send_data_array[index] = STM32_PLC_Analog_Input_ADC_Get_Raw(i);
			send_data_array[index+1] = STM32_PLC_Analog_Input_ADC_Get_Raw(i) >> 8;
			index += 2;
		}
		/* Get DADC values */
		for(uint8_t i = 0; i < 5; i++){
			send_data_array[index] = STM32_PLC_Analog_Input_DADC_Get_Raw(i);
			send_data_array[index+1] = STM32_PLC_Analog_Input_DADC_Get_Raw(i) >> 8;
			index += 2;
		}
		/* Get capture inputs */
		for(uint8_t i = 0; i < 2; i++){
			union_f_u8.f = STM32_PLC_Input_Capture_Get(i);
			for(uint8_t i = 0; i < 4; i++){
				send_data_array[index] = union_f_u8.u8[i];
				index++;
			}
		}
		/* Get encoder inputs */
		for(uint8_t i = 0; i < 2; i++){
			send_data_array[index] = STM32_PLC_Encoder_Get_Raw(i);
			send_data_array[index+1] = STM32_PLC_Encoder_Get_Raw(i) >> 8;
			index += 2;
		}
		CDC_Transmit_FS(send_data_array, 1 + 8 + 8*2 + 5*2 + 2*4 + 2*2);
		break;
	}
}

