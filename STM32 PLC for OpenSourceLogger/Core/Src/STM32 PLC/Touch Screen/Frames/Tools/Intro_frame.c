/*
 * Intro_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"

void STM32_PLC_LCD_Show_Intro_Frame() {
	ILI9341_set_rotation(2);
	ILI9341_fill_screen(COLOR_WHITE);

	/* Do the 80's style introduction */
	uint16_t colors[7] = {(uint16_t) COLOR_RED, (uint16_t) COLOR_GREEN, (uint16_t) COLOR_CYAN, (uint16_t) COLOR_BLUE, (uint16_t) COLOR_MAGENTA, (uint16_t) COLOR_NAVY, (uint16_t) COLOR_ORANGE };
	for (uint8_t i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
		uint16_t x0 = 10 * (i + 1);
		uint16_t y0 = 10 * (i + 1);
		uint16_t x1 = ILI9341_HEIGHT - 19 * (i + 1);
		uint16_t y1 = ILI9341_WIDTH - 19 * (i + 1);
		ILI9341_fill_rect(x0, y0, x1, y1, colors[i]);
		ILI9341_hollow_rect(x0, y0, x1, y1, COLOR_BLACK);
	}
	ILI9341_print_text("STM32 PLC", 74, 80, COLOR_BLACK, COLOR_ORANGE, 2);
	HAL_Delay(1000);
}

