/*
 * Information_ok_dialog.c
 *
 *  Created on: 24 juli 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"

uint8_t STM32_PLC_LCD_Show_Information_OK_Dialog(char information[]) {
	ILI9341_set_rotation(2);

	/* Big blue frame */
	ILI9341_fill_rect(40, 80, 290, 160, COLOR_BLUE);
	ILI9341_hollow_rect(40, 80, 290, 160, COLOR_BLACK);

	/* White big frame */
	ILI9341_fill_rect(42, 82, 288, 158, COLOR_WHITE);
	ILI9341_hollow_rect(42, 82, 288, 158, COLOR_BLACK);

	/* Small question background frame */
	ILI9341_fill_rect(45, 85, 285, 106, COLOR_BLUE);
	ILI9341_hollow_rect(45, 85, 285, 106, COLOR_BLACK);

	/* Text */
	ILI9341_print_text("Information", 105, 88, COLOR_BLACK, COLOR_BLUE, 2);
	ILI9341_print_text(information, 50, 110, COLOR_BLACK, COLOR_WHITE, 1);

	/* OK button */
	ILI9341_fill_rect(145, 129, 180, 150, COLOR_LGRAY);
	ILI9341_hollow_rect(145, 129, 180, 150, COLOR_BLACK);
	ILI9341_print_text("OK", 152, 132, COLOR_BLACK, COLOR_LGRAY, 2);

	/* Logic */
	return STM32_PLC_LCD_Call_One_Button_Logic(145, 129, 180, 150);
}
