/*
 * SAE_J1939_Request_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"
#include "../../../Open SAE J1939/SAE J1939/SAE J1939 Enums/Enum_PGN.h"
#include "../../../Open SAE J1939/SAE J1939/SAE J1939-21 Transport Layer/Transport_Layer.h"

void STM32_PLC_LCD_Show_SAE_J1939_Request_Frame(J1939 *j1939, uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Do a PGN request", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Most commonly PGN requests */
	ILI9341_print_text("Commonly PGN numbers:", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Address claimed:60928 Software ID:65242", 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("ECU ID:64965 Component ID:65295", 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("DM1:65226 DM2:65227 DM3:65228", 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Request button */
	ILI9341_fill_rect(85, 195, 273, 220, COLOR_GREEN);
	ILI9341_hollow_rect(85, 195, 273, 220, COLOR_BLACK);
	ILI9341_print_text("Enter a request", 90, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for request button */
	STM32_PLC_LCD_Call_One_Button_Logic(85, 195, 273, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to enter a PGN number?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* You entered choice 1 - Show numpad */
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter PGN number between 0 and 65535") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	uint16_t PGN;
	if(number_value < 0)
		PGN = 0;
	else if(number_value > 0xFFFF)
		PGN = 0xFFFF;
	else
		PGN = (uint16_t) number_value;

	/* Enter address */
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter destination address 0 to 255") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	uint8_t DA;
	if(number_value < 0)
		DA = 0;
	else if(number_value > 0xFF)
		DA = 0xFF;
	else
		DA = (uint8_t) number_value;

	/* Enter the request */
	SAE_J1939_Send_Request(j1939, DA, PGN);

	/* Exit */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}
