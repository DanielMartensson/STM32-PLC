/*
 * Question_dialog_yes_no.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"

uint8_t STM32_PLC_LCD_Show_Question_Yes_No_Dialog(char question[]) {
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
	ILI9341_print_text("Question", 115, 88, COLOR_BLACK, COLOR_BLUE, 2);
	ILI9341_print_text(question, 50, 110, COLOR_BLACK, COLOR_WHITE, 1);

	/* Yes button */
	ILI9341_fill_rect(120, 129, 160, 150, COLOR_LGRAY);
	ILI9341_hollow_rect(120, 129, 160, 150, COLOR_BLACK);
	ILI9341_print_text("Yes", 122, 132, COLOR_BLACK, COLOR_LGRAY, 2);

	/* No button */
	ILI9341_fill_rect(168, 129, 208, 150, COLOR_LGRAY);
	ILI9341_hollow_rect(168, 129, 208, 150, COLOR_BLACK);
	ILI9341_print_text("No", 176, 132, COLOR_BLACK, COLOR_LGRAY, 2);

	/* Logic */
	uint8_t b1_x1 = 120;
	uint8_t b1_y1 = 129;
	uint8_t b1_x2 = 160;
	uint8_t b1_y2 = 150;
	uint8_t b2_x1 = 168;
	uint8_t b2_y1 = 129;
	uint8_t b2_x2 = 208;
	uint8_t b2_y2 = 150;
	return STM32_PLC_LCD_Call_Two_Button_Logic(b1_x1, b1_y1, b1_x2, b1_y2, b2_x1, b2_y1, b2_x2, b2_y2);
}
