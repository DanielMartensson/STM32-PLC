/*
 * SAE_J1939_Identifications_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"
#include "../../../Functions.h"

static uint8_t enter_identification(char identification[], char title[], uint8_t *frame_id);
static void show_identifications(char title[], struct Identifications *identifications, bool display_from_ecu_address);
static void fill_char_array(char text[], char title[], uint8_t data[], uint8_t length);

void STM32_PLC_LCD_Show_SAE_J1939_This_ECU_Identifications_Frame(J1939 *j1939, uint8_t *frame_id) {
	show_identifications("Identifications about this ECU", &j1939->this_identifications, false);

	/* Button */
	ILI9341_fill_rect(70, 195, 293, 220, COLOR_GREEN);
	ILI9341_hollow_rect(70, 195, 293, 220, COLOR_BLACK);
	ILI9341_print_text("Set identification", 75, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for button */
	STM32_PLC_LCD_Call_One_Button_Logic(70, 195, 293, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to set identification?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Begin with software identification */
	char identification[17] = "";
	if(enter_identification(identification, "Enter software identification", frame_id) == 0)
		return;
	j1939->this_identifications.software_identification.number_of_fields = strlen(identification); /* This differ from ECU/Component identification */
	memcpy(j1939->this_identifications.software_identification.identifications, (uint8_t*)identification, sizeof(identification));

	/* ECU part number */
	if(enter_identification(identification, "Enter ECU part number", frame_id) == 0)
		return;
	memcpy(j1939->this_identifications.ecu_identification.ecu_part_number, (uint8_t*)identification, sizeof(identification));

	/* ECU serial number */
	if(enter_identification(identification, "Enter ECU serial number", frame_id) == 0)
		return;
	memcpy(j1939->this_identifications.ecu_identification.ecu_serial_number, (uint8_t*)identification, sizeof(identification));

	/* ECU location */
	if(enter_identification(identification, "Enter ECU location", frame_id) == 0)
		return;
	memcpy(j1939->this_identifications.ecu_identification.ecu_location, (uint8_t*)identification, sizeof(identification));

	/* ECU type */
	if(enter_identification(identification, "Enter ECU type", frame_id) == 0)
		return;
	memcpy(j1939->this_identifications.ecu_identification.ecu_type, (uint8_t*)identification, sizeof(identification));

	/* Component product date */
	if(enter_identification(identification, "Enter component product date", frame_id) == 0)
		return;
	memcpy(j1939->this_identifications.component_identification.component_product_date, (uint8_t*)identification, sizeof(identification));

	/* Component model name */
	if(enter_identification(identification, "Enter component model name", frame_id) == 0)
		return;
	memcpy(j1939->this_identifications.component_identification.component_model_name, (uint8_t*)identification, sizeof(identification));

	/* Component serial number */
	if(enter_identification(identification, "Enter component serial number", frame_id) == 0)
		return;
	memcpy(j1939->this_identifications.component_identification.component_serial_number, (uint8_t*)identification, sizeof(identification));

	/* Component unit name */
	if(enter_identification(identification, "Enter component unit name", frame_id) == 0)
		return;
	memcpy(j1939->this_identifications.component_identification.component_unit_name, (uint8_t*)identification, sizeof(identification));

	/* Save identifications to SD card */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Write("ID.TXT");
	STM32_PLC_SD_Write_File((char*)j1939->this_identifications.software_identification.identifications);
	STM32_PLC_SD_Write_File((char*)DELIMITER);
	STM32_PLC_SD_Write_File((char*)j1939->this_identifications.ecu_identification.ecu_part_number);
	STM32_PLC_SD_Write_File((char*)DELIMITER);
	STM32_PLC_SD_Write_File((char*)j1939->this_identifications.ecu_identification.ecu_serial_number);
	STM32_PLC_SD_Write_File((char*)DELIMITER);
	STM32_PLC_SD_Write_File((char*)j1939->this_identifications.ecu_identification.ecu_location);
	STM32_PLC_SD_Write_File((char*)DELIMITER);
	STM32_PLC_SD_Write_File((char*)j1939->this_identifications.ecu_identification.ecu_type);
	STM32_PLC_SD_Write_File((char*)DELIMITER);
	STM32_PLC_SD_Write_File((char*)j1939->this_identifications.component_identification.component_product_date);
	STM32_PLC_SD_Write_File((char*)DELIMITER);
	STM32_PLC_SD_Write_File((char*)j1939->this_identifications.component_identification.component_model_name);
	STM32_PLC_SD_Write_File((char*)DELIMITER);
	STM32_PLC_SD_Write_File((char*)j1939->this_identifications.component_identification.component_serial_number);
	STM32_PLC_SD_Write_File((char*)DELIMITER);
	STM32_PLC_SD_Write_File((char*)j1939->this_identifications.component_identification.component_unit_name);
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();

	/* Done */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}

void STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_Identifications_Frame(J1939 *j1939, uint8_t *frame_id) {
	show_identifications("Identifications about other ECU", &j1939->from_other_ecu_identifications, true);

	/* Exit button */
	ILI9341_fill_rect(85, 205, 273, 230, COLOR_GREEN);
	ILI9341_hollow_rect(85, 205, 273, 230, COLOR_BLACK);
	ILI9341_print_text("Exit frame now", 95, 210, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for that button */
	STM32_PLC_LCD_Call_One_Button_Logic(85, 205, 273, 230);

	/* Go back */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}

static uint8_t enter_identification(char identification[], char title[], uint8_t *frame_id) {
	memset(identification, 0, strlen(identification));
	if(STM32_PLC_LCD_Show_Keyboard_Frame(identification, title) == 0){
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return 0;
	}
	return 1;
}

static void show_identifications(char title[], struct Identifications *identifications, bool display_from_ecu_address) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text(title, 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Software identification */
	char text[50] = "";
	uint8_t index_row = 35;
	uint8_t length = identifications->software_identification.number_of_fields;
	ILI9341_print_text("Software identification:", 55, index_row, COLOR_YELLOW, COLOR_NAVY, 1);
	fill_char_array(text, "ID:", identifications->software_identification.identifications, length);
	ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	if(display_from_ecu_address){
		sprintf(text, "Source address:%i", identifications->software_identification.from_ecu_address);
		ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	}else{
		index_row += 10;
	}

	/* ECU identification */
	ILI9341_print_text("ECU identification:", 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	length = strlen((char*)identifications->ecu_identification.ecu_part_number);
	fill_char_array(text, "Part number:", identifications->ecu_identification.ecu_part_number, length);
	ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	length = strlen((char*)identifications->ecu_identification.ecu_serial_number);
	fill_char_array(text, "Serial number:", identifications->ecu_identification.ecu_serial_number, length);
	ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	length = strlen((char*)identifications->ecu_identification.ecu_location);
	fill_char_array(text, "Location:", identifications->ecu_identification.ecu_location, length);
	ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	length = strlen((char*)identifications->ecu_identification.ecu_type);
	fill_char_array(text, "Type:", identifications->ecu_identification.ecu_type, length);
	ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	if(display_from_ecu_address){
		sprintf(text, "Source address:%i", identifications->ecu_identification.from_ecu_address);
		ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	}else{
		index_row += 10;
	}

	/* Component identification */
	ILI9341_print_text("Component identification:", 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	length = strlen((char*)identifications->component_identification.component_product_date);
	fill_char_array(text, "Product date:", identifications->component_identification.component_product_date, length);
	ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	length = strlen((char*)identifications->component_identification.component_model_name);
	fill_char_array(text, "Model name:", identifications->component_identification.component_model_name, length);
	ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	length = strlen((char*)identifications->component_identification.component_serial_number);
	fill_char_array(text, "Serial number:", identifications->component_identification.component_serial_number, length);
	ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	length = strlen((char*)identifications->component_identification.component_unit_name);
	fill_char_array(text, "Unit name:", identifications->component_identification.component_unit_name, length);
	ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	if(display_from_ecu_address){
		sprintf(text, "Source address:%i", identifications->component_identification.from_ecu_address);
		ILI9341_print_text(text, 55, index_row += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	}

}

static void fill_char_array(char text[], char title[], uint8_t data[], uint8_t length) {
	memset(text, 0, strlen(text));
	memcpy(text, title, strlen(title));
	memcpy(text + strlen(title), (char*)data, length); /* Move text strlen(title) elements */
}
