/*
 * Main_Logic.c
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"

void STM32_PLC_LCD_Call_Main_Logic(uint8_t *frame_id, J1939 *j1939) {
	if (TSC2046_isPressed()) {
		TSC2046_GetTouchData();
		uint16_t X = lcd.myTsData.X;
		uint16_t Y = lcd.myTsData.Y;
		/* Check which button we are pressing on */
		if (X >= 8 && X <= 37 && Y >= 8 && Y <= 37) {            /* First icon */
			switch (*frame_id) {
			case 0:
				STM32_PLC_LCD_Show_Measurement_And_Time_Frame(frame_id);
				break;
			case 1:
				STM32_PLC_LCD_Show_Logging_Frame(j1939, frame_id);
				break;
			case 2:
				STM32_PLC_LCD_Show_SAE_J1939_Request_Frame(j1939, frame_id);
				break;
			case 3:
				STM32_PLC_LCD_Show_SAE_J1939_This_ECU_DM1_Frame(j1939, frame_id);
				break;
			case 4:
				STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_DM2_Frame(j1939, frame_id);
				break;
			case 5:
				STM32_PLC_LCD_Show_SAE_J1939_This_ECU_Identifications_Frame(j1939, frame_id);
				break;
			case 6:
				STM32_PLC_LCD_Show_SDADC_Settings_Frame(frame_id);
				break;
			}
		} else if (X >= 8 && X <= 37 && Y >= 55 && Y <= 94) {    /* Second icon */
			switch (*frame_id) {
			case 0:
				STM32_PLC_LCD_Show_Analog_Calibration_Frame(frame_id);
				break;
			case 1:
				STM32_PLC_LCD_Show_Control_Program_Settings_Frame(frame_id);
				break;
			case 2:
				STM32_PLC_LCD_Show_SAE_J1939_Address_Frame(j1939, frame_id);
				break;
			case 3:
				STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_DM1_Frame(j1939, frame_id);
				break;
			case 4:
				STM32_PLC_LCD_Show_SAE_J1939_This_ECU_Name_Frame(j1939, frame_id);
				break;
			case 5:
				STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_Identifications_Frame(j1939, frame_id);
				break;
			}
		} else if (X >= 8 && X <= 37 && Y >= 100 && Y <= 139) {  /* Third icon */
			switch (*frame_id) {
			case 0:
				STM32_PLC_LCD_Show_PWM_Frequency_Settings_Frame(frame_id);
				break;
			case 1:
				STM32_PLC_LCD_Show_Date_Time_Alarm_Settings_Frame(frame_id);
				break;
			case 2:
				STM32_PLC_LCD_Show_SAE_J1939_Commanded_Address_Frame(j1939, frame_id);
				break;
			case 3:
				STM32_PLC_LCD_Show_SAE_J1939_This_ECU_DM2_Frame(j1939, frame_id);
				break;
			case 4:
				STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_Name_Frame(j1939, frame_id);
				break;
			case 5:
				STM32_PLC_LCD_Show_Encoder_Revolutions_Settings_Frame(frame_id);
				break;
			}
		} else if (X >= 8 && X <= 37 && Y >= 146 && Y <= 185) {  /* Fourth icon */
			if (*frame_id > 0) {
				*frame_id = *frame_id - 1; /* Got to previous frame */
				STM32_PLC_LCD_Show_Main_Frame(frame_id, true);
			}
		} else if (X >= 8 && X <= 37 && Y >= 193 && Y <= 232) {  /* Fifth icon */
			if (*frame_id < 7) {
				*frame_id = *frame_id + 1; /* Go to next frame */
				STM32_PLC_LCD_Show_Main_Frame(frame_id, true);
			}
		}
	}
}
