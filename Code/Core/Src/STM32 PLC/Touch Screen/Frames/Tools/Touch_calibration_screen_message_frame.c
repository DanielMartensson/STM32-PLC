/*
 * Touch_calibration_screen_message_frame.c
 *
 *  Created on: May 24, 2022
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"

void STM32_PLC_LCD_Show_Touch_Screen_Calibration_Message_Frame() {
	ILI9341_set_rotation(2);
	ILI9341_fill_screen(COLOR_WHITE);
	ILI9341_print_text("Hold screen for calibration", 80, 120, COLOR_BLACK, COLOR_WHITE, 1);
}


