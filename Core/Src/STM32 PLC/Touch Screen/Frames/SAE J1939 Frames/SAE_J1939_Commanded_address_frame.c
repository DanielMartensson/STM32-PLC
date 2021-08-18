/*
 * SAE_J1939_Commanded_address_frame.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"
#include "../../../Functions.h"
#include "../../../Open SAE J1939/SAE J1939/SAE J1939-81 Network Management Layer/Network_Management_Layer.h"

static uint8_t show_numpad_question(char title[], uint8_t *frame_id, uint32_t max_value, uint32_t *value);

void STM32_PLC_LCD_Show_SAE_J1939_Commanded_Address_Frame(J1939 *j1939, uint8_t *frame_id) {
	/* Enter identity number */
	uint32_t identity_number;
	if(show_numpad_question("Enter identity between 0 and 2097151", frame_id, 2097151, &identity_number) == 0)
		return;
	uint32_t manufacturer_code;
	if(show_numpad_question("Enter manufacturer code between 0 and 2047", frame_id, 2047, &manufacturer_code) == 0)
		return;
	uint32_t function_instance;
	if(show_numpad_question("Enter function instance between 0 and 31", frame_id, 31, &function_instance) == 0)
		return;
	uint32_t ECU_instance;
	if(show_numpad_question("Enter ECU instance between 0 and 7", frame_id, 7, &ECU_instance) == 0)
		return;
	uint32_t function;
	if(show_numpad_question("Enter function between 0 and 255", frame_id, 255, &function) == 0)
		return;
	uint32_t vehicle_system;
	if(show_numpad_question("Enter vehicle system between 0 and 127", frame_id, 127, &vehicle_system) == 0)
		return;
	uint32_t arbitrary_address_capable;
	if(show_numpad_question("Enter arbitrary address capable between 0 and 1", frame_id, 1, &arbitrary_address_capable) == 0)
		return;
	uint32_t industry_group;
	if(show_numpad_question("Enter industry group between 0 and 7", frame_id, 7, &industry_group) == 0)
		return;
	uint32_t vehicle_system_instance;
	if(show_numpad_question("Enter vehicle system instance between 0 and 15", frame_id, 15, &vehicle_system_instance) == 0)
		return;
	uint32_t new_ECU_address;
	if(show_numpad_question("Enter new ECU address between 0 and 253", frame_id, 253, &new_ECU_address) == 0)
		return;
	uint32_t DA;
	if(show_numpad_question("Destination of the ECU between 0 and 253", frame_id, 253, &DA) == 0)
		return;

	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Set NAME and source address", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out identity number */
	char text[50];
	sprintf(text, "Identity:%lu", identity_number);
	ILI9341_print_text(text, 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out manufacturer code */
	if(manufacturer_code == MANUFACTURER_CODE_GRAYHILL)
		sprintf(text, "Manufacturer code: Gray Hill");
	else if (manufacturer_code == MANUFACTURER_CODE_SONCEBOZ)
		sprintf(text, "Manufacturer code: SonceBoz");
	else
		sprintf(text, "Manufacturer code:%i", (uint16_t)manufacturer_code);
	ILI9341_print_text(text, 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out function instance */
	sprintf(text, "Function instance:%i", (uint8_t)function_instance);
	ILI9341_print_text(text, 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out ECU instance */
	sprintf(text, "ECU instance:%i", (uint8_t)ECU_instance);
	ILI9341_print_text(text, 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out function */
	if(function == FUNCTION_AUXILIARY_VALVES_CONTROL)
		sprintf(text, "Function:Auxiliary Valves Control");
	else if (function == FUNCTION_VDC_MODULE)
		sprintf(text, "Function:VDC Module");
	else
		sprintf(text, "Function:%i", (uint8_t)function);
	ILI9341_print_text(text, 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out vehicle system */
	sprintf(text, "Vehicle system:%i", (uint8_t)vehicle_system);
	ILI9341_print_text(text, 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out vehicle system */
	if(arbitrary_address_capable > 0)
		sprintf(text, "Arbitrary address capable:Yes");
	else
		sprintf(text, "Arbitrary address capable:No");
	ILI9341_print_text(text, 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out industry group */
	if(industry_group == INDUSTRY_GROUP_GLOBAL)
		sprintf(text, "Industry group:Global");
	else if(industry_group == INDUSTRY_GROUP_CONSTRUCTION)
		sprintf(text, "Industry group:Construction");
	else if(industry_group == INDUSTRY_GROUP_AGRICULTURAL_AND_FORESTRY)
		sprintf(text, "Industry group:Agricultural and forestry");
	else if(industry_group == INDUSTRY_GROUP_INDUSTRIAL_CONTROL_PROCESS)
		sprintf(text, "Industry group:Industrial control process");
	else if(industry_group == INDUSTRY_GROUP_MARINE)
		sprintf(text, "Industry group:Marine");
	else if(industry_group == INDUSTRY_GROUP_ON_HIGHWAY)
		sprintf(text, "Industry group:On highway");
	else
		sprintf(text, "Industry group:None");
	ILI9341_print_text(text, 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out vehicle system instance */
	sprintf(text, "Vehicle system instance:%i", (uint8_t)vehicle_system_instance);
	ILI9341_print_text(text, 55, 115, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write the new ECU address */
	sprintf(text, "New ECU address:%i", (uint8_t)new_ECU_address);
	ILI9341_print_text(text, 55, 125, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write the current ECU address */
	sprintf(text, "Current ECU address:%i", (uint8_t)DA);
	ILI9341_print_text(text, 55, 135, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Button */
	ILI9341_fill_rect(70, 195, 293, 220, COLOR_GREEN);
	ILI9341_hollow_rect(70, 195, 293, 220, COLOR_BLACK);
	ILI9341_print_text("Set name & address", 75, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for button */
	STM32_PLC_LCD_Call_One_Button_Logic(70, 195, 293, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to set NAME and address?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Send it out */
	SAE_J1939_Send_Commanded_Address(j1939, DA, new_ECU_address, identity_number, manufacturer_code, function_instance, ECU_instance, function, vehicle_system, arbitrary_address_capable, industry_group, vehicle_system_instance);

	/* Done */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}

static uint8_t show_numpad_question(char title[], uint8_t *frame_id, uint32_t max_value, uint32_t *value) {
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, title) == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return 0;
	}
	if(number_value < 0)
		*value = 0;
	else if(number_value > max_value)
		*value = max_value;
	else
		*value = (uint32_t) number_value;
	return 1;
}

