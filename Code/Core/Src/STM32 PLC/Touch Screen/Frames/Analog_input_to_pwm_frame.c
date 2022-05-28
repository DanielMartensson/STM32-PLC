/*
 * Measurement_and_time_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

static void add_spaces(uint8_t length, char text[]);

void STM32_PLC_LCD_Show_Analog_Input_To_PWM_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("ADC0 to ADC7 to PWM0 to PWM7", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Explain */
	ILI9341_print_text("Give ADC0 to ADC7 current", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("and PWM0 to PWM8 will open drain", 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("the PWM inputs for 0 to 2.2A", 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("65535 = 100% PWM", 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("0 = 0% PWM", 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Set PWM prescaler for other PWM Hz", 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Exit button */
	ILI9341_fill_rect(85, 205, 273, 230, COLOR_GREEN);
	ILI9341_hollow_rect(85, 205, 273, 230, COLOR_BLACK);
	ILI9341_print_text("Exit frame now", 95, 210, COLOR_BLACK, COLOR_GREEN, 2);

	while(1) {
		uint16_t pwm[8];
		for(uint8_t i = 0; i < 8; i++)
			pwm[i] = STM32_PLC_Analog_Input_ADC_Get_Raw(i);

		/* ADC 0 to ADC 2 */
		char text[60];
		sprintf(text, "ADC0:%i ADC1:%i ADC2:%i", pwm[0], pwm[1], pwm[2]);
		add_spaces(43, text);
		ILI9341_print_text(text, 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);

		/* ADC3 to ADC5 */
		sprintf(text, "ADC3:%i ADC4:%i ADC5:%i", pwm[3], pwm[4], pwm[5]);
		add_spaces(43, text);
		ILI9341_print_text(text, 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);

		/* ADC6 to ADC8 */
		sprintf(text, "ADC6:%i ADC7:%i", pwm[6], pwm[7]);
		add_spaces(43, text);
		ILI9341_print_text(text, 55, 115, COLOR_YELLOW, COLOR_NAVY, 1);

		/* Control the PWM */
		for(uint8_t i = 0; i < 8; i++)
			STM32_PLC_PWM_Set(i, pwm[i]);

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

	/* Close the PWM */
	STM32_PLC_PWM_Reset();

	/* Exit */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}

static void add_spaces(uint8_t length, char text[]){
	/* This is for removing old values from LCD */
	for(uint8_t i = strlen(text); i < length; i++)
		text[i] = ' ';
	text[length] = '\0'; /* C-String termination */
}
