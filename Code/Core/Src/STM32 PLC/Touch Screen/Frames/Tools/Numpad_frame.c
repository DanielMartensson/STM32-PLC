/*
 * Numpad_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"

uint8_t STM32_PLC_LCD_Show_Numpad_Frame(bool decimalbutton_show, bool minusbutton_show, float *number_value, char title[]) {
	/* Begin with black page */
	ILI9341_fill_screen(COLOR_BLACK);

	/* Print frame - large square */
	ILI9341_hollow_rect(5, 5, 315, 235, COLOR_GREEN);

	/* Create gray, white square */
	ILI9341_fill_rect(6, 6, 314, 55, COLOR_DGRAY);
	ILI9341_fill_rect(12, 24, 308, 50, COLOR_WHITE);

	/* Set title */
	ILI9341_print_text(title, 12, 12, COLOR_WHITE, COLOR_DGRAY, 1);

	/* Create buttons */
	uint16_t x = 0;
	char number[3];
	for (uint8_t i = 0; i < 5; i++) {
		x += 23;
		/* Upper numbers */
		ILI9341_fill_rect(x, 70, x + 40, 110, COLOR_DGRAY);
		ILI9341_fill_rect(x + 5, 75, x + 35, 105, COLOR_WHITE);
		sprintf(number, "%d", i);
		ILI9341_print_text(number, x + 16, 83, COLOR_BLACK, COLOR_WHITE, 2);

		/* Lower numbers */
		ILI9341_fill_rect(x, 125, x + 40, 165, COLOR_DGRAY);
		ILI9341_fill_rect(x + 5, 130, x + 35, 160, COLOR_WHITE);
		sprintf(number, "%d", i + 5);
		ILI9341_print_text(number, x + 16, 138, COLOR_BLACK, COLOR_WHITE, 2);

		/* This hide or show the buttons */
		if (i == 0 && minusbutton_show == true) {
			ILI9341_fill_rect(x, 180, x + 40, 220, COLOR_DGRAY);
			ILI9341_fill_rect(x + 5, 185, x + 35, 215, COLOR_WHITE);
		} else if (i == 1 && decimalbutton_show == true) {
			ILI9341_fill_rect(x, 180, x + 40, 220, COLOR_DGRAY);
			ILI9341_fill_rect(x + 5, 185, x + 35, 215, COLOR_WHITE);
		}

		/* This show the <- and OK buttons */
		if (i > 1) {
			ILI9341_fill_rect(x, 180, x + 40, 220, COLOR_DGRAY);
			ILI9341_fill_rect(x + 5, 185, x + 35, 215, COLOR_WHITE);
		}

		/* Give the buttons a text */
		if (i == 0 && minusbutton_show == true) {
			ILI9341_print_text("-", x + 15, 193, COLOR_BLACK, COLOR_WHITE, 2);
		} else if (i == 1 && decimalbutton_show == true) {
			ILI9341_print_text(".", x + 15, 193, COLOR_BLACK, COLOR_WHITE, 2);
		} else if (i == 2) {
			ILI9341_print_text("C", x + 15, 193, COLOR_BLACK, COLOR_WHITE, 2);
		} else if (i == 3) {
			ILI9341_print_text("<-", x + 9, 193, COLOR_BLACK, COLOR_WHITE, 2);
		} else if (i == 4) {
			ILI9341_print_text("OK", x + 9, 193, COLOR_BLACK, COLOR_WHITE, 2);
		}
		x += 35; /* Space between buttons */
	}

	/* Logic */
	*number_value = 0;
	return STM32_PLC_LCD_Call_Numpad_Logic(decimalbutton_show, minusbutton_show, number_value);
}
