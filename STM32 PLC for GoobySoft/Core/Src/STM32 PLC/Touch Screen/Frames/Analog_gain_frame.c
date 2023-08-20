/*
 * Analog_gain_frame.c
 *
 *  Created on: 20 maj 2022
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

void STM32_PLC_LCD_Show_Analog_Gain_Frame(uint8_t *frame_id){
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Set analog gain", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Array and variables for the text */
	char text[50];
	uint16_t y = 25;

	/* Get analog gains for SDADC 1 */
	uint8_t gain_for_configuration_index_0, gain_for_configuration_index_1, gain_for_configuration_index_2;
	STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_1(&gain_for_configuration_index_0, &gain_for_configuration_index_1, &gain_for_configuration_index_2);
	sprintf(text, "0=ADC0:%i,ADC1:%i,ADC2:%i", gain_for_configuration_index_0, gain_for_configuration_index_0, gain_for_configuration_index_0);
	ILI9341_print_text(text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "1=ADC3:%i,ADC4:%i,ADC5:%i", gain_for_configuration_index_1, gain_for_configuration_index_1, gain_for_configuration_index_1);
	ILI9341_print_text(text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "2=ADC6:%i,ADC7:%i,ADC8:%i", gain_for_configuration_index_2, gain_for_configuration_index_2, gain_for_configuration_index_2);
	ILI9341_print_text(text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Get analog gains for SDADC 2 */
	STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_2(&gain_for_configuration_index_0, &gain_for_configuration_index_1, &gain_for_configuration_index_2);
	sprintf(text, "3=ADC9:%i", gain_for_configuration_index_0);
	ILI9341_print_text(text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "4=ADC10:%i", gain_for_configuration_index_1);
	ILI9341_print_text(text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "5=ADC11:%i", gain_for_configuration_index_2);
	ILI9341_print_text(text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Get analog gains for SDADC 3 */
	STM32_PLC_Flash_Get_ADC_Gains_For_SDADC_3(&gain_for_configuration_index_0, &gain_for_configuration_index_1, &gain_for_configuration_index_2);
	sprintf(text, "6=DADC0:%i,DADC1:%i", gain_for_configuration_index_0, gain_for_configuration_index_0);
	ILI9341_print_text(text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "7=DADC2:%i,DADC3:%i", gain_for_configuration_index_1, gain_for_configuration_index_1);
	ILI9341_print_text(text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "8=DADC4:%i", gain_for_configuration_index_2);
	ILI9341_print_text(text, 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Print gain values */
	ILI9341_print_text("Gain values from 1/2x to 32x:", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("0=1x,1=2x,2=4x,3=8x,4=16x,5=32x,6=0.5x", 55, y += 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Button */
	ILI9341_fill_rect(65, 195, 300, 220, COLOR_GREEN);
	ILI9341_hollow_rect(65, 195, 300, 220, COLOR_BLACK);
	ILI9341_print_text("Set analog gain now", 70, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for button */
	STM32_PLC_LCD_Call_One_Button_Logic(65, 195, 300, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want set analog gain?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* You entered choice 1 - Show numpad */
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value = 0;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter input number between 0 and 8") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint8_t analog_input_index;
	if(number_value < 0)
		analog_input_index = 0;
	else if(number_value > 8)
		analog_input_index = 8;
	else
		analog_input_index = (uint8_t) number_value;


	/* Ask for gain value */
	number_value = 0;
	switch(analog_input_index){
	case 0:
		sprintf(text, "Enter gain value for ADC0,ADC1,ADC2");
		break;
	case 1:
		sprintf(text, "Enter gain value for ADC3,ADC4,ADC5");
		break;
	case 2:
		sprintf(text, "Enter gain value for ADC6,ADC7,ADC8");
		break;
	case 3:
		sprintf(text, "Enter gain value for ADC9");
		break;
	case 4:
		sprintf(text, "Enter gain value for ADC10");
		break;
	case 5:
		sprintf(text, "Enter gain value for ADC11");
		break;
	case 6:
		sprintf(text, "Enter gain value for DADC0,DADC1");
		break;
	case 7:
		sprintf(text, "Enter gain value for DADC2,DADC3");
		break;
	case 8:
		sprintf(text, "Enter gain value for DADC4");
		break;
	}
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, text) == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}
	uint8_t gain;
	if(number_value < 0)
		gain = 0;
	else if(number_value > 7)
		gain = 7;
	else
		gain = (uint8_t) number_value;

	/* Apply them */
	switch(analog_input_index){
	case 0:
		/* SDADC1 */
		STM32_PLC_Analog_Input_Set_Gain(0, SDADC_CONF_INDEX_0, gain, true);
		break;
	case 1:
		STM32_PLC_Analog_Input_Set_Gain(0, SDADC_CONF_INDEX_1, gain, true);
		break;
	case 2:
		STM32_PLC_Analog_Input_Set_Gain(0, SDADC_CONF_INDEX_2, gain, true);
		break;
	case 3:
		/* SDADC 2 */
		STM32_PLC_Analog_Input_Set_Gain(1, SDADC_CONF_INDEX_0, gain, true);
		break;
	case 4:
		STM32_PLC_Analog_Input_Set_Gain(1, SDADC_CONF_INDEX_1, gain, true);
		break;
	case 5:
		STM32_PLC_Analog_Input_Set_Gain(1, SDADC_CONF_INDEX_2, gain, true);
		break;
	case 6:
		/* SDADC 3 */
		STM32_PLC_Analog_Input_Set_Gain(2, SDADC_CONF_INDEX_0, gain, true);
		break;
	case 7:
		STM32_PLC_Analog_Input_Set_Gain(2, SDADC_CONF_INDEX_1, gain, true);
		break;
	case 8:
		STM32_PLC_Analog_Input_Set_Gain(2, SDADC_CONF_INDEX_2, gain, true);
		break;
	}

	/* Show main frame again */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);

}
