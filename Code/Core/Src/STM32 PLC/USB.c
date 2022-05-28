/*
 * USB.c
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

/* Private functions */
static uint32_t read_can_bus_message_from_open_source_logger(uint32_t byte_index, uint8_t *receive_buf);
static uint32_t read_control_signals_from_open_source_logger(uint32_t byte_index, uint8_t *receive_buf);
static uint32_t read_set_pwm_prescaler_message(uint32_t byte_index, uint8_t *receive_buf);
static uint32_t read_set_adc_gain_message(uint32_t byte_index, uint8_t *receive_buf);
static uint32_t send_back_adc_gains(uint32_t byte_index, uint8_t *receive_buf);
static void send_measurements_to_open_source_logger();
static void send_back_pwm_prescalers();

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
	/* Toggle the USB LED */
	HAL_GPIO_TogglePin(LED_USB_GPIO_Port, LED_USB_Pin);

	/* Read all bytes as they where packages */
	uint32_t byte_index = 0;
	while(byte_index < receive_len){
		/* Always add +1 for byte_index because the previous byte index was the message type */
		uint8_t message_type = receive_buf[byte_index++];

		/* Read the message type */
		switch(message_type){
		case READ_CAN_BUS_MESSAGE_TYPE:
			byte_index = read_can_bus_message_from_open_source_logger(byte_index, receive_buf);
			break;
		case READ_CONTROL_SIGNALS_MESSAGE_TYPE:
			/* This case will be called all the time */
			byte_index = read_control_signals_from_open_source_logger(byte_index, receive_buf);
			break;
		case READ_SET_PWM_PRESCALER_MESSAGE_TYPE:
			byte_index = read_set_pwm_prescaler_message(byte_index, receive_buf);
			break;
		case READ_SET_ANALOG_INPUT_GAIN_MESSAGE_TYPE:
			byte_index = read_set_adc_gain_message(byte_index, receive_buf);
			break;
		case SEND_BACK_PWM_PRESCALERS_MESSAGE_TYPE:
			send_back_pwm_prescalers();
			break;
		case SEND_BACK_ANALOG_GAINS_MESSAGE_TYPE:
			byte_index = send_back_adc_gains(byte_index, receive_buf);
			break;
		default:
			byte_index = receive_len; /* In case if the switch statement did not understand */
		}
	}
}

static uint32_t read_can_bus_message_from_open_source_logger(uint32_t byte_index, uint8_t *receive_buf){
	/* Create the CAN message */
	CAN_TxHeaderTypeDef TxHeader = {0};
	TxHeader.IDE = receive_buf[byte_index++]; /* CAN_ID_STD or CAN_ID_EXT */
	uint32_t ID = (receive_buf[byte_index] << 24) | (receive_buf[byte_index + 1] << 16) | (receive_buf[byte_index + 2] << 8) | receive_buf[byte_index + 3];
	byte_index += 4;
	/* Give ID to both StdID and ExtId. The IDE variable determine which one we are going to use */
	TxHeader.StdId = ID;
	TxHeader.ExtId = ID;
	TxHeader.DLC = receive_buf[byte_index++];
	uint8_t data[TxHeader.DLC];
	for(uint8_t i = 0; i < TxHeader.DLC; i++)
		data[i] = receive_buf[byte_index++];
	TxHeader.RTR = CAN_RTR_DATA;                                /* Data frame */
	TxHeader.TransmitGlobalTime = DISABLE;
	STM32_PLC_CAN_Transmit(data, &TxHeader);

	/* Return byte index value */
	return byte_index;
}

static uint32_t read_control_signals_from_open_source_logger(uint32_t byte_index, uint8_t *receive_buf){
	for(uint8_t i = 0; i < 8; i++){
		STM32_PLC_PWM_Set(i, (receive_buf[byte_index] << 8) | receive_buf[byte_index + 1]);
		byte_index += 2;
	}
	for(uint8_t i = 0; i < 3; i++){
		STM32_PLC_Analog_Output_Set(i, (receive_buf[byte_index] << 8) | receive_buf[byte_index + 1]);
		byte_index += 2;
	}

	/* Send measurements back */
	send_measurements_to_open_source_logger();

	/* Return byte index value */
	return byte_index;
}

