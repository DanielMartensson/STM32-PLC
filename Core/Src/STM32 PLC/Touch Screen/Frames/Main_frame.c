/*
 * Main_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"

/* Create the main frame */
void STM32_PLC_LCD_Show_Main_Frame(uint8_t *frame_id, bool change_only_ABC_buttons) {
	/* Set rotation */
	ILI9341_set_rotation(2);

	if(!change_only_ABC_buttons) {
		/* Set background */
		ILI9341_fill_screen(COLOR_NAVY);

		/* Print frame - large square */
		ILI9341_draw_horizontal_line(5, 235, 310, COLOR_GREEN);
		ILI9341_draw_horizontal_line(5, 5, 310, COLOR_GREEN);
		ILI9341_draw_vertical_line(5, 5, 230, COLOR_GREEN);
		ILI9341_draw_vertical_line(315, 5, 230, COLOR_GREEN);

		/* Print buttons - Small squares */
		ILI9341_draw_vertical_line(50, 5, 230, COLOR_GREEN);
		ILI9341_draw_horizontal_line(5, 49, 45, COLOR_GREEN);
		ILI9341_draw_horizontal_line(5, 96, 45, COLOR_GREEN);
		ILI9341_draw_horizontal_line(5, 143, 45, COLOR_GREEN);
		ILI9341_draw_horizontal_line(5, 190, 45, COLOR_GREEN);
		ILI9341_draw_horizontal_line(5, 235, 45, COLOR_GREEN);

		/* This line is for the input and output text */
		ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	}
	/* Apply them */
	char text[40];
	sprintf(text, "%c", 65 + 3 * *frame_id); /* A */
	ILI9341_print_text(text, 18, 13, COLOR_YELLOW, COLOR_NAVY, 4);
	sprintf(text, "%c", 66 + 3 * *frame_id); /* B */
	ILI9341_print_text(text, 18, 59, COLOR_CYAN, COLOR_NAVY, 4);
	sprintf(text, "%c", 67 + 3 * *frame_id); /* C */
	ILI9341_print_text(text, 18, 106, COLOR_MAGENTA, COLOR_NAVY, 4);
	if(!change_only_ABC_buttons) {
		ILI9341_print_text("<-", 10, 156, COLOR_ORANGE, COLOR_NAVY, 3);
		ILI9341_print_text("->", 14, 202, COLOR_GREEN, COLOR_NAVY, 3);

		/* Print title */
		ILI9341_print_text("Main frame", 55, 10, COLOR_YELLOW, COLOR_NAVY, 2);

		/* Write out letters */
		sprintf(text, "A:Show measurement and time");
		ILI9341_print_text(text, 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "B:Set analog calibration");
		ILI9341_print_text(text, 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "C:Set PWM frequencies");
		ILI9341_print_text(text, 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "D:Store measurements to SD card");
		ILI9341_print_text(text, 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "E:Set control program");
		ILI9341_print_text(text, 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "F:Set date and time and alarm");
		ILI9341_print_text(text, 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "G:Do a PGN request");
		ILI9341_print_text(text, 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "H:Show ECU addresses");
		ILI9341_print_text(text, 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "I:Commanded address");
		ILI9341_print_text(text, 55, 115, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "J:Show this ECU DM1 codes");
		ILI9341_print_text(text, 55, 125, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "K:Show other ECU DM1 codes");
		ILI9341_print_text(text, 55, 135, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "L:Show this ECU DM2 codes");
		ILI9341_print_text(text, 55, 145, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "M:Show other ECU DM2 codes");
		ILI9341_print_text(text, 55, 155, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "N:Show this ECU name");
		ILI9341_print_text(text, 55, 165, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "O:Show other ECU name");
		ILI9341_print_text(text, 55, 175, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "P:Show this ECU identifications");
		ILI9341_print_text(text, 55, 185, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "Q:Show other ECU identifications");
		ILI9341_print_text(text, 55, 195, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "R:Set pulses per encoder revolution");
		ILI9341_print_text(text, 55, 195, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "S:Set gain and offset for ADC/DADC");
		ILI9341_print_text(text, 55, 205, COLOR_YELLOW, COLOR_NAVY, 1);
	}
}
