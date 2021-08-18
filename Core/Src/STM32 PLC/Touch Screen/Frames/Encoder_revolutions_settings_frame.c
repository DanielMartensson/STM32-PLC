/*
 * Encoder_revolutions_settings_frame.c
 *
 *  Created on: 25 juli 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

void STM32_PLC_LCD_Show_Encoder_Revolutions_Settings_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Set encoder revolution", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Show all calibration inputs */
	ILI9341_print_text("Encoder counts between:", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("-32767 to 32767", 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Set how many pulses one", 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("revolution is for encoder:", 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Show selected frequency */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Read("ENCODER.TXT");
	char text[50];
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();
	uint16_t pulses_per_revolution_0 = atoi(strtok(text, DELIMITER));
	uint16_t pulses_per_revolution_1 = atoi(strtok(NULL, DELIMITER));
	ILI9341_print_text("Current settings:", 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "Encoder0:%i Encoder1:%i", pulses_per_revolution_0, pulses_per_revolution_1);
	ILI9341_print_text(text, 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Select settings button */
	ILI9341_fill_rect(90, 195, 273, 220, COLOR_GREEN);
	ILI9341_hollow_rect(90, 195, 273, 220, COLOR_BLACK);
	ILI9341_print_text("Select encoder", 100, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for request button */
	STM32_PLC_LCD_Call_One_Button_Logic(90, 195, 273, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to set encoder revolution?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* You entered choice 1 - Show numpad */
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter input number between 1 and 32767") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint16_t pulses_per_revolution;
	if(number_value < 1)
		pulses_per_revolution = 1;
	else if(number_value > 32767)
		pulses_per_revolution = 32767;
	else
		pulses_per_revolution = (uint16_t) number_value;

	/* Ask for which PWM */
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Set setting for Encoder0=0 or Encoder1=1") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint8_t encoder_choice;
	if(number_value < 0)
		encoder_choice = 0;
	else if(number_value > 1)
		encoder_choice = 1;
	else
		encoder_choice = (uint8_t) number_value;

	/* Apply them */
	STM32_PLC_Encoder_Set_Pulses_Per_Revolutions(encoder_choice, pulses_per_revolution);

	/* Mount */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Overwrite */
	if(encoder_choice == 0)
		pulses_per_revolution_0 = pulses_per_revolution;
	else
		pulses_per_revolution_1 = pulses_per_revolution;

	/* Write */
	STM32_PLC_SD_Open_Existing_File_With_Write("ENCODER.TXT");
	sprintf(text, "%i%s%i", pulses_per_revolution_0, DELIMITER, pulses_per_revolution_1);
	STM32_PLC_SD_Write_File(text);
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}
