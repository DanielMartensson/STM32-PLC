/*
 * Plot_frame.c
 *
 *  Created on: 1 aug. 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"
#include "../../../Functions.h"

static void add_spaces(uint8_t length, char text[]);

void STM32_PLC_LCD_Show_Plot_Frame() {
	/* ADC 0 to ADC 2 */
	char text[60];
	sprintf(text, "ADC0:%0.2f ADC1:%0.2f ADC2:%0.2f", STM32_PLC_Analog_Input_ADC_Get_Calibrated(0), STM32_PLC_Analog_Input_ADC_Get_Calibrated(1), STM32_PLC_Analog_Input_ADC_Get_Calibrated(2));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);

	/* ADC3 to ADC5 */
	sprintf(text, "ADC3:%0.2f ADC4:%0.2f ADC5:%0.2f", STM32_PLC_Analog_Input_ADC_Get_Calibrated(3), STM32_PLC_Analog_Input_ADC_Get_Calibrated(4), STM32_PLC_Analog_Input_ADC_Get_Calibrated(5));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);

	/* ADC6 to ADC8 */
	sprintf(text, "ADC6:%0.2f ADC7:%0.2f ADC8:%0.2f", STM32_PLC_Analog_Input_ADC_Get_Calibrated(6), STM32_PLC_Analog_Input_ADC_Get_Calibrated(7), STM32_PLC_Analog_Input_ADC_Get_Calibrated(8));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);

	/* ADC9 to ADC11 */
	sprintf(text, "ADC9:%0.2f ADC10:%0.2f ADC11:%0.2f", STM32_PLC_Analog_Input_ADC_Get_Calibrated(9), STM32_PLC_Analog_Input_ADC_Get_Calibrated(10), STM32_PLC_Analog_Input_ADC_Get_Calibrated(11));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);

	/* DADC0 to DADC2 */
	sprintf(text, "DADC0:%0.2f DADC1:%0.2f DADC2:%0.2f", STM32_PLC_Analog_Input_DADC_Get_Calibrated(0), STM32_PLC_Analog_Input_DADC_Get_Calibrated(1), STM32_PLC_Analog_Input_DADC_Get_Calibrated(2));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);

	/* DADC3 to DADC4 */
	sprintf(text, "DADC3:%0.2f DADC4:%0.2f", STM32_PLC_Analog_Input_DADC_Get_Calibrated(3), STM32_PLC_Analog_Input_DADC_Get_Calibrated(4));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);

	/* DI0 to DI4 */
	sprintf(text, "DI0:%i DI1:%i DI2:%i DI3:%i DI4:%i", STM32_PLC_Digital_Input_Get(0), STM32_PLC_Digital_Input_Get(1), STM32_PLC_Digital_Input_Get(2), STM32_PLC_Digital_Input_Get(3), STM32_PLC_Digital_Input_Get(4));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);

	/* DI5 to DI9 */
	sprintf(text, "DI5:%i DI6:%i DI7:%i DI8:%i DI9:%i", STM32_PLC_Digital_Input_Get(5), STM32_PLC_Digital_Input_Get(6), STM32_PLC_Digital_Input_Get(7), STM32_PLC_Digital_Input_Get(8), STM32_PLC_Digital_Input_Get(9));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);

	/* E0 to E2 */
	sprintf(text, "E0:%0.2f E1:%0.2f E2:%0.2f", STM32_PLC_Encoder_Get_Calibrated(0), STM32_PLC_Encoder_Get_Calibrated(1), STM32_PLC_Encoder_Get_Calibrated(2));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 115, COLOR_YELLOW, COLOR_NAVY, 1);

	/* IC0 to IC1 */
	sprintf(text, "IC0:%0.2f IC1:%0.2f", STM32_PLC_Input_Capture_Get_Calibrated(0), STM32_PLC_Input_Capture_Get_Calibrated(1));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 125, COLOR_YELLOW, COLOR_NAVY, 1);

	/* IC2 to IC3 */
	sprintf(text, "IC2:%0.2f IC3:%0.2f", STM32_PLC_Input_Capture_Get_Calibrated(2), STM32_PLC_Input_Capture_Get_Calibrated(3));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 135, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Display date & time */
	uint8_t week_day, date, month, year, seconds, minutes, hours;
	STM32_PLC_RTC_Get_Time(&seconds, &minutes, &hours);
	STM32_PLC_RTC_Get_Date(&week_day, &date, &month, &year);
	sprintf(text, "Date:%i-%i-%i Time:%i:%i:%i", 2000 + year, month, date, hours, minutes, seconds);
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 145, COLOR_YELLOW, COLOR_NAVY, 1);
}

static void add_spaces(uint8_t length, char text[]){
	/* This is for removing old values from LCD */
	for(uint8_t i = strlen(text); i < length; i++)
		text[i] = ' ';
	text[length] = '\0'; /* C-String termination */
}
