/*
 * Numpad_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"

uint8_t STM32_PLC_LCD_Call_Numpad_Logic(bool decimalbutton_show, bool minusbutton_show, float *number_value) {
	bool haveDot = false;
	char text[17] = "";
	uint8_t k = 0;
	while (1) {
		if (TSC2046_isPressed()) {
			TSC2046_GetTouchData();
			uint16_t X = lcd.myTsData.X;
			uint16_t Y = lcd.myTsData.Y;
			if (X >= 23 && X <= 63 && Y >= 70 && Y <= 110) {
				/* 0 */
				if (k >= 0 && k < 16) {
					text[k] = '0';
					k++;
				}
			} else if (X >= 81 && X <= 121 && Y >= 70 && Y <= 110) {
				/* 1 */
				if (k < 16) {
					text[k] = '1';
					k++;
				}
			} else if (X >= 139 && X <= 179 && Y >= 70 && Y <= 110) {
				/* 2 */
				if (k < 16) {
					text[k] = '2';
					k++;
				}
			} else if (X >= 197 && X <= 237 && Y >= 70 && Y <= 110) {
				/* 3 */
				if (k < 16) {
					text[k] = '3';
					k++;
				}
			} else if (X >= 255 && X <= 295 && Y >= 70 && Y <= 110) {
				/* 4 */
				if (k < 16) {
					text[k] = '4';
					k++;
				}
			} else if (X >= 23 && X <= 63 && Y >= 125 && Y <= 165) {
				/* 5 */
				if (k < 16) {
					text[k] = '5';
					k++;
				}
			} else if (X >= 81 && X <= 121 && Y >= 125 && Y <= 165) {
				/* 6 */
				if (k < 16) {
					text[k] = '6';
					k++;
				}
			} else if (X >= 139 && X <= 179 && Y >= 125 && Y <= 165) {
				/* 7 */
				if (k < 16) {
					text[k] = '7';
					k++;
				}
			} else if (X >= 197 && X <= 237 && Y >= 125 && Y <= 165) {
				/* 8 */
				if (k < 16) {
					text[k] = '8';
					k++;
				}
			} else if (X >= 255 && X <= 295 && Y >= 125 && Y <= 165) {
				/* 9 */
				if (k < 16) {
					text[k] = '9';
					k++;
				}
			} else if (X >= 23 && X <= 63 && Y >= 180 && Y <= 220) {
				/* - */
				if (minusbutton_show == true && k == 0) {
					text[k] = '-';
					k++;
				}
			} else if (X >= 81 && X <= 121 && Y >= 180 && Y <= 220) {
				/* . */
				if (decimalbutton_show == true && k > 0 && haveDot == false && k < 16) {
					text[k] = '.';
					k++;
					haveDot = true;
				}
			} else if (X >= 139 && X <= 179 && Y >= 180 && Y <= 220) {
				/* C */
				memset(text, 0, sizeof(text));
				k = 0;
				haveDot = false;
				ILI9341_fill_rect(12, 24, 308, 50, COLOR_WHITE); /* Clear white space above */
			} else if (X >= 197 && X <= 237 && Y >= 180 && Y <= 220) {
				/* <- */
				return 0;
			} else if (X >= 255 && X <= 295 && Y >= 180 && Y <= 220) {
				/* OK */
				*number_value = atoff(text);
				return 1;
			}
			/* Display the selected number text */
			ILI9341_print_text(text, 15, 25, COLOR_BLACK, COLOR_WHITE, 3);
		}
	}
}
