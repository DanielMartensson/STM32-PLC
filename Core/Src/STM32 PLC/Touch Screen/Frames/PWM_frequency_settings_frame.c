/*
 * PWM_frequency_settings_frame.c
 *
 *  Created on: 25 juli 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

static const uint16_t prescalers[20] = {0, 1, 2, 4, 6, 13, 72, 145, 182, 243, 365, 731, 1462, 2193, 2924, 3655, 4880, 7310, 65535};

void STM32_PLC_LCD_Show_PWM_Frequency_Settings_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Set PWM frequency", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/*
	 * For TIM2 and TIM5
	 * Timer clock: 48 Mhz
	 * Prescaler: Selected below
	 * Counter: 65535 (0xffff)
	 * Update frequency: See PWM choices
	 * MATLAB formula:
	 * for i = [0 1 2 4 6 13 72 145 182 243 365 731 1462 2193 2924 3655 4880 7310 65535]
    		disp(sprintf("Hz = %i at prescaler = %i", (48*10^6/(1+i))/0xFFFF, i));
		end
	 */

	/* Show all calibration inputs */
	ILI9341_print_text("PWM choices to select:", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("732Hz=0 366Hz=1 244Hz=2", 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("146Hz=4 104Hz=5 52Hz=6", 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("10Hz=7 5Hz=8 4Hz=9", 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("3Hz=10 2Hz=11 1Hz=12 0.5Hz=13", 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("0.33Hz=14 0.25Hz=15 0.2Hz=16", 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("0.15Hz=17 0.1Hz=18 0.011Hz=19", 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Show selected frequency */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	STM32_PLC_SD_Open_Existing_File_With_Read("PWM.TXT");
	char text[30];
	STM32_PLC_SD_Read_File(text, sizeof(text));
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();
	uint16_t prescaler_PWM_0_3 = atoi(strtok(text, DELIMITER));
	uint16_t prescaler_PWM_4_7 = atoi(strtok(NULL, DELIMITER));
	ILI9341_print_text("Current settings:", 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "PWM_0_3:%i PWM_4_7:%i", prescaler_PWM_0_3, prescaler_PWM_4_7);
	ILI9341_print_text(text, 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Select settings button */
	ILI9341_fill_rect(85, 195, 273, 220, COLOR_GREEN);
	ILI9341_hollow_rect(85, 195, 273, 220, COLOR_BLACK);
	ILI9341_print_text("Select PWM freq", 90, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for request button */
	STM32_PLC_LCD_Call_One_Button_Logic(85, 195, 273, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to set PWM frequency?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* You entered choice 1 - Show numpad */
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter input number between 0 and 19") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint8_t PWM_frequency;
	if(number_value < 0)
		PWM_frequency = 0;
	else if(number_value > 19)
		PWM_frequency = 19;
	else
		PWM_frequency = (uint8_t) number_value;

	/* Ask for which PWM */
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Set setting for PWM0-PWM3=0 or PWM4-PWM7=1") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint8_t PWM_TIM;
	if(number_value < 0)
		PWM_TIM = 0;
	else if(number_value > 1)
		PWM_TIM = 1;
	else
		PWM_TIM = (uint8_t) number_value;

	/* Apply them */
	if(PWM_TIM == 0)
		STM32_PLC_PWM0_To_PWM3_Set_Prescaler(prescalers[PWM_frequency]);
	else
		STM32_PLC_PWM4_To_PWM7_Set_Prescaler(prescalers[PWM_frequency]);

	/* Mount */
	if(STM32_PLC_SD_Mont_Card() != FR_OK){
		STM32_PLC_LCD_Show_Information_OK_Dialog("Could not mount SD card");
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Overwrite */
	if(PWM_TIM == 0)
		prescaler_PWM_0_3 = PWM_frequency;
	else
		prescaler_PWM_4_7 = PWM_frequency;

	/* Write */
	STM32_PLC_SD_Open_Existing_File_With_Write("PWM.TXT");
	sprintf(text, "%i%s%i", prescaler_PWM_0_3, DELIMITER, prescaler_PWM_4_7);
	STM32_PLC_SD_Write_File(text);
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}
