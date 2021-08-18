/*
 * Control_program_frame.c
 *
 *  Created on: 25 juli 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

/* Holders for program */
static uint8_t prg = 0;
static float program_parameters[20] = {0}; /* These parameters are only for specific programs */
static uint8_t set_parameters(float parameters[], char title[][60], uint8_t index_title, uint8_t amount_of_controllers, bool only_integer_at_index[]);

/* PI control parameters */
#define AMOUNT_OF_PI_CONTROLLERS 3
#define PI_CONTROLLER_PARAMETER_LENGTH 4
static float PI_I[AMOUNT_OF_PI_CONTROLLERS] = {0};

/* Pulse counter parameters */
#define AMOUNT_OF_PULSE_COUNTERS 4
#define PULSE_COUNTER_PARAMETER_LENGTH 2

/* MRAC Control parameters */
#define AMOUNT_OF_MRAC_CONTROLLERS 3
#define MRAC_CONTROLLER_PARAMETER_LENGTH 2
static float MRAC_I1[AMOUNT_OF_PI_CONTROLLERS] = {0};
static float MRAC_I2[AMOUNT_OF_PI_CONTROLLERS] = {0};

/* ON/OFF control parameters */
#define AMOUNT_OF_ON_OFF_CONTROLLERS 4
#define ON_OFF_CONTROLLER_PARAMETER_LENGTH 2

/* Input output PWM parameters */
#define AMOUNT_OF_INPUT_OUTPUT_PWM 4

/* Input output analog parameters */
#define AMOUNT_OF_INPUT_OUTPUT_ANALOG 3

/* Auxiliary valve control parameters */
#define AMOUNT_OF_AUXILIARY_VALVE_CONTROL 4

/* General purpose valve control parameters */
#define AMOUNT_OF_GENERAL_PURPOSE_VALVE_CONTROL 4
#define GENERAL_PURPOSE_VALVE_CONTROL_PARAMETER_LENGTH 1


void STM32_PLC_LCD_Set_Control_Program(uint8_t program_number) {
	prg = program_number;
	STM32_PLC_LED(program_number);
}

void STM32_PLC_LCD_Set_Program_Parameters(float parameters[]){
	memcpy(program_parameters, parameters, sizeof(program_parameters));
}

uint8_t STM32_PLC_LCD_Get_Control_Program() {
	return prg;
}

