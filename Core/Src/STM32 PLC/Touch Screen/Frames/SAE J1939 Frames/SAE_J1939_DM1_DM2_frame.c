/*
 * SAE_J1939_DM1_DM2_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Touch_screen.h"
#include "../../Hardware/ILI9341.h"

static void show_DM_frame(char title[], struct DM1 *dm, bool display_from_ecu_address);
static void call_exit(uint8_t *frame_id);

void STM32_PLC_LCD_Show_SAE_J1939_This_ECU_DM1_Frame(J1939 *j1939, uint8_t *frame_id) {
	show_DM_frame("This ECU DM1 codes", &j1939->this_dm.dm1, false);
	call_exit(frame_id);
}

void STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_DM1_Frame(J1939 *j1939, uint8_t *frame_id){
	show_DM_frame("Other ECU DM1 codes", &j1939->from_other_ecu_dm.dm1, true);
	call_exit(frame_id);
}

void STM32_PLC_LCD_Show_SAE_J1939_This_ECU_DM2_Frame(J1939 *j1939, uint8_t *frame_id) {
	show_DM_frame("This ECU DM2 codes", &j1939->this_dm.dm2, false);
	call_exit(frame_id);
}

void STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_DM2_Frame(J1939 *j1939, uint8_t *frame_id) {
	show_DM_frame("Other ECU DM2 codes", &j1939->from_other_ecu_dm.dm2, true);
	call_exit(frame_id);
}

/* This can be DM1 or DM2 frame */
static void show_DM_frame(char title[], struct DM1 *dm, bool display_from_ecu_address) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text(title, 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SAE Lamp status malfunction indicator */
	char text[50];
	sprintf(text, "Lamp malfunction:%i", dm->SAE_lamp_status_malfunction_indicator);
	ILI9341_print_text(text, 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SAE Lamp status red stop */
	sprintf(text, "Lamp red stop:%i", dm->SAE_lamp_status_red_stop);
	ILI9341_print_text(text, 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SAE Lamp status amber warning */
	sprintf(text, "Lamp amber warning:%i", dm->SAE_lamp_status_amber_warning);
	ILI9341_print_text(text, 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SAE Lamp status protection lamp */
	sprintf(text, "Lamp protection:%i", dm->SAE_lamp_status_protect_lamp);
	ILI9341_print_text(text, 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SAE Flash lamp malfunction indicator */
	sprintf(text, "Flash malfunction:%i", dm->SAE_flash_lamp_malfunction_indicator);
	ILI9341_print_text(text, 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SAE Flash lamp red stop */
	sprintf(text, "Flash red stop:%i", dm->SAE_flash_lamp_red_stop);
	ILI9341_print_text(text, 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SAE Flash lamp amber warning */
	sprintf(text, "Flash amber warning:%i", dm->SAE_flash_lamp_amber_warning);
	ILI9341_print_text(text, 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SAE Flash lamp protection lamp */
	sprintf(text, "Lamp protection:%i", dm->SAE_flash_lamp_protect_lamp);
	ILI9341_print_text(text, 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SPN */
	sprintf(text, "SPN:%lu", dm->SPN);
	ILI9341_print_text(text, 55, 115, COLOR_YELLOW, COLOR_NAVY, 1);

	/* FMI */
	uint8_t FMI = dm->FMI;
	switch (FMI) {
	case 0x0:
		sprintf(text, "FMI:Above normal most serve");
		break;
	case 0x1:
		sprintf(text, "FMI:Below normal most serve");
		break;
	case 0x2:
		sprintf(text, "FMI:Data erratic");
		break;
	case 0x3:
		sprintf(text, "FMI:Voltage above normal");
		break;
	case 0x4:
		sprintf(text, "FMI:Voltage below normal");
		break;
	case 0x5:
		sprintf(text, "FMI:Current below normal");
		break;
	case 0x6:
		sprintf(text, "FMI:Current above normal");
		break;
	case 0x7:
		sprintf(text, "FMI:Mechanical system not responding");
		break;
	case 0x8:
		sprintf(text, "FMI:Abnormal frequency");
		break;
	case 0x9:
		sprintf(text, "FMI:Abnormal update rate");
		break;
	case 0xA:
		sprintf(text, "FMI:Abnormal rate change");
		break;
	case 0xB:
		sprintf(text, "FMI:Root cause not known");
		break;
	case 0xC:
		sprintf(text, "FMI:Bad intelligent device");
		break;
	case 0xD:
		sprintf(text, "FMI:Out of calibration");
		break;
	case 0xE:
		sprintf(text, "FMI:Special instructions");
		break;
	case 0xF:
		sprintf(text, "FMI:Abnormal least serve");
		break;
	case 0x10:
		sprintf(text, "FMI:Above normal moderately serve");
		break;
	case 0x11:
		sprintf(text, "FMI:Below normal least serve");
		break;
	case 0x12:
		sprintf(text, "FMI:Below normal moderately serve");
		break;
	case 0x13:
		sprintf(text, "FMI:Received network data in error");
		break;
	case 0x14:
		sprintf(text, "FMI:Data drifted high");
		break;
	case 0x15:
		sprintf(text, "FMI:Data drifted low");
		break;
	default:
		sprintf(text, "FMI:Not available");
		break;
	}
	ILI9341_print_text(text, 55, 125, COLOR_YELLOW, COLOR_NAVY, 1);

	/* SPN conversion method */
	sprintf(text, "SPN conversion method:%i", dm->SPN_conversion_method);
	ILI9341_print_text(text, 55, 135, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Occurrence count */
	sprintf(text, "Occurrence count:%i", dm->occurrence_count);
	ILI9341_print_text(text, 55, 145, COLOR_YELLOW, COLOR_NAVY, 1);

	/* From ECU address */
	if(display_from_ecu_address){
		sprintf(text, "From ECU address:%i", dm->from_ecu_address);
		ILI9341_print_text(text, 55, 155, COLOR_YELLOW, COLOR_NAVY, 1);
	}
}

static void call_exit(uint8_t *frame_id){
	/* Exit button */
	ILI9341_fill_rect(85, 205, 273, 230, COLOR_GREEN);
	ILI9341_hollow_rect(85, 205, 273, 230, COLOR_BLACK);
	ILI9341_print_text("Exit frame now", 95, 210, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for that button */
	STM32_PLC_LCD_Call_One_Button_Logic(85, 205, 273, 230);

	/* Go back */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}