static void send_measurements_to_open_source_logger(){
	/* Create array of measurements */
	uint8_t send_data_array[60] = {0};
	uint8_t index = 0;

	/* Set the message type */
	send_data_array[index++] = SEND_MEASUREMENTS_MESSAGE_TYPE;

	/* Set digital inputs */
	for (uint8_t i = 0; i < 10; i++)
		send_data_array[index++] = STM32_PLC_Digital_Input_Get(i);

	/* Set analog single input values */
	for (uint8_t i = 0; i < 12; i++) {
		uint16_t adc_value = STM32_PLC_Analog_Input_ADC_Get_Raw(i);
		send_data_array[index++] =  adc_value>> 8;
		send_data_array[index++] = adc_value;
	}

	/* Set analog differential input values */
	for (uint8_t i = 0; i < 5; i++) {
		uint16_t adc_value = STM32_PLC_Analog_Input_DADC_Get_Raw(i);
		send_data_array[index++] = adc_value >> 8;
		send_data_array[index++] = adc_value;
	}

	/* Set input capture values */
	for (uint8_t i = 0; i < 4; i++) {
		uint16_t input_capture_value = STM32_PLC_Input_Capture_Get_Raw(i);
		send_data_array[index++] = input_capture_value >> 8;
		send_data_array[index++] = input_capture_value;
	}

	/* Set encoder values */
	for (uint8_t i = 0; i < 3; i++) {
		uint16_t encoder_value = STM32_PLC_Encoder_Get_Raw(i);
		send_data_array[index++] = encoder_value >> 8;
		send_data_array[index++] = encoder_value;
	}

	/* Send the data via USB */
	CDC_Transmit_FS(send_data_array, index);
}


static uint32_t read_set_pwm_prescaler_message(uint32_t byte_index, uint8_t *receive_buf){
	/* What type of PWM should be send the prescaler */
	uint8_t pwm_peripheral = receive_buf[byte_index++];

	/* Read the prescaler and apply it */
	uint16_t prescaler = receive_buf[byte_index] << 8 | receive_buf[byte_index + 1];
	byte_index += 2;

	/* Select witch peripheral */
	switch(pwm_peripheral){
	case 0:
		STM32_PLC_PWM0_To_PWM3_Set_Prescaler(prescaler, true);
		break;
	case 1:
		STM32_PLC_PWM4_To_PWM7_Set_Prescaler(prescaler, true);
		break;
	}

	/* Return byte index value */
	return byte_index;

}

static uint32_t read_set_adc_gain_message(uint32_t byte_index, uint8_t *receive_buf){
	/* What type of ADC should be send the gain too ? */
	uint8_t sdadc = receive_buf[byte_index++];

	/* Get the configuration index */
	uint8_t configuration_index = receive_buf[byte_index++];

	/* Read the gain and apply it */
	uint8_t gain = receive_buf[byte_index++];

	/* Set the gain */
	STM32_PLC_Analog_Input_Set_Gain(sdadc, configuration_index, gain, true);

	/* Return byte index value */
	return byte_index;
}

static uint32_t send_back_adc_gains(uint32_t byte_index, uint8_t *receive_buf){
	/* Create array of gains */
	uint8_t send_data_array[4] = {0};
	uint8_t index = 0;

	/* Get sdadc index */
	uint8_t sdadc = receive_buf[byte_index++];

	/* Get the gains */
	uint8_t gain_for_configuration_index_0, gain_for_configuration_index_1, gain_for_configuration_index_2;
	switch(sdadc){
	case 1:
		STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_1(&gain_for_configuration_index_0, &gain_for_configuration_index_1, &gain_for_configuration_index_2);
		break;
	case 2:
		STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_2(&gain_for_configuration_index_0, &gain_for_configuration_index_1, &gain_for_configuration_index_2);
		break;
	case 3:
		STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_3(&gain_for_configuration_index_0, &gain_for_configuration_index_1, &gain_for_configuration_index_2);
		break;
	}

	/* Fill the array */
	send_data_array[index++] = SEND_BACK_ANALOG_GAINS_MESSAGE_TYPE;
	send_data_array[index++] = gain_for_configuration_index_0;
	send_data_array[index++] = gain_for_configuration_index_1;
	send_data_array[index++] = gain_for_configuration_index_2;

	/* Send the data via USB */
	CDC_Transmit_FS(send_data_array, index);

	/* Return index */
	return byte_index;
}

static void send_back_pwm_prescalers(){
	/* Create array of prescalers */
	uint8_t send_data_array[5] = {0};
	uint8_t index = 0;

	/* Get the prescalers */
	uint16_t prescaler_for_PWM_0_3, prescaler_for_PWM_4_7;
	STM32_PLC_Flash_Get_PWM_Prescalers(&prescaler_for_PWM_0_3, &prescaler_for_PWM_4_7);

	/* Fill the array */
	send_data_array[index++] = SEND_BACK_PWM_PRESCALERS_MESSAGE_TYPE;
	send_data_array[index++] = prescaler_for_PWM_0_3 >> 8;
	send_data_array[index++] = prescaler_for_PWM_0_3;
	send_data_array[index++] = prescaler_for_PWM_4_7 >> 8;
	send_data_array[index++] = prescaler_for_PWM_4_7;

	/* Send the data via USB */
	CDC_Transmit_FS(send_data_array, index);
}
