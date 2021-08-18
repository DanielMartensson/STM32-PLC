/*
 * Initial_Startup.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"
#include "Touch Screen/Touch_screen.h"

void STM32_PLC_Initial_Startup(J1939 *j1939) {

	/* Mount SD card */
	FRESULT status = STM32_PLC_SD_Mont_Card();
	char text[700];
	if(status != FR_OK){
		sprintf(text, "SD mount error with FatFS code:%i", status);
		STM32_PLC_LCD_Show_Information_OK_Dialog(text);
	}

	/* Calibration setup */
	float Scale_X, Scale_Y, Bias_X, Bias_Y;
	sprintf(text, "0%s0%s0%s0%s", DELIMITER, DELIMITER, DELIMITER, DELIMITER);
	status = STM32_PLC_SD_Create_New_File_With_Read_Write("TOUCH.TXT", text, false);
	if(status == FR_OK) {
		/* File just has been created */
		STM32_PLC_LCD_Calibrate_Touch();
		STM32_PLC_LCD_Get_Touch_Calibration_Parameters(&Scale_X, &Scale_Y, &Bias_X, &Bias_Y);
		sprintf(text, "%f%s%f%s%f%s%f", Scale_X, DELIMITER, Scale_Y, DELIMITER, Bias_X, DELIMITER, Bias_Y);
		STM32_PLC_SD_Open_Existing_File_With_Write("TOUCH.TXT");
		STM32_PLC_SD_Write_File(text);
		STM32_PLC_SD_Close_File();
	} else if (status == FR_EXIST) {
		/* Calibration parameters exist */
		STM32_PLC_SD_Open_Existing_File_With_Read("TOUCH.TXT");
		STM32_PLC_SD_Read_File(text, sizeof(text));
		Scale_X = atoff(strtok(text, DELIMITER));
		Scale_Y = atoff(strtok(NULL, DELIMITER));
		Bias_X = atoff(strtok(NULL, DELIMITER));
		Bias_Y = atoff(strtok(NULL, DELIMITER));
		STM32_PLC_LCD_Set_Touch_Calibration_Parameters(&Scale_X, &Scale_Y, &Bias_X, &Bias_Y);
	}else{
		sprintf(text, "SD write/read error with FatFS code:%i", status);
		STM32_PLC_LCD_Show_Information_OK_Dialog(text);
	}

	/* Program select */
	STM32_PLC_SD_Create_New_File_With_Read_Write("PROGRAM.TXT", "0", false);
	STM32_PLC_SD_Open_Existing_File_With_Read("PROGRAM.TXT");
	STM32_PLC_SD_Read_File(text, sizeof(text));
	uint8_t program_number = atoi(text);
	STM32_PLC_LCD_Set_Control_Program(program_number);
	STM32_PLC_SD_Close_File();

	/* Insert the program parameters for the program who is already selected */
	char filename[20];
	sprintf(filename, "PROGRAM%i.TXT", program_number);
	sprintf(text, "0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0%s0", DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER);
	STM32_PLC_SD_Create_New_File_With_Read_Write(filename, text, false);
	STM32_PLC_SD_Open_Existing_File_With_Read(filename);
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	float parameters[20] = {0};
	for(uint8_t i = 0; i < 20; i++)
		if(i == 0)
			parameters[i] = atoff(strtok(text, DELIMITER));
		else
			parameters[i] = atoff(strtok(NULL, DELIMITER));
	STM32_PLC_LCD_Set_Program_Parameters(parameters);

	/* Analog input settings */
	sprintf(text, "0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0%s0,0,0", DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER);
	STM32_PLC_SD_Create_New_File_With_Read_Write("ANALOG.TXT", text, false);
	STM32_PLC_SD_Open_Existing_File_With_Read("ANALOG.TXT");
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	/* Collect analog values */
	char delimiters[4];
	sprintf(delimiters, "%s,", DELIMITER); /* Multiple delimiter */
	float min_max_bias[3]; /* 3 values per each analog input channel */
	for(uint8_t i = 0; i < 17; i++) {
		if(i == 0){
			min_max_bias[0] = atoff(strtok(text, delimiters));
			min_max_bias[1] = atoff(strtok(NULL, delimiters));
			min_max_bias[2] = atoff(strtok(NULL, delimiters));
		} else {
			min_max_bias[0] = atoff(strtok(NULL, delimiters));
			min_max_bias[1] = atoff(strtok(NULL, delimiters));
			min_max_bias[2] = atoff(strtok(NULL, delimiters));
		}
		if(i <= 11)
			STM32_PLC_Analog_Input_ADC_Set_Calibration(i, min_max_bias[0], min_max_bias[1], min_max_bias[2]);
		else
			STM32_PLC_Analog_Input_DADC_Set_Calibration(i - 12, min_max_bias[0], min_max_bias[1], min_max_bias[2]);
	}

	/* SDADC settings */
	sprintf(text, "0,0%s0,0%s0,0%s0,0%s0,0%s0,0%s0,0%s0,0%s0,0", DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER);
	STM32_PLC_SD_Create_New_File_With_Read_Write("SDADC.TXT", text, false);
	STM32_PLC_SD_Open_Existing_File_With_Read("SDADC.TXT");
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	uint8_t gain;
	uint16_t offset;
	for(uint8_t i = 9; i < 9; i++) {
		if(i == 0){
			gain = atoi(strtok(text, delimiters));
			offset = atoi(strtok(NULL, delimiters));
		}else{
			gain = atoi(strtok(NULL, delimiters));
			offset = atoi(strtok(NULL, delimiters));
		}
		switch(i){
		case 0:
			/* SDADC1 */
			STM32_PLC_Analog_Input_Set_Gain_Offset(1, SDADC_CONF_INDEX_0, gain, offset);
			break;
		case 1:
			STM32_PLC_Analog_Input_Set_Gain_Offset(1, SDADC_CONF_INDEX_1, gain, offset);
			break;
		case 2:
			STM32_PLC_Analog_Input_Set_Gain_Offset(1, SDADC_CONF_INDEX_2, gain, offset);
			break;
		case 3:
			/* SDADC 2 */
			STM32_PLC_Analog_Input_Set_Gain_Offset(2, SDADC_CONF_INDEX_0, gain, offset);
			break;
		case 4:
			STM32_PLC_Analog_Input_Set_Gain_Offset(2, SDADC_CONF_INDEX_1, gain, offset);
			break;
		case 5:
			STM32_PLC_Analog_Input_Set_Gain_Offset(2, SDADC_CONF_INDEX_2, gain, offset);
			break;
		case 6:
			/* SDADC 3 */
			STM32_PLC_Analog_Input_Set_Gain_Offset(3, SDADC_CONF_INDEX_0, gain, offset);
			break;
		case 7:
			STM32_PLC_Analog_Input_Set_Gain_Offset(3, SDADC_CONF_INDEX_1, gain, offset);
			break;
		case 8:
			STM32_PLC_Analog_Input_Set_Gain_Offset(3, SDADC_CONF_INDEX_2, gain, offset);
			break;
		}
	}

	/* PWM settings */
	sprintf(text, "0%s0", DELIMITER);
	STM32_PLC_SD_Create_New_File_With_Read_Write("PWM.TXT", text, false);
	STM32_PLC_SD_Open_Existing_File_With_Read("PWM.TXT");
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	uint16_t prescaler_PWM_0_3 = atoi(strtok(text, DELIMITER));
	uint16_t prescaler_PWM_4_7 = atoi(strtok(NULL, DELIMITER));
	STM32_PLC_PWM0_To_PWM3_Set_Prescaler(prescaler_PWM_0_3);
	STM32_PLC_PWM4_To_PWM7_Set_Prescaler(prescaler_PWM_4_7);

	/* Encoder settings */
	sprintf(text, "1%s1", DELIMITER); /* Important that they cannot be zeros */
	STM32_PLC_SD_Create_New_File_With_Read_Write("ENCODER.TXT", text, false);
	STM32_PLC_SD_Open_Existing_File_With_Read("ENCODER.TXT");
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	uint16_t pulses_per_revolution_0 = atoi(strtok(text, DELIMITER));
	uint16_t pulses_per_revolution_1 = atoi(strtok(NULL, DELIMITER));
	STM32_PLC_Encoder_Set_Pulses_Per_Revolutions(0, pulses_per_revolution_0);
	STM32_PLC_Encoder_Set_Pulses_Per_Revolutions(1, pulses_per_revolution_1);

	/* SAE J1939 Name */
	sprintf(text, "0%s0%s0%s0%s0%s0%s0%s0%s0", DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER);
	STM32_PLC_SD_Create_New_File_With_Read_Write("NAME.TXT", text, false);
	STM32_PLC_SD_Open_Existing_File_With_Read("NAME.TXT");
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	j1939->this_name.identity_number = atoi(strtok(text, DELIMITER));
	j1939->this_name.manufacturer_code = atoi(strtok(NULL, DELIMITER));
	j1939->this_name.function_instance = atoi(strtok(NULL, DELIMITER));
	j1939->this_name.ECU_instance = atoi(strtok(NULL, DELIMITER));
	j1939->this_name.function = atoi(strtok(NULL, DELIMITER));
	j1939->this_name.vehicle_system = atoi(strtok(NULL, DELIMITER));
	j1939->this_name.arbitrary_address_capable = atoi(strtok(NULL, DELIMITER));
	j1939->this_name.industry_group = atoi(strtok(NULL, DELIMITER));
	j1939->this_name.vehicle_system_instance = atoi(strtok(NULL, DELIMITER));

	/* Read identifications */
	sprintf(text, "0%s0%s0%s0%s0%s0%s0%s0%s0", DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER, DELIMITER);
	STM32_PLC_SD_Create_New_File_With_Read_Write("ID.TXT", text, false);
	STM32_PLC_SD_Open_Existing_File_With_Read("ID.TXT");
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();

	/* Software identification */
	char *software_identification = strtok(text, DELIMITER);
	j1939->this_identifications.software_identification.number_of_fields = strlen(software_identification); /* Specify the length of software ID is a SAE J1939 standard, compared to ECU/Component identification */
	memcpy(j1939->this_identifications.software_identification.identifications, (uint8_t*)software_identification, j1939->this_identifications.software_identification.number_of_fields);

	/* ECU identification */
	char *ecu_part_number = strtok(NULL, DELIMITER);
	memcpy(j1939->this_identifications.ecu_identification.ecu_part_number, (uint8_t*)ecu_part_number, strlen(ecu_part_number));
	char *ecu_serial_number = strtok(NULL, DELIMITER);
	memcpy(j1939->this_identifications.ecu_identification.ecu_serial_number, (uint8_t*)ecu_serial_number, strlen(ecu_serial_number));
	char *ecu_location = strtok(NULL, DELIMITER);
	memcpy(j1939->this_identifications.ecu_identification.ecu_location, (uint8_t*)ecu_location, strlen(ecu_location));
	char *ecu_type = strtok(NULL, DELIMITER);
	memcpy(j1939->this_identifications.ecu_identification.ecu_type, (uint8_t*)ecu_type, strlen(ecu_type));

	/* Component identification */
	char *component_product_date = strtok(NULL, DELIMITER);
	memcpy(j1939->this_identifications.component_identification.component_product_date, (uint8_t*)component_product_date, strlen(component_product_date));
	char *component_model_name = strtok(NULL, DELIMITER);
	memcpy(j1939->this_identifications.component_identification.component_model_name, (uint8_t*)component_model_name, strlen(component_model_name));
	char *component_serial_number = strtok(NULL, DELIMITER);
	memcpy(j1939->this_identifications.component_identification.component_serial_number, (uint8_t*)component_serial_number, strlen(component_serial_number));
	char *component_unit_name = strtok(NULL, DELIMITER);
	memcpy(j1939->this_identifications.component_identification.component_unit_name, (uint8_t*)component_unit_name, strlen(component_unit_name));

	/* ECU address */
	STM32_PLC_SD_Create_New_File_With_Read_Write("ADDRESS.TXT", "0", false);
	STM32_PLC_SD_Open_Existing_File_With_Read("ADDRESS.TXT");
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	j1939->this_ECU_address = atoi(strtok(text, DELIMITER));

	/* Unmount SD card */
	STM32_PLC_SD_Unmount_Card();

}
