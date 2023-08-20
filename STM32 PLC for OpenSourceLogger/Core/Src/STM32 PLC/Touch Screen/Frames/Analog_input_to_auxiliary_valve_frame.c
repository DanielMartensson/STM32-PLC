/*
 * Measurement_and_time_frame.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"
#include "../../Open SAE J1939/ISO_11783/ISO_11783-7_Application_Layer/Application_Layer.h"
#include <math.h>

static void add_spaces(uint8_t length, char text[]);

void STM32_PLC_LCD_Show_Analog_Input_To_Auxiliary_Valve_Frame(J1939 *j1939, uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("ADC0 to ADC11 to Auxiliary Valve 0 to 11", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Explain */
	ILI9341_print_text("Give ADC0 to ADC11 current", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("and CAN will send out SAE J1939", 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("auxiliary valve command 0 to 11", 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("-250 to -1 = Retract valve state", 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("0 = Neutral/initial valve state", 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("1 to 250 = Extend valve state", 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Exit button */
	ILI9341_fill_rect(85, 205, 273, 230, COLOR_GREEN);
	ILI9341_hollow_rect(85, 205, 273, 230, COLOR_BLACK);
	ILI9341_print_text("Exit frame now", 95, 210, COLOR_BLACK, COLOR_GREEN, 2);

	while(1) {
		int16_t adc[12];
		/* Control the PWM */
		uint8_t valve_state;
		for(uint8_t i = 0; i < 12; i++){
			float flow = 500.0f / 65535.0f * ((float)STM32_PLC_Analog_Input_ADC_Get_Raw(i)) - 250.0f;
			adc[i] = flow;
			if(flow > 1)
				valve_state = VALVE_STATE_EXTEND;
			else if(flow < -1)
				valve_state = VALVE_STATE_RETRACT;
			else
				valve_state = 0;
			uint8_t standard_flow = fabsf(flow);
			ISO_11783_Send_Auxiliary_Valve_Command(j1939, i, standard_flow, FAIL_SAFE_MODE_BLOCKED, valve_state);
		}

		/* ADC 0 to ADC 2 */
		char text[60];
		sprintf(text, "ADC0:%i ADC1:%i ADC2:%i", adc[0], adc[1], adc[2]);
		add_spaces(43, text);
		ILI9341_print_text(text, 55, 95, COLOR_YELLOW, COLOR_NAVY, 1);

		/* ADC3 to ADC5 */
		sprintf(text, "ADC3:%i ADC4:%i ADC5:%i", adc[3], adc[4], adc[5]);
		add_spaces(43, text);
		ILI9341_print_text(text, 55, 105, COLOR_YELLOW, COLOR_NAVY, 1);

		/* ADC6 to ADC8 */
		sprintf(text, "ADC6:%i ADC7:%i ADC8:%i", adc[6], adc[7], adc[8]);
		add_spaces(43, text);
		ILI9341_print_text(text, 55, 115, COLOR_YELLOW, COLOR_NAVY, 1);

		/* ADC9 to ADC11 */
		sprintf(text, "ADC9:%i ADC10:%i ADC11:%i", adc[9], adc[10], adc[11]);
		add_spaces(43, text);
		ILI9341_print_text(text, 55, 125, COLOR_YELLOW, COLOR_NAVY, 1);

		/* Logic for button */
		if (TSC2046_isPressed()) {
			TSC2046_GetTouchData();
			uint16_t X = lcd.myTsData.X;
			uint16_t Y = lcd.myTsData.Y;
			if (X >= 85 && X <= 273 && Y >= 205 && Y <= 230) {
				ILI9341_hollow_rect(85, 205, 273, 230, COLOR_MAGENTA);
				break;
			}
		}
	}

	/* Exit */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}

static void add_spaces(uint8_t length, char text[]){
	/* This is for removing old values from LCD */
	for(uint8_t i = strlen(text); i < length; i++)
		text[i] = ' ';
	text[length] = '\0'; /* C-String termination */
}
