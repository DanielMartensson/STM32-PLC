/*
 * SDADC_settings_frame.c
 *
 *  Created on: 25 juli 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

void STM32_PLC_LCD_Show_SDADC_Settings_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Set gain, offset for input 0 to 16", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Values order:Gain Offset ", 55, 20, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Read */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Read("SDADC.TXT");
	char text[500];
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();

	/* Collect analog values */
	char delimiters[4];
	sprintf(delimiters, "%s,", DELIMITER); /* Multiple delimiter */
	uint16_t gain_offset[2*9]; /* 2 values per each configuration */
	char line_text[50]; /* We cannot use text array here - It will give hardfault */
	uint16_t y = 25;
	for(uint8_t i = 0; i < 9; i++) {
		if(i == 0){
			gain_offset[0 + 2*i] = atoff(strtok(text, delimiters));
			gain_offset[1 + 2*i] = atoff(strtok(NULL, delimiters));
		} else {
			gain_offset[0 + 2*i] = atoff(strtok(NULL, delimiters));
			gain_offset[1 + 2*i] = atoff(strtok(NULL, delimiters));
		}
		if(i <= 2){
			/* This is for SDADC1 */
			sprintf(line_text, "%i=ADC%i,ADC%i,ADC%i:%i %i", i, i+i+i, i+i+i+1, i+i+i+2, gain_offset[0 + 2*i], gain_offset[1 + 2*i]);
			ILI9341_print_text(line_text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
		}else if(i >= 3 && i <= 5){
			/* This is for SDADC2 */
			sprintf(line_text, "%i=ADC%i:%i %i", i, i, gain_offset[0 + 2*i], gain_offset[1 + 2*i]);
			ILI9341_print_text(line_text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
		}else if(i >= 6 && i <= 7){
			/* This is for SDADC3 */
			sprintf(line_text, "%i=DADC%i,DADC%i:%i %i", i, i+i-12, i+i+1-12, gain_offset[0 + 2*i], gain_offset[1 + 2*i]);
			ILI9341_print_text(line_text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
		}else if(i == 8){
			/* This is for SDADC3 - The last */
			sprintf(line_text, "%i=DADC4:%i %i", i, gain_offset[0 + 2*i], gain_offset[1 + 2*i]);
			ILI9341_print_text(line_text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
		}
	}

	/* Print gain values */
	ILI9341_print_text("Gain values from 1/2 to 32:", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("0=1/2,1=1,2=2,3=4,4=8,5=16,6=32", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Offset values are between 0 and 4095", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);

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
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter input number between 0 and 8") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint8_t analog_input_index;
	if(number_value < 0)
		analog_input_index = 0;
	else if(number_value > 8)
		analog_input_index = 8;
	else
		analog_input_index = (uint8_t) number_value;

	/* Ask for gain value */
	number_value = 0;
	switch(analog_input_index){
	case 0:
		sprintf(text, "Enter gain value for ADC0,ADC1,ADC2");
		break;
	case 1:
		sprintf(text, "Enter gain value for ADC3,ADC4,ADC5");
		break;
	case 2:
		sprintf(text, "Enter gain value for ADC6,ADC7,ADC8");
		break;
	case 3:
		sprintf(text, "Enter gain value for ADC9");
		break;
	case 4:
		sprintf(text, "Enter gain value for ADC10");
		break;
	case 5:
		sprintf(text, "Enter gain value for ADC11");
		break;
	case 6:
		sprintf(text, "Enter gain value for DADC0,DADC1");
		break;
	case 7:
		sprintf(text, "Enter gain value for DADC2,DADC3");
		break;
	case 8:
		sprintf(text, "Enter gain value for DADC4");
		break;
	}
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, text) == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	uint8_t gain;
	if(number_value < 0)
		gain = 0;
	else if(number_value > 6)
		gain = 6;
	else
		gain = (uint8_t) number_value;

	/* Ask for offset value */
	number_value = 0;
	switch(analog_input_index){
	case 0:
		sprintf(text, "Enter offset value for ADC0,ADC1,ADC2");
		break;
	case 1:
		sprintf(text, "Enter offset value for ADC3,ADC4,ADC5");
		break;
	case 2:
		sprintf(text, "Enter offset value for ADC6,ADC7,ADC8");
		break;
	case 3:
		sprintf(text, "Enter offset value for ADC9");
		break;
	case 4:
		sprintf(text, "Enter offset value for ADC10");
		break;
	case 5:
		sprintf(text, "Enter offset value for ADC11");
		break;
	case 6:
		sprintf(text, "Enter offset value for DADC0,DADC1");
		break;
	case 7:
		sprintf(text, "Enter offset value for DADC2,DADC3");
		break;
	case 8:
		sprintf(text, "Enter offset value for DADC4");
		break;
	}
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, text) == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	uint16_t offset;
	if(number_value < 0)
		offset = 0;
	else if(number_value > 4095)
		offset = 4905;
	else
		offset = (uint16_t) number_value;

	/* Apply them */
	switch(analog_input_index){
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

	/* Overwrite */
	for(uint8_t i = 0; i < 9; i++) {
		if(analog_input_index == i){
			gain_offset[0 + i*2] = gain;
			gain_offset[1 + i*2] = offset;
		}
	}

	/* Write */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Write("SDADC.TXT");
	for(uint8_t i = 0; i < 9; i++) {
		if(i <= 7)
			sprintf(text, "%i,%i%s", gain_offset[0 + 2*i], gain_offset[1 + 2*i], DELIMITER);
		else
			sprintf(text, "%i,%i", gain_offset[0 + 2*i], gain_offset[1 + 2*i]);
		STM32_PLC_SD_Write_File(text);
	}
	/* Exit */
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);

}
