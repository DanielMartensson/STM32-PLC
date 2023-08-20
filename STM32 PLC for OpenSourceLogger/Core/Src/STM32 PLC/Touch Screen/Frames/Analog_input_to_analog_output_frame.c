/*
 * Measurement_and_time_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"
#include <math.h>

static void add_spaces(uint8_t length, char text[]);

void STM32_PLC_LCD_Show_Analog_Input_To_Analog_Output_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("ADC0 to ADC2 to DAC0 to DAC2", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Explain */
	ILI9341_print_text("Give ADC0 to ADC2 current", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("and DAC0 to DAC2 will give", 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("out 0-20.625mA current. 4095 = 20.625mA", 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Give power supply 24V. Don't forget GND!", 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Exit button */
	ILI9341_fill_rect(85, 205, 273, 230, COLOR_GREEN);
	ILI9341_hollow_rect(85, 205, 273, 230, COLOR_BLACK);
	ILI9341_print_text("Exit frame now", 95, 210, COLOR_BLACK, COLOR_GREEN, 2);

	while(1) {
		int16_t adc[3];
		/* Control the DAC */
		for(uint8_t i = 0; i < 3; i++){
			float dac = 4095.0f / 65535.0f * ((float)STM32_PLC_Analog_Input_ADC_Get_Raw(i));
			adc[i] = dac;
			STM32_PLC_Analog_Output_Set(i, dac);
		}

		/* ADC 0 to ADC 2 */
		char text[60];
		sprintf(text, "ADC0:%i ADC1:%i ADC2:%i", adc[0], adc[1], adc[2]);
		add_spaces(43, text);
		ILI9341_print_text(text, 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);

		/* Logic for button */
		if (TSC2046_isPressed()) {
			TSC2046_GetTouchData();
			uint16_t X = lcd.myTsData.X;
			uint16_t Y = lcd.myTsData.Y;
			if (X >= 85 && X <= 273 && Y >= 205 && Y <= 230) {
				ILI9341_hollow_rect(85, 205, 273, 230, COLOR_MAGENTA);
				break;
			}
		}
	}

	/* Close the DAC */
	STM32_PLC_Analog_Output_Reset();

	/* Exit */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}

static void add_spaces(uint8_t length, char text[]){
	/* This is for removing old values from LCD */
	for(uint8_t i = strlen(text); i < length; i++)
		text[i] = ' ';
	text[length] = '\0'; /* C-String termination */
}
