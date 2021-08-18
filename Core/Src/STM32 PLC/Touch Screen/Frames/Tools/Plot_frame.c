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
	sprintf(text, "ADC0:%0.2f ADC1:%0.2f ADC2:%0.2f", STM32_PLC_Analog_Input_ADC_Get(0), STM32_PLC_Analog_Input_ADC_Get(1), STM32_PLC_Analog_Input_ADC_Get(2));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);

	/* ADC3 to ADC5 */
	sprintf(text, "ADC3:%0.2f ADC4:%0.2f ADC5:%0.2f", STM32_PLC_Analog_Input_ADC_Get(3), STM32_PLC_Analog_Input_ADC_Get(4), STM32_PLC_Analog_Input_ADC_Get(5));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);

	/* ADC6 to ADC8 */
	sprintf(text, "ADC6:%0.2f ADC5:%0.2f ADC8:%0.2f", STM32_PLC_Analog_Input_ADC_Get(6), STM32_PLC_Analog_Input_ADC_Get(5), STM32_PLC_Analog_Input_ADC_Get(8));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);

	/* ADC9 to ADC11 */
	sprintf(text, "ADC9:%0.2f ADC10:%0.2f ADC11:%0.2f", STM32_PLC_Analog_Input_ADC_Get(9), STM32_PLC_Analog_Input_ADC_Get(10), STM32_PLC_Analog_Input_ADC_Get(11));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);

	/* DADC0 to DADC2 */
	sprintf(text, "DADC0:%0.2f DADC1:%0.2f DADC2:%0.2f", STM32_PLC_Analog_Input_DADC_Get(0), STM32_PLC_Analog_Input_DADC_Get(1), STM32_PLC_Analog_Input_DADC_Get(2));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);

	/* DADC3 to DADC4 */
	sprintf(text, "DADC3:%0.2f DADC4:%0.2f", STM32_PLC_Analog_Input_DADC_Get(3), STM32_PLC_Analog_Input_DADC_Get(4));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);

	/* DI0 to DI3 */
	sprintf(text, "DI0:%i DI1:%i DI2:%i DI3:%i", STM32_PLC_Digital_Input_Get(0), STM32_PLC_Digital_Input_Get(1), STM32_PLC_Digital_Input_Get(2), STM32_PLC_Digital_Input_Get(3));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);

	/* DI4 to DI7 */
	sprintf(text, "DI4:%i DI5:%i DI6:%i DI7:%i", STM32_PLC_Digital_Input_Get(4), STM32_PLC_Digital_Input_Get(5), STM32_PLC_Digital_Input_Get(6), STM32_PLC_Digital_Input_Get(7));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);

	/* E0 to E1 */
	sprintf(text, "E0:%f E1:%f", STM32_PLC_Encoder_Get(0), STM32_PLC_Encoder_Get(1));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 115, COLOR_YELLOW, COLOR_NAVY, 1);

	/* IC0 to IC2 */
	sprintf(text, "IC0:%f IC1:%f", STM32_PLC_Input_Capture_Get(0), STM32_PLC_Input_Capture_Get(1));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 125, COLOR_YELLOW, COLOR_NAVY, 1);

	/* DAC0 to DAC2 */
	sprintf(text, "DAC0:%i DAC1:%i DAC2:%i", STM32_PLC_Analog_Output_Get(0), STM32_PLC_Analog_Output_Get(1), STM32_PLC_Analog_Output_Get(2));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 135, COLOR_YELLOW, COLOR_NAVY, 1);

	/* PWM0 to PWM3 */
	sprintf(text, "PWM0:%i PWM1:%i PWM2:%i PWM3:%i", STM32_PLC_PWM_Get(0), STM32_PLC_PWM_Get(1), STM32_PLC_PWM_Get(2), STM32_PLC_PWM_Get(3));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 145, COLOR_YELLOW, COLOR_NAVY, 1);

	/* PWM4 to PWM7 */
	sprintf(text, "PWM4:%i PWM5:%i PWM6:%i PWM7:%i", STM32_PLC_PWM_Get(4), STM32_PLC_PWM_Get(5), STM32_PLC_PWM_Get(6), STM32_PLC_PWM_Get(7));
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 155, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Display date & time */
	uint8_t date;
	uint8_t month;
	uint8_t year;
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	STM32_PLC_RTC_Get_Time(&seconds, &minutes, &hours);
	STM32_PLC_RTC_Get_Date(&date, &month, &year);
	sprintf(text, "Date:%i-%i-%i Time:%i:%i:%i", 2000 + year, month, date, hours, minutes, seconds);
	add_spaces(43, text);
	ILI9341_print_text(text, 55, 165, COLOR_YELLOW, COLOR_NAVY, 1);
}

static void add_spaces(uint8_t length, char text[]){
	/* This is for removing old values from LCD */
	for(uint8_t i = strlen(text); i < length; i++)
		text[i] = ' ';
	text[length] = '\0';
}
