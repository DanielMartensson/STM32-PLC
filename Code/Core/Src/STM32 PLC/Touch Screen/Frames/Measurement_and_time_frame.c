/*
 * Measurement_and_time_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

void STM32_PLC_LCD_Show_Measurement_And_Time_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Measurement values and time", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Exit button */
	ILI9341_fill_rect(85, 205, 273, 230, COLOR_GREEN);
	ILI9341_hollow_rect(85, 205, 273, 230, COLOR_BLACK);
	ILI9341_print_text("Exit frame now", 95, 210, COLOR_BLACK, COLOR_GREEN, 2);

	while(1) {
		/* Show the values */
		STM32_PLC_LCD_Show_Plot_Frame();

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

	/* Exit */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}
