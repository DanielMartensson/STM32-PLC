/*
 * Numpad_frame.c
 *
 *  Created on: Jul 29, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"

static void shift_keyboard(uint8_t keyboard_page);

uint8_t STM32_PLC_LCD_Call_Keyboard_Logic(char word[]) {
	char text[17] = "";
	uint8_t k = 0;
	uint8_t keyboard_page = 6; /* We start at this */
	while (1) {
		if (TSC2046_isPressed()) {
			TSC2046_GetTouchData();
			uint16_t X = lcd.myTsData.X;
			uint16_t Y = lcd.myTsData.Y;
			if (X >= 23 && X <= 63 && Y >= 70 && Y <= 110) {
				/* 0 */
				if (k >= 0 && k < 16) {
					text[k] = 0 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 81 && X <= 121 && Y >= 70 && Y <= 110) {
				/* 1 */
				if (k < 16) {
					text[k] = 1 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 139 && X <= 179 && Y >= 70 && Y <= 110) {
				/* 2 */
				if (k < 16) {
					text[k] = 2 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 197 && X <= 237 && Y >= 70 && Y <= 110) {
				/* 3 */
				if (k < 16) {
					text[k] = 3 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 255 && X <= 295 && Y >= 70 && Y <= 110) {
				/* 4 */
				if (k < 16) {
					text[k] = 4 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 23 && X <= 63 && Y >= 125 && Y <= 165) {
				/* 5 */
				if (k < 16) {
					text[k] = 0 + 5 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 81 && X <= 121 && Y >= 125 && Y <= 165) {
				/* 6 */
				if (k < 16) {
					text[k] = 1 + 5 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 139 && X <= 179 && Y >= 125 && Y <= 165) {
				/* 7 */
				if (k < 16) {
					text[k] = 2 + 5 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 197 && X <= 237 && Y >= 125 && Y <= 165) {
				/* 8 */
				if (k < 16) {
					text[k] = 3 + 5 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 255 && X <= 295 && Y >= 125 && Y <= 165) {
				/* 9 */
				if (k < 16) {
					text[k] = 4 + 5 + 32 + 5*keyboard_page;
					k++;
				}
			} else if (X >= 23 && X <= 63 && Y >= 180 && Y <= 220) {
				/* < */
				if(keyboard_page > 0){
					keyboard_page--;
					shift_keyboard(keyboard_page);
				}
			} else if (X >= 81 && X <= 121 && Y >= 180 && Y <= 220) {
				/* > */
				if(keyboard_page < 17){
					keyboard_page++;
					shift_keyboard(keyboard_page);
				}
			} else if (X >= 139 && X <= 179 && Y >= 180 && Y <= 220) {
				/* C */
				memset(text, 0, sizeof(text));
				k = 0;
				ILI9341_fill_rect(12, 24, 308, 50, COLOR_WHITE); /* Clear white space above */
			} else if (X >= 197 && X <= 237 && Y >= 180 && Y <= 220) {
				/* <- */
				return 0;
			} else if (X >= 255 && X <= 295 && Y >= 180 && Y <= 220) {
				/* OK */
				memcpy(word, text, 17);
				return 1;
			}
			/* Display the selected number text */
			ILI9341_print_text(text, 15, 25, COLOR_BLACK, COLOR_WHITE, 3);
		}
	}
}

static void shift_keyboard(uint8_t keyboard_page) {
	char letter[2];
	uint16_t x = 0;
	for(uint8_t i = 0; i < 5; i++) {
		/* Jump one step to the left */
		x += 23;

		/* Upper letters */
		sprintf(letter, "%c", i + 32 + 5*keyboard_page);
		ILI9341_print_text(letter, x + 16, 83, COLOR_BLACK, COLOR_WHITE, 2);

		/* Down letter */
		sprintf(letter, "%c", i + 5 + 32 + 5*keyboard_page);
		ILI9341_print_text(letter, x + 16, 138, COLOR_BLACK, COLOR_WHITE, 2);

		/* Jump one step to the left */
		x += 35;
	}
}
