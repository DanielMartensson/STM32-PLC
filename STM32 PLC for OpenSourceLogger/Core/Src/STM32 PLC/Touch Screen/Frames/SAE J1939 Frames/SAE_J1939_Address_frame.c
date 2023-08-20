/*
 * SAE_J1939_Address_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"
#include "../../../Functions.h"
#include "../../../Open SAE J1939/SAE_J1939/SAE_J1939-81_Network_Management_Layer/Network_Management_Layer.h"

void STM32_PLC_LCD_Show_SAE_J1939_Address_Frame(J1939 *j1939, uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);

	ILI9341_print_text("ECU address and connections", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* This ECU address */
	char text[50];
	sprintf(text, "This ECU address:%i", j1939->information_this_ECU.this_ECU_address);
	ILI9341_print_text(text, 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);

	/* How many ECU are connected */
	sprintf(text, "Other ECU connected:%i", j1939->number_of_other_ECU);
	ILI9341_print_text(text, 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Which ECU are connected */
	sprintf(text, "Other ECU addresses:");
	ILI9341_print_text(text, 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
	for(uint8_t i = 0; i < j1939->number_of_other_ECU; i++){
		sprintf(text, "%i,", j1939->other_ECU_address[i]); /* Important with space */
		ILI9341_print_text(text, 55 + i*15, 65, COLOR_YELLOW, COLOR_NAVY, 1);
	}

	/* How many ECU are not connected */
	sprintf(text, "Other ECU not connected:%i", j1939->number_of_cannot_claim_address);
	ILI9341_print_text(text, 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Button */
	ILI9341_fill_rect(65, 195, 300, 220, COLOR_GREEN);
	ILI9341_hollow_rect(65, 195, 300, 220, COLOR_BLACK);
	ILI9341_print_text("Set the ECU address", 70, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for button */
	STM32_PLC_LCD_Call_One_Button_Logic(65, 195, 300, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to set the ECU address?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Enter a number */
	float number_value;
	bool decimalbutton_show = false;
	bool minusbutton_show = false;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter address between 0 and 253") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	uint8_t address;
	if(number_value < 0)
		address = 0;
	else if(number_value > 253)
		address = 253;
	else
		address = (uint8_t) number_value;

	/* Send to all ECU that the address DA is unused */
	SAE_J1939_Send_Address_Delete(j1939, 0xFF, j1939->information_this_ECU.this_ECU_address);

	/* Apply it - our new address */
	j1939->information_this_ECU.this_ECU_address = address;

	/* Save it to the flash */
	STM32_PLC_Flash_Set_J1939_This_ECU_Address(address);

	/* Send new address to all other ECU */
	SAE_J1939_Response_Request_Address_Claimed(j1939);

	/* Done */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}
