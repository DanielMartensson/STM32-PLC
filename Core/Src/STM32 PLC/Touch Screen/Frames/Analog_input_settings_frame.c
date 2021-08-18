/*
 * Analog_input_settings_frame.c
 *
 *  Created on: 25 juli 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

void STM32_PLC_LCD_Show_Analog_Calibration_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Set analog calibration for input 0 to 16", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Values order:Min Max Bias", 55, 20, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Read */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Read("ANALOG.TXT");
	char text[500];
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();

	/* Collect analog values */
	char delimiters[4];
	sprintf(delimiters, "%s,", DELIMITER); /* Multiple delimiter */
	float min_max_bias[3*17]; /* 3 values per each analog input channel and we have 17 input channels */
	char line_text[50]; /* We cannot use text array here - It will give hardfault */
	uint16_t y = 25;
	for(uint8_t i = 0; i < 17; i++) {
		if(i == 0){
			min_max_bias[0 + 3*i] = atoff(strtok(text, delimiters));
			min_max_bias[1 + 3*i] = atoff(strtok(NULL, delimiters));
			min_max_bias[2 + 3*i] = atoff(strtok(NULL, delimiters));
		} else {
			min_max_bias[0 + 3*i] = atoff(strtok(NULL, delimiters));
			min_max_bias[1 + 3*i] = atoff(strtok(NULL, delimiters));
			min_max_bias[2 + 3*i] = atoff(strtok(NULL, delimiters));
		}
		if(i <= 11){
			sprintf(line_text, "%i=ADC%i:%0.2f %0.2f %0.2f", i, i, min_max_bias[0 + i*3], min_max_bias[1 + i*3], min_max_bias[2 + i*3]);
			ILI9341_print_text(line_text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
		}else{
			sprintf(line_text, "%i=DADC%i:%0.2f %0.2f %0.2f", i, i-12, min_max_bias[0 + i*3], min_max_bias[1 + i*3], min_max_bias[2 + i*3]);
			ILI9341_print_text(line_text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
		}
	}

	/* Select settings button */
	ILI9341_fill_rect(85, 205, 273, 230, COLOR_GREEN);
	ILI9341_hollow_rect(85, 205, 273, 230, COLOR_BLACK);
	ILI9341_print_text("Select setting", 95, 210, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for request button */
	STM32_PLC_LCD_Call_One_Button_Logic(85, 205, 273, 230);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to change settings?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* You entered choice 1 - Show numpad */
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value = 0;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter input number between 0 and 16") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint8_t analog_input_index;
	if(number_value < 0)
		analog_input_index = 0;
	else if(number_value > 16)
		analog_input_index = 16;
	else
		analog_input_index = (uint8_t) number_value;

	/* We need to have decimal and minus button active */
	decimalbutton_show = true;
	minusbutton_show = true;

	/* Ask for min value */
	number_value = 0;
	if(analog_input_index <= 11)
		sprintf(text, "Enter min value for ADC%i", analog_input_index);
	else
		sprintf(text, "Enter min value for DADC%i", analog_input_index-12);
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, text) == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	float min_value = number_value;

	/* Ask for max value */
	number_value = 0;
	if(analog_input_index <= 11)
		sprintf(text, "Enter max value for ADC%i", analog_input_index);
	else
		sprintf(text, "Enter max value for DADC%i", analog_input_index-12);
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, text) == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	float max_value = number_value;

	/* Ask for bias value */
	number_value = 0;
	if(analog_input_index <= 11)
		sprintf(text, "Enter bias value for ADC%i", analog_input_index);
	else
		sprintf(text, "Enter bias value for DADC%i", analog_input_index-12);
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, text) == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	float bias_value = number_value;

	/* Apply them */
	if(analog_input_index <= 11)
		STM32_PLC_Analog_Input_ADC_Set_Calibration(analog_input_index, min_value, max_value, bias_value);
	else if (analog_input_index >= 12 && analog_input_index <= 16)
		STM32_PLC_Analog_Input_DADC_Set_Calibration(analog_input_index - 12, min_value, max_value, bias_value);

	/* Overwrite */
	for(uint8_t i = 0; i < 17; i++) {
		if(analog_input_index == i){
			min_max_bias[0 + i*3] = min_value;
			min_max_bias[1 + i*3] = max_value;
			min_max_bias[2 + i*3] = bias_value;
		}
	}

	/* Write */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Write("ANALOG.TXT");
	for(uint8_t i = 0; i < 17; i++) {
		if(i <= 15)
			sprintf(text, "%0.2f,%0.2f,%0.2f%s", min_max_bias[0 + 3*i], min_max_bias[1 + 3*i], min_max_bias[2 + 3*i], DELIMITER);
		else
			sprintf(text, "%0.2f,%0.2f,%0.2f", min_max_bias[0 + 3*i], min_max_bias[1 + 3*i], min_max_bias[2 + 3*i]);
		STM32_PLC_SD_Write_File(text);
	}

	/* Exit */
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);

}