void STM32_PLC_LCD_Show_Control_Program_Settings_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Select control program", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Show all programs */
	ILI9341_print_text("Program0:No program", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Program1:PI control", 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Program2:Pulse count", 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Program3:MRAC control", 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Program4:ON/OFF control", 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Program5:Input and output PWM", 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Program6:Input and output Analog", 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Program7:Digital output alarm", 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Program8:Auxiliary valve command", 55, 115, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Program9:General purpose valve command", 55, 125, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Show selected program */
	char text[500];
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Read("PROGRAM.TXT");
	STM32_PLC_SD_Read_File(text, sizeof(text));
	sprintf(text, "Selected program=%i", atoi(text));
	ILI9341_print_text(text, 55, 145, COLOR_YELLOW, COLOR_NAVY, 1);
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();

	/* Show select program button */
	ILI9341_fill_rect(85, 195, 273, 220, COLOR_GREEN);
	ILI9341_hollow_rect(85, 195, 273, 220, COLOR_BLACK);
	ILI9341_print_text("Select program", 95, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for select program button */
	STM32_PLC_LCD_Call_One_Button_Logic(85, 195, 273, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to set program?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Ask for a program number */
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter program number between 0 and 9") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint8_t program_number;
	if(number_value < 0)
		program_number = 0;
	else if(number_value > 9)
		program_number = 9;
	else
		program_number = (uint8_t) number_value;

	/* Apply program number */
	STM32_PLC_LCD_Set_Control_Program(program_number);

	/* Write to SD card*/
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Write("PROGRAM.TXT");
	sprintf(text, "%i", program_number);
	STM32_PLC_SD_Write_File(text);
	STM32_PLC_SD_Close_File();

	/* If no program was selected - Clear everything */
	if(program_number == 0) {
		/* Clear the integrals */
		memset(PI_I, 0, sizeof(PI_I));
		memset(MRAC_I1, 0, sizeof(MRAC_I1));
		memset(MRAC_I2, 0, sizeof(MRAC_I2));

		/* Reset counter for pulses */
		STM32_PLC_Pulse_Count_Reset();
	}

	/* Ask if user want to select parameters */
	if(program_number == 1 || program_number == 2 || program_number == 3 || program_number == 4 || program_number == 9) {
		if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter program parameters? 0:No 1:Yes") == 0) {
			STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
			return;
		}
	}else{
		number_value = 0;
	}
	uint8_t status;
	if(number_value < 0)
		status = 0;
	else if(number_value > 1)
		status = 1;
	else
		status = (uint8_t)number_value;

	/* If yes, select parameters */
	if(status == 1){
		/* Depending on what program we selected - we need to choose right parameters */
		char title_1[4][60] = {"Enter setpoint for PI%i", "Set proportional gain P%i", "Set integral gain G%i", "Anti-winup%i enabled NO:0 or YES:1"};
		char title_2[2][60] = {"Set high threshold%i", "Set low threshold%i"};
		char title_3[2][60] = {"Set setpoint for MRAC%i", "Set integral gain G%i"};
		char title_4[2][60] = {"Set setpoint for ON/OFF%i", "Set max threshold%i"};
		char title_9[1][60] = {"Enter DA%i between 0 and 253"};
		bool only_integer_at_index[4] = {false};
		switch(program_number){
		case 1:
			only_integer_at_index[3] = true;
			status = set_parameters(program_parameters, title_1, PI_CONTROLLER_PARAMETER_LENGTH, AMOUNT_OF_PI_CONTROLLERS, only_integer_at_index);
			break;
		case 2:
			status = set_parameters(program_parameters, title_2, PULSE_COUNTER_PARAMETER_LENGTH, AMOUNT_OF_PULSE_COUNTERS, only_integer_at_index);
			break;
		case 3:
			status = set_parameters(program_parameters, title_3, MRAC_CONTROLLER_PARAMETER_LENGTH, AMOUNT_OF_MRAC_CONTROLLERS, only_integer_at_index);
			break;
		case 4:
			status = set_parameters(program_parameters, title_4, ON_OFF_CONTROLLER_PARAMETER_LENGTH, AMOUNT_OF_ON_OFF_CONTROLLERS, only_integer_at_index);
			break;
		case 9:
			only_integer_at_index[0] = true;
			status = set_parameters(program_parameters, title_9, GENERAL_PURPOSE_VALVE_CONTROL_PARAMETER_LENGTH, AMOUNT_OF_GENERAL_PURPOSE_VALVE_CONTROL, only_integer_at_index);
			break;
		}

		/* Check status */
		if(status == 1){
			/* Success: Save parameters at program number */
			char filename[20];
			sprintf(filename, "PROGRAM%i.TXT", program_number);
			sprintf(text, "%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f%s%f",
					program_parameters[0], DELIMITER,
					program_parameters[1], DELIMITER,
					program_parameters[2], DELIMITER,
					program_parameters[3], DELIMITER,
					program_parameters[4], DELIMITER,
					program_parameters[5], DELIMITER,
					program_parameters[6], DELIMITER,
					program_parameters[7], DELIMITER,
					program_parameters[8], DELIMITER,
					program_parameters[9], DELIMITER,
					program_parameters[10], DELIMITER,
					program_parameters[11], DELIMITER,
					program_parameters[12], DELIMITER,
					program_parameters[13], DELIMITER,
					program_parameters[14], DELIMITER,
					program_parameters[15], DELIMITER,
					program_parameters[16], DELIMITER,
					program_parameters[17], DELIMITER,
					program_parameters[18], DELIMITER,
					program_parameters[19]);
			STM32_PLC_SD_Create_New_File_With_Read_Write(filename, text, true);	/* true means that it creates an initial string */
		}
	}

	/* Exit */
	STM32_PLC_SD_Unmount_Card();
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}

void STM32_PLC_LCD_Execute_Control_Program(J1939 *j1939) {
	/* If Digital input 0 is true, we cannot perform any control - Safety */
	if(STM32_PLC_Digital_Input_Get_Stop()){
		STM32_PLC_PWM_Reset();
		STM32_PLC_Analog_Output_Reset();
		return;
	}

	/* Perform simple control - See above */
	switch (prg) {
	case 1:
		/* PI-Control */
		for(uint8_t i = 0; i < AMOUNT_OF_PI_CONTROLLERS; i++){
			/* Variables */
			float setpoint = program_parameters[0 + i*PI_CONTROLLER_PARAMETER_LENGTH];
			float proportional_gain = program_parameters[1 + i*PI_CONTROLLER_PARAMETER_LENGTH];
			float integral_gain = program_parameters[2 + i*PI_CONTROLLER_PARAMETER_LENGTH];
			bool anti_windup_enabled = program_parameters[3 + i*PI_CONTROLLER_PARAMETER_LENGTH] > 0.9f ? true : false; /* 0.9 because float 1.0 is not always 1.0 */
			float input = STM32_PLC_Analog_Input_ADC_Get(i);
			/* Logic */
			float error = setpoint - input;
			PI_I[i] += integral_gain*error;
			float output = proportional_gain*error + PI_I[i];
			uint16_t ON_Period;
			if(output >= 0xFFFF)
				ON_Period = 0xFFFF;
			else if(output <= 0)
				ON_Period = 0;
			else
				ON_Period = (uint16_t)output;
			STM32_PLC_PWM_Set(i, ON_Period);
			STM32_PLC_Analog_Output_Set(i, ON_Period/16); /* Down scale 16-bit to 12-bit */
			/* Anti-winup */
			if(anti_windup_enabled && error <= 0)
				PI_I[i] = 0;
		}
		break;
	case 2:
		/* Pulse Count */
		for(uint8_t i = 0; i < AMOUNT_OF_PULSE_COUNTERS; i++) {
			/* Variables */
			float high_threshold = program_parameters[0 + i*PULSE_COUNTER_PARAMETER_LENGTH];
			float low_threshold = program_parameters[1 + i*PULSE_COUNTER_PARAMETER_LENGTH];
			float input = STM32_PLC_Analog_Input_ADC_Get(i);
			bool start = STM32_PLC_Digital_Input_Get(i);
			/* Logic */
			if(input > high_threshold){
				STM32_PLC_PWM_Set(i, 0);
				STM32_PLC_Pulse_Count_Set(i);
			}
			if(input <= low_threshold || start){
				STM32_PLC_PWM_Set(i, 0xFFFF);
			}
		}
		break;
	case 3:
		/* MRAC control */
		for(uint8_t i = 0; i < AMOUNT_OF_MRAC_CONTROLLERS; i++) {
			/* Variables */
			float setpoint = program_parameters[0 + i*MRAC_CONTROLLER_PARAMETER_LENGTH];
			float integral_gain = program_parameters[1 + i*MRAC_CONTROLLER_PARAMETER_LENGTH];
			float input = STM32_PLC_Analog_Input_ADC_Get(i);
			/* Logic */
			float error = setpoint - input;
			MRAC_I1[i] -= integral_gain*setpoint*error;
			MRAC_I2[i] += integral_gain*input*error;
			float output = setpoint*MRAC_I1[i] - input*MRAC_I2[i];
			uint16_t ON_Period;
			if(output >= 0xFFFF)
				ON_Period = 0xFFFF;
			else if(output <= 0)
				ON_Period = 0;
			else
				ON_Period = (uint16_t)output;
			STM32_PLC_PWM_Set(i, ON_Period);
			STM32_PLC_Analog_Output_Set(i, ON_Period/16); /* Down scale 16-bit to 12-bit */
		}
		break;
	case 4:
		/* ON/OFF control */
		for(uint8_t i = 0; i < AMOUNT_OF_ON_OFF_CONTROLLERS; i++){
			/* Variables */
			uint16_t input = STM32_PLC_Analog_Input_ADC_Get(i);
			float high_threshold = program_parameters[i];
			/* Logic */
			if(input >= high_threshold)
				STM32_PLC_PWM_Set(i, 0xFFFF);
			else
				STM32_PLC_PWM_Set(i, 0);
		}
		break;
	case 5:
		/* Input output PWM */
		for(uint8_t i = 0; i < AMOUNT_OF_INPUT_OUTPUT_PWM; i++){
			/* Variables */
			bool single_operation = STM32_PLC_Digital_Input_Get(i);
			uint16_t input = STM32_PLC_Analog_Input_ADC_Get_Raw(i);
			/* Logic */
			if(single_operation){
				STM32_PLC_PWM_Set(i, input);              /* 0% - 100 % */
			}else{
				/* Controlling with two PWM with different periods */
				STM32_PLC_PWM_Set(i+i, 0x8000 - input/2);   /* 50 - 0% */
				STM32_PLC_PWM_Set(i+i+1, 0x8000 + input/2); /* 50% - 100% */
			}
		}
		break;
	case 6:
		/* Input output analog */
		for(uint8_t i = 0; i < AMOUNT_OF_INPUT_OUTPUT_ANALOG; i++){
			/* Variables */
			uint16_t input = STM32_PLC_Analog_Input_ADC_Get_Raw(i);
			/* Logic */
			STM32_PLC_Analog_Output_Set(i, input/16);	/* Down scale 16-bit to 12-bit */
		}
		break;
	case 7:
		; /* This ; is necessary, because we need to tell the C language that after a label (case 7:), there is a statement */
		/* Digital output alarm */
		uint8_t minutes, hours, date, week_day; /* We don't need to use these variables in the control program */
		bool alarm_A_active = STM32_PLC_RTC_Get_AlarmAB(RTC_ALARM_A, &minutes, &hours, &date, &week_day);
		bool alarm_B_active = STM32_PLC_RTC_Get_AlarmAB(RTC_ALARM_B, &minutes, &hours, &date, &week_day);
		if(alarm_A_active){
			STM32_PLC_PWM_Set(0, 0xFFFF); /* PWM0 100% */
			STM32_PLC_PWM_Set(1, 0);      /* PWM1 0% */
		}else{
			STM32_PLC_PWM_Set(0, 0);      /* PWM0 0% */
			STM32_PLC_PWM_Set(1, 0xFFFF); /* PWM1 100% */
		}
		if(alarm_B_active){
			STM32_PLC_PWM_Set(2, 0xFFFF); /* PWM2 100% */
			STM32_PLC_PWM_Set(3, 0);      /* PWM3 0% */
		}else{
			STM32_PLC_PWM_Set(2, 0);      /* PWM2 0% */
			STM32_PLC_PWM_Set(3, 0xFFFF); /* PWM3 100% */
		}
		break;
	case 8:
		/* Auxiliary Valve Command - ISO 11783-7 */
		for(uint8_t i = 0; i < AMOUNT_OF_AUXILIARY_VALVE_CONTROL; i++){
			/* Variables */
			uint16_t input = STM32_PLC_Analog_Input_ADC_Get_Raw(i);
			bool digital = STM32_PLC_Digital_Input_Get(i);
			/* Logic */
			uint8_t standard_flow = input/257; /* Down scale 16-bit to 8-bit */
			uint8_t valve_number = i;
			uint8_t fail_safe_mode = FAIL_SAFE_MODE_BLOCKED; /* Not activated */
			uint8_t valve_state = digital;
			ISO_11783_Send_Auxiliary_Valve_Command(j1939, valve_number, standard_flow, fail_safe_mode, valve_state);
		}
		break;
	case 9:
		/* General Purpose Valve Command - ISO 11783-7 */
		for(uint8_t i = 0; i < AMOUNT_OF_GENERAL_PURPOSE_VALVE_CONTROL; i++){
			/* Variables */
			uint16_t input = STM32_PLC_Analog_Input_ADC_Get_Raw(i);
			bool DI = STM32_PLC_Digital_Input_Get(i);
			/* Logic */
			uint8_t standard_flow = 0; /* Not used */
			uint8_t DA = (uint8_t) (program_parameters[i] + 0.1f); /* Destination address. DA will always be an integer e.g 199.9999 will be 200 */
			uint8_t fail_safe_mode = FAIL_SAFE_MODE_BLOCKED; /* Not activated */
			uint8_t valve_state = DI;
			uint16_t extended_flow = (uint16_t)input;		/* High precision command */
			ISO_11783_Send_General_Purpose_Valve_Command(j1939, DA, standard_flow, fail_safe_mode, valve_state, extended_flow);
		}
		break;
	default:
		break;
	}
}

static uint8_t set_parameters(float parameters[], char title[][60], uint8_t index_title, uint8_t amount_of_controllers, bool only_integer_at_index[]) {
	bool minusbutton_show = true;
	bool decimalbutton_show = true;
	float number_value;
	for(uint8_t i = 0; i < amount_of_controllers; i++) {
		for(uint8_t j = 0; i < index_title; j++){
			/* Ask the user about parameters */
			char text[60];
			sprintf(text, title[j], i);
			if(only_integer_at_index[j]){
				minusbutton_show = false;
				decimalbutton_show = false;
			}else{
				minusbutton_show = true;
				decimalbutton_show = true;
			}
			if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, text) == 0) {
				return 0;
			}
			parameters[i*index_title + j] = number_value;
		}
	}
	return 1;
}
