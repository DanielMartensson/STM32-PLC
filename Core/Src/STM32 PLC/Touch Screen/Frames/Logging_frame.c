/*
 * Logging_frame.c
 *
 *  Created on: 24 juli 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

void STM32_PLC_LCD_Show_Logging_Frame(J1939 *j1939, uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	char text[200];
	ILI9341_print_text("Logging to a SD card", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Check the space */
	uint32_t total_space;
	uint32_t free_space;
	FRESULT status = STM32_PLC_SD_Mont_Card();
	if(status == FR_OK) {
		STM32_PLC_SD_Check_Space(&total_space, &free_space);
		sprintf(text, "Total space:%lu", total_space);
		ILI9341_print_text(text, 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "Free space:%lu", free_space);
		ILI9341_print_text(text, 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
	} else {
		ILI9341_print_text("Error:Could get the space", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
		sprintf(text, "SD mount error with FatFS code:%i", status);
		STM32_PLC_LCD_Show_Information_OK_Dialog(text);
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Star logging button */
	uint8_t x1 = 95;
	uint8_t y1 = 205;
	uint16_t x2 = 260;
	uint8_t y2 = 230;
	ILI9341_fill_rect(x1, y1, x2, y2, COLOR_GREEN);
	ILI9341_hollow_rect(x1, y1, x2, y2, COLOR_BLACK);
	ILI9341_print_text("Start logging", 100, 210, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for request button */
	STM32_PLC_LCD_Call_One_Button_Logic(x1, y1, x2, y2);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to log to file?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* You entered choice 1 - Show numpad */
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter a log number") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Open a file */
	sprintf(text, "%i.CSV", (uint16_t)number_value);
	STM32_PLC_SD_Create_New_File_With_Read_Write(text, "", true);
	STM32_PLC_SD_Open_Existing_File_With_Write(text);
	STM32_PLC_SD_Write_File("ID,Day,Hour,Minute,Second,Millisecond,");
	STM32_PLC_SD_Write_File("ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7,ADC8,ADC9,ADC10,ADC11,");
	STM32_PLC_SD_Write_File("DADC0,DADC1,DADC2,DADC3,DADC4,");
	STM32_PLC_SD_Write_File("I0,I1,I2,I3,I4,I5,I6,I7,");
	STM32_PLC_SD_Write_File("E0,E1,");
	STM32_PLC_SD_Write_File("IC0,IC1,");
	STM32_PLC_SD_Write_File("DAC0,DAC1,DAC2,");
	STM32_PLC_SD_Write_File("PWM0,PWM1,PWM2,PWM3,PWM4,PWM5,PWM6,PWM7,PULSE0,PULSE1,PULSE2,PULSE3\n");

	/* Sample time */
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter sample time between 1 and 65535") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint16_t sample_time;
	if(number_value < 1)
		sample_time = 1;
	else if(number_value > 0xFFFF)
		sample_time = 0xFFFF;
	else
		sample_time = (uint16_t) number_value;

	/* Show main frame */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);

	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Logging values and time", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Stop logging button */
	ILI9341_fill_rect(x1, y1, x2, y2, COLOR_RED);
	ILI9341_hollow_rect(x1, y1, x2, y2, COLOR_BLACK);
	ILI9341_print_text("Stop logging", 105, 210, COLOR_BLACK, COLOR_RED, 2);

	/* Do the logging process */
	uint16_t milliseconds = 0;
	uint8_t seconds = 0;
	uint8_t minutes = 0;
	uint8_t hours = 0;
	uint8_t days = 0;
	uint16_t counter = 0;
	STM32_PLC_Pulse_Count_Reset();
	uint32_t ID = 0; /* This is the primary key for counting how many samples we have */
	while (!STM32_PLC_Digital_Input_Get_Stop()) {
		/* Execute control program for every cycle */
		STM32_PLC_LCD_Execute_Control_Program(j1939);

		/* Write line for every sample time */
		if(counter >= sample_time) {
			ID++;
			sprintf(text, "%lu,%i,%i,%i,%i,%i,",
					ID,
					days,
					hours,
					minutes,
					seconds,
					milliseconds);
			STM32_PLC_SD_Write_File(text);

			sprintf(text, "%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,",
					STM32_PLC_Analog_Input_ADC_Get(0),
					STM32_PLC_Analog_Input_ADC_Get(1),
					STM32_PLC_Analog_Input_ADC_Get(2),
					STM32_PLC_Analog_Input_ADC_Get(3),
					STM32_PLC_Analog_Input_ADC_Get(4),
					STM32_PLC_Analog_Input_ADC_Get(5),
					STM32_PLC_Analog_Input_ADC_Get(6),
					STM32_PLC_Analog_Input_ADC_Get(7),
					STM32_PLC_Analog_Input_ADC_Get(8),
					STM32_PLC_Analog_Input_ADC_Get(9),
					STM32_PLC_Analog_Input_ADC_Get(10),
					STM32_PLC_Analog_Input_ADC_Get(11));
			STM32_PLC_SD_Write_File(text);

			sprintf(text, "%0.2f,%0.2f,%0.2f,%0.2f,%0.2f,",
					STM32_PLC_Analog_Input_DADC_Get(0),
					STM32_PLC_Analog_Input_DADC_Get(1),
					STM32_PLC_Analog_Input_DADC_Get(2),
					STM32_PLC_Analog_Input_DADC_Get(3),
					STM32_PLC_Analog_Input_DADC_Get(4));
			STM32_PLC_SD_Write_File(text);

			sprintf(text, "%i,%i,%i,%i,%i,%i,%i,%i,",
					STM32_PLC_Digital_Input_Get(0),
					STM32_PLC_Digital_Input_Get(1),
					STM32_PLC_Digital_Input_Get(2),
					STM32_PLC_Digital_Input_Get(3),
					STM32_PLC_Digital_Input_Get(4),
					STM32_PLC_Digital_Input_Get(5),
					STM32_PLC_Digital_Input_Get(6),
					STM32_PLC_Digital_Input_Get(7));
			STM32_PLC_SD_Write_File(text);

			sprintf(text, "%f,%f,",
					STM32_PLC_Encoder_Get(0),
					STM32_PLC_Encoder_Get(1));
			STM32_PLC_SD_Write_File(text);

			sprintf(text, "%f,%f,",
					STM32_PLC_Input_Capture_Get(0),
					STM32_PLC_Input_Capture_Get(1));
			STM32_PLC_SD_Write_File(text);

			sprintf(text, "%i,%i,%i,",
					STM32_PLC_Analog_Output_Get(0),
					STM32_PLC_Analog_Output_Get(1),
					STM32_PLC_Analog_Output_Get(2));
			STM32_PLC_SD_Write_File(text);

			sprintf(text, "%i,%i,%i,%i,%i,%i,%i,%i,",
					STM32_PLC_PWM_Get(0),
					STM32_PLC_PWM_Get(1),
					STM32_PLC_PWM_Get(2),
					STM32_PLC_PWM_Get(3),
					STM32_PLC_PWM_Get(4),
					STM32_PLC_PWM_Get(5),
					STM32_PLC_PWM_Get(6),
					STM32_PLC_PWM_Get(7));
			STM32_PLC_SD_Write_File(text);

			sprintf(text, "%lu,%lu,%lu,%lu,\n",
					STM32_PLC_Pulse_Count_Get(0),
					STM32_PLC_Pulse_Count_Get(1),
					STM32_PLC_Pulse_Count_Get(2),
					STM32_PLC_Pulse_Count_Get(3));
			STM32_PLC_SD_Write_File(text);

			/* Reset counter */
			counter = 0;
		}

		/* For every iteration, do count */
		counter++;

		/* Compute time */
		milliseconds++;
		if(milliseconds >= 1000){
			milliseconds = 0;
			seconds++;
		}
		if(seconds >= 60){
			seconds = 0;
			minutes++;
		}
		if(minutes >= 60){
			minutes = 0;
			hours++;
		}
		if(hours >= 24) {
			hours = 0;
			days++;
		}
		if(days >= 255)
			days = 0;

		/* One 1 ms is necessary */
		HAL_Delay(1);

		/* Show plot frame */
		STM32_PLC_LCD_Show_Plot_Frame();

		/* Check if we want to abort if we press the button */
		if (TSC2046_isPressed()) {
			TSC2046_GetTouchData();
			uint16_t X = lcd.myTsData.X;
			uint16_t Y = lcd.myTsData.Y;
			if (X >= x1 && X <= x2 && Y >= y1 && Y <= y2) {
				ILI9341_hollow_rect(x1, y1, x2, y2, COLOR_MAGENTA);
				break;
			}
		}
	}

	/* Close file */
	STM32_PLC_SD_Close_File();
	STM32_PLC_SD_Unmount_Card();

	/* This causes that PWM, analog output is OFF - Safety */
	STM32_PLC_PWM_Reset();
	STM32_PLC_Analog_Output_Reset();

	/* Exit */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}
