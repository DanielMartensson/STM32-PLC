/*
 * SAE_J1939_Name_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"
#include "../../../Functions.h"

static uint8_t show_numpad_question(char title[], uint8_t *frame_id, uint32_t max_value, uint32_t *value);
static void show_name_frame(char title[], struct Name *name, bool display_from_ecu_address);

void STM32_PLC_LCD_Show_SAE_J1939_This_ECU_Name_Frame(J1939 *j1939, uint8_t *frame_id) {
	show_name_frame("This ECU name", &j1939->this_name, false);

	/* Button */
	ILI9341_fill_rect(80, 195, 285, 220, COLOR_GREEN);
	ILI9341_hollow_rect(80, 195, 285, 220, COLOR_BLACK);
	ILI9341_print_text("Set the ECU NAME", 87, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for button */
	STM32_PLC_LCD_Call_One_Button_Logic(80, 195, 285, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to set the NAME?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

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

	/* Apply for this ECU */
	j1939->this_name.identity_number = identity_number;
	j1939->this_name.manufacturer_code = manufacturer_code;
	j1939->this_name.function_instance = function_instance;
	j1939->this_name.ECU_instance = ECU_instance;
	j1939->this_name.function = function;
	j1939->this_name.vehicle_system = vehicle_system;
	j1939->this_name.arbitrary_address_capable = arbitrary_address_capable;
	j1939->this_name.industry_group = industry_group;
	j1939->this_name.vehicle_system_instance = vehicle_system_instance;

	/* Write SD card */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Write("NAME.TXT");
	char text[100];
	sprintf(text, "%lu%s%i%s%i%s%i%s%i%s%i%s%i%s%i%s%i", identity_number, DELIMITER, (uint16_t)manufacturer_code, DELIMITER, (uint8_t)function_instance, DELIMITER, (uint8_t)ECU_instance, DELIMITER, (uint8_t)function, DELIMITER, (uint8_t)vehicle_system, DELIMITER, (uint8_t)arbitrary_address_capable, DELIMITER, (uint8_t)industry_group, DELIMITER, (uint8_t)vehicle_system_instance);
	STM32_PLC_SD_Write_File(text);
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}

void STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_Name_Frame(J1939 *j1939, uint8_t *frame_id) {
	show_name_frame("Other ECU name", &j1939->from_other_ecu_name, true);

	/* Exit button */
	ILI9341_fill_rect(85, 205, 273, 230, COLOR_GREEN);
	ILI9341_hollow_rect(85, 205, 273, 230, COLOR_BLACK);
	ILI9341_print_text("Exit frame now", 95, 210, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for that button */
	STM32_PLC_LCD_Call_One_Button_Logic(85, 205, 273, 230);

	/* Go back */
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

static void show_name_frame(char title[], struct Name *name, bool display_from_ecu_address){
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text(title, 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out identity number */
	char text[50];
	sprintf(text, "Identity:%lu", name->identity_number);
	ILI9341_print_text(text, 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out manufacturer code */
	if(name->manufacturer_code == MANUFACTURER_CODE_GRAYHILL)
		sprintf(text, "Manufacturer code: Gray Hill");
	else if (name->manufacturer_code == MANUFACTURER_CODE_SONCEBOZ)
		sprintf(text, "Manufacturer code: SonceBoz");
	else
		sprintf(text, "Manufacturer code:%i", name->manufacturer_code);
	ILI9341_print_text(text, 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out function instance */
	sprintf(text, "Function instance:%i", name->function_instance);
	ILI9341_print_text(text, 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out ECU instance */
	sprintf(text, "ECU instance:%i", name->ECU_instance);
	ILI9341_print_text(text, 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out function */
	if(name->function == FUNCTION_AUXILIARY_VALVES_CONTROL)
		sprintf(text, "Function:Auxiliary Valves Control");
	else if (name->function == FUNCTION_VDC_MODULE)
		sprintf(text, "Function:VDC Module");
	else
		sprintf(text, "Function:%i", name->function);
	ILI9341_print_text(text, 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out vehicle system */
	sprintf(text, "Vehicle system:%i", name->vehicle_system);
	ILI9341_print_text(text, 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out vehicle system */
	if(name->arbitrary_address_capable > 0)
		sprintf(text, "Arbitrary address capable:Yes");
	else
		sprintf(text, "Arbitrary address capable:No");
	ILI9341_print_text(text, 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out industry group */
	if(name->industry_group == INDUSTRY_GROUP_GLOBAL)
		sprintf(text, "Industry group:Global");
	else if(name->industry_group == INDUSTRY_GROUP_CONSTRUCTION)
		sprintf(text, "Industry group:Construction");
	else if(name->industry_group == INDUSTRY_GROUP_AGRICULTURAL_AND_FORESTRY)
		sprintf(text, "Industry group:Agricultural and forestry");
	else if(name->industry_group == INDUSTRY_GROUP_INDUSTRIAL_CONTROL_PROCESS)
		sprintf(text, "Industry group:Industrial control process");
	else if(name->industry_group == INDUSTRY_GROUP_MARINE)
		sprintf(text, "Industry group:Marine");
	else if(name->industry_group == INDUSTRY_GROUP_ON_HIGHWAY)
		sprintf(text, "Industry group:On highway");
	else
		sprintf(text, "Industry group:None");
	ILI9341_print_text(text, 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out vehicle system instance */
	sprintf(text, "Vehicle system instance:%i", name->vehicle_system_instance);
	ILI9341_print_text(text, 55, 115, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Write out source address */
	if(display_from_ecu_address){
		sprintf(text, "Source address:%i", name->from_ecu_address);
		ILI9341_print_text(text, 55, 125, COLOR_YELLOW, COLOR_NAVY, 1);
	}
}
