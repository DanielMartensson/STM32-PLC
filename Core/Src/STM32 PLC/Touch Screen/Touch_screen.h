/*
 * Touch_screen.h
 *
 *  Created on: Jul 23, 2021
 *      Author: Daniel Mårtensson
 */

#ifndef SRC_STM32_PLC_TOUCH_SCREEN_TOUCH_SCREEN_H_
#define SRC_STM32_PLC_TOUCH_SCREEN_TOUCH_SCREEN_H_

/* Necessary */
#include "../Open SAE J1939/Open SAE J1939/Structs.h"
#include "../Open SAE J1939/SAE J1939/SAE J1939 Enums/Enum_NAME.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#define DELIMITER "Å" /* This a separator for the text files - ASCII 143 - Å has the origins from 14th in Sweden */

/* Frames with no frame id */
void STM32_PLC_LCD_Show_Intro_Frame();
void STM32_PLC_LCD_Show_Main_Frame(uint8_t *frame_id, bool change_only_ABC_buttons);
uint8_t STM32_PLC_LCD_Show_Numpad_Frame(bool decimalbutton_show, bool minusbutton_show, float *number_value, char title[]);
uint8_t STM32_PLC_LCD_Show_Keyboard_Frame(char word[], char title[]);
void STM32_PLC_LCD_Show_Plot_Frame();

/* Frame id 0 */
void STM32_PLC_LCD_Show_Measurement_And_Time_Frame(uint8_t *frame_id);
void STM32_PLC_LCD_Show_Analog_Calibration_Frame(uint8_t *frame_id);
void STM32_PLC_LCD_Show_PWM_Frequency_Settings_Frame(uint8_t *frame_id);

/* Frame id 1 */
void STM32_PLC_LCD_Show_Logging_Frame(J1939 *j1939, uint8_t *frame_id);
void STM32_PLC_LCD_Show_Control_Program_Settings_Frame(uint8_t *frame_id);
void STM32_PLC_LCD_Show_Date_Time_Alarm_Settings_Frame(uint8_t *frame_id);

/* Frame id 2 */
void STM32_PLC_LCD_Show_SAE_J1939_Request_Frame(J1939 *j1939, uint8_t *frame_id);
void STM32_PLC_LCD_Show_SAE_J1939_Address_Frame(J1939 *j1939, uint8_t *frame_id);
void STM32_PLC_LCD_Show_SAE_J1939_Commanded_Address_Frame(J1939 *j1939, uint8_t *frame_id);

/* Frame id 3 */
void STM32_PLC_LCD_Show_SAE_J1939_This_ECU_DM1_Frame(J1939 *j1939, uint8_t *frame_id);
void STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_DM1_Frame(J1939 *j1939, uint8_t *frame_id);
void STM32_PLC_LCD_Show_SAE_J1939_This_ECU_DM2_Frame(J1939 *j1939, uint8_t *frame_id);

/* Frame id 4 */
void STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_DM2_Frame(J1939 *j1939, uint8_t *frame_id);
void STM32_PLC_LCD_Show_SAE_J1939_This_ECU_Name_Frame(J1939 *j1939, uint8_t *frame_id);
void STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_Name_Frame(J1939 *j1939, uint8_t *frame_id);

/* Frame id 5 */
void STM32_PLC_LCD_Show_SAE_J1939_This_ECU_Identifications_Frame(J1939 *j1939, uint8_t *frame_id);
void STM32_PLC_LCD_Show_SAE_J1939_Other_ECU_Identifications_Frame(J1939 *j1939, uint8_t *frame_id);
void STM32_PLC_LCD_Show_Encoder_Revolutions_Settings_Frame(uint8_t *frame_id);

/* Frame id 6 */
void STM32_PLC_LCD_Show_SDADC_Settings_Frame(uint8_t *frame_id);

/* Dialogs */
uint8_t STM32_PLC_LCD_Show_Question_Yes_No_Dialog(char question[]);
uint8_t STM32_PLC_LCD_Show_Information_OK_Dialog(char information[]);

/* Logics */
void STM32_PLC_LCD_Call_Main_Logic(uint8_t *frame_id, J1939 *j1939);
uint8_t STM32_PLC_LCD_Call_Numpad_Logic(bool decimalbutton_show, bool minusbutton_show, float *number_value);
uint8_t STM32_PLC_LCD_Call_Keyboard_Logic(char word[]);
uint8_t STM32_PLC_LCD_Call_Two_Button_Logic(uint16_t b1_x1, uint16_t b1_y1, uint16_t b1_x2, uint16_t b1_y2, uint16_t b2_x1, uint16_t b2_y1, uint16_t b2_x2, uint16_t b2_y2);
uint8_t STM32_PLC_LCD_Call_One_Button_Logic(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

/* Automatic Control Program */
void STM32_PLC_LCD_Set_Control_Program(uint8_t program_number);
void STM32_PLC_LCD_Set_Program_Parameters(float parameters[]);
uint8_t STM32_PLC_LCD_Get_Control_Program();
void STM32_PLC_LCD_Execute_Control_Program(J1939 *j1939);

#endif /* SRC_STM32_PLC_TOUCH_SCREEN_TOUCH_SCREEN_H_ */
