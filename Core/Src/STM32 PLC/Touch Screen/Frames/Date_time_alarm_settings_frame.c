/*
 * Date_time_alarm_settings_frame.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"

static uint8_t show_numpad_question(char title[], uint8_t *frame_id, uint8_t min_value, uint8_t max_value, uint8_t *value);

void STM32_PLC_LCD_Show_Date_Time_Alarm_Settings_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Configure the date and time and alarm", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Show the current date and time */
	uint8_t year, month, week_day, date, hours, minutes, seconds;
	STM32_PLC_RTC_Get_Date(&date, &month, &year);
	STM32_PLC_RTC_Get_Time(&seconds, &minutes, &hours);
	char text[40];
	ILI9341_print_text("Current date and time:", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "Date:%i-%i-%i Time:%i:%i:%i", year + 2000, month, date, hours, minutes, seconds);
	ILI9341_print_text(text, 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Print Alarm A */
	bool active = STM32_PLC_RTC_Get_AlarmAB(RTC_ALARM_A, &minutes, &hours, &date, &week_day);
	ILI9341_print_text("Current alarm A:", 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "Date:%i Time:%i:%i Active:%i", date, hours, minutes, active);
	ILI9341_print_text(text, 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Print Alarm B */
	active = STM32_PLC_RTC_Get_AlarmAB(RTC_ALARM_B, &minutes, &hours, &date, &week_day);
	ILI9341_print_text("Current alarm B:", 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "Week day:%i Time:%i:%i Active:%i", week_day, hours, minutes, active);
	ILI9341_print_text(text, 55, 85, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Button */
	ILI9341_fill_rect(65, 195, 300, 220, COLOR_GREEN);
	ILI9341_hollow_rect(65, 195, 300, 220, COLOR_BLACK);
	ILI9341_print_text("Set date time alarm", 70, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for button */
	STM32_PLC_LCD_Call_One_Button_Logic(65, 195, 300, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to set date and time?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Enter date and time */
	if(show_numpad_question("Enter year between 0 and 99", frame_id, 0, 99, &year))
		return;
	if(show_numpad_question("Enter month between 1 and 12", frame_id, 1, 11, &month))
		return;
	if(show_numpad_question("Enter week day between 1 and 7", frame_id, 1, 7, &week_day))
		return;
	if(show_numpad_question("Enter date between 1 and 31", frame_id, 1, 31, &date))
		return;
	if(show_numpad_question("Enter hours between 0 and 23", frame_id, 0, 23, &hours))
		return;
	if(show_numpad_question("Enter minutes between 0 and 59", frame_id, 0, 59, &minutes))
		return;

	/* Set date and time where seconds is 0 */
	STM32_PLC_RTC_Set_Date(date, week_day, month, year);
	STM32_PLC_RTC_Set_Time(0, minutes, hours);

	/* Enter alarm A */
	if(show_numpad_question("Alarm A:Enter hours between 0 and 23", frame_id, 0, 23, &hours))
		return;
	if(show_numpad_question("Alarm A:Enter minutes between 0 and 59", frame_id, 0, 59, &minutes))
		return;
	if(show_numpad_question("Alarm A:Enter date between 1 and 31", frame_id, 1, 31, &date))
		return;

	/* Set alarm A */
	STM32_PLC_RTC_Set_AlarmA(minutes, hours, date);

	/* Enter alarm B */
	if(show_numpad_question("Alarm B:Enter hours between 0 and 23", frame_id, 0, 23, &hours))
		return;
	if(show_numpad_question("Alarm B:Enter minutes between 0 and 59", frame_id, 0, 59, &minutes))
		return;
	if(show_numpad_question("Alarm B:Enter week day between 1 and 7", frame_id, 1, 7, &week_day))
		return;

	/* Set alarm B */
	STM32_PLC_RTC_Set_AlarmB(minutes, hours, week_day);

	/* Exit */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}

static uint8_t show_numpad_question(char title[], uint8_t *frame_id, uint8_t min_value, uint8_t max_value, uint8_t *value){
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, title) == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return 1;
	}
	if(number_value < min_value)
		*value = min_value;
	else if(number_value > max_value)
		*value = max_value;
	else
		*value = (uint32_t) number_value;
	return 0;
}
