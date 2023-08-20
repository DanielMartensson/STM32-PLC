/*
 * Analog_input_calibration.c
 *
 *  Created on: 21 maj 2022
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

void STM32_PLC_LCD_Show_About_STM32_PLC_Frame(uint8_t *frame_id){
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("About STM32 PLC", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Variables for the text */
	uint16_t y = 25;

	/* Show analog inputs */
	ILI9341_print_text("This PCB board have ADC 16-bit, DAC 12-bit", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("PWM 16-bit, CAN-bus with SAE J1939 protocol", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Digital inputs, Differential ADC 16-bit", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Input capture and Encoder. See the document", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("of this PCB board in the C++ software:", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("OpenSourceLogger", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Whit that software, you can store data", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("directly to a SQL database. Also control", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("the outputs of this PCB board. This STM32", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("processor STM32F373VBT is written with C", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("programming language. Visit:", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("https://github.com/danielmartensson/", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("and look for the OpenSourceLogger", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("repository there. Run the software.", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Created: 2022-05-25", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);


	/* Button */
	ILI9341_fill_rect(65, 195, 300, 220, COLOR_GREEN);
	ILI9341_hollow_rect(65, 195, 300, 220, COLOR_BLACK);
	ILI9341_print_text("Leave the frame now", 70, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for button */
	STM32_PLC_LCD_Call_One_Button_Logic(65, 195, 300, 220);

	/* Exit */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);

}
