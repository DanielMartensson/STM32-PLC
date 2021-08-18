/*
 * One_button_logic.c
 *
 *  Created on: 24 juli 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"

uint8_t STM32_PLC_LCD_Call_One_Button_Logic(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
	while (1) {
		if (TSC2046_isPressed()) {
			TSC2046_GetTouchData();
			uint16_t X = lcd.myTsData.X;
			uint16_t Y = lcd.myTsData.Y;
			if (X >= x1 && X <= x2 && Y >= y1 && Y <= y2) {
				ILI9341_hollow_rect(x1, y1, x2, y2, COLOR_MAGENTA);
				return 1; /* Button 1 */
			}
		}
	}
}
