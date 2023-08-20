/*
 * Two_button_logic.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"

uint8_t STM32_PLC_LCD_Call_Two_Button_Logic(uint16_t b1_x1, uint16_t b1_y1, uint16_t b1_x2, uint16_t b1_y2, uint16_t b2_x1, uint16_t b2_y1, uint16_t b2_x2, uint16_t b2_y2) {
	while (1) {
		if (TSC2046_isPressed()) {
			TSC2046_GetTouchData();
			uint16_t X = lcd.myTsData.X;
			uint16_t Y = lcd.myTsData.Y;
			if (X >= b1_x1 && X <= b1_x2 && Y >= b1_y1 && Y <= b1_y2) {
				ILI9341_hollow_rect(b1_x1, b1_y1, b1_x2, b1_y2, COLOR_MAGENTA);
				return 1; /* Button 1 */
			} else if (X >= b2_x1 && X <= b2_x2 && Y >= b2_y1 && Y <= b2_y2) {
				ILI9341_hollow_rect(b2_x1, b2_y1, b2_x2, b2_y2, COLOR_MAGENTA);
				return 0; /* Button 2 */
			}
		}
	}
}
