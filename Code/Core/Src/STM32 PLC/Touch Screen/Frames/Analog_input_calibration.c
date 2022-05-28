/*
 * Analog_input_calibration.c
 *
 *  Created on: 21 maj 2022
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

void STM32_PLC_LCD_Show_Analog_Input_Calibration_Frame(uint8_t *frame_id){
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Set analog input calibration", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Variables for the text */
	uint16_t y = 25;

	/* Show analog inputs */
	ILI9341_print_text("0=ADC0 1=ADC1", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("2=ADC2 3=ADC3", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("4=ADC4 5=ADC5", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("6=ADC6 7=ADC7", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("8=ADC8 9=ADC9", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("10=ADC10 11=ADC11", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("12=DADC0 13=DADC1", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("14=DADC2 15=DADC3", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("15=DADC4 16=DADC5", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("At 0mA=0 Raw value", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("At 4mA=12710 Raw value", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("At 20mA=63549 Raw value", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("At 20.625mA=65535 Raw value", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Button */
	ILI9341_fill_rect(65, 195, 300, 220, COLOR_GREEN);
	ILI9341_hollow_rect(65, 195, 300, 220, COLOR_BLACK);
	ILI9341_print_text("Set calibration now", 70, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for button */
	STM32_PLC_LCD_Call_One_Button_Logic(65, 195, 300, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want set analog gain?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Ask for which analog input */
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter analog input 0 to 16") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint8_t input_index;
	if(number_value < 0)
		input_index = 0;
	else if(number_value > 16)
		input_index = 16;
	else
		input_index = (uint8_t) number_value;

	/* Ask for scalar */
	minusbutton_show = true;
	decimalbutton_show = true;
	float scalar;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &scalar, "Enter scalar value") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Ask for bias */
	float bias;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &bias, "Enter bias value") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Apply calibration */
	STM32_PLC_Analog_Input_Set_Calibration(input_index, scalar, bias, true);

	/* Exit */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);

}
