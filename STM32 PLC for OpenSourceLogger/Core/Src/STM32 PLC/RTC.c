/*
 * RTC.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

static RTC_HandleTypeDef *real_time_clock;
static bool alarm_A_enabled;
static bool alarm_B_enabled;
static bool alarm_A_is_active;
static bool alarm_B_is_active;

void STM32_PLC_RTC(RTC_HandleTypeDef *hrtc) {
	real_time_clock = hrtc;

	/* Get alarm enables */
	STM32_PLC_Flash_Get_Alarm_Enables(&alarm_A_enabled, &alarm_B_enabled);
}

void STM32_PLC_RTC_Get_Date(uint8_t *week_day, uint8_t *date, uint8_t *month, uint8_t *year) {
	RTC_DateTypeDef sDate = {0};
	HAL_RTC_GetDate(real_time_clock, &sDate, RTC_FORMAT_BIN);
	*date = sDate.Date;
	*month = sDate.Month;
	*year = sDate.Year;
	*week_day = sDate.WeekDay;
}

void STM32_PLC_RTC_Set_Date(uint8_t date, uint8_t week_day, uint8_t month, uint8_t year) {
	RTC_DateTypeDef sDate = {0};
	sDate.Date = date;
	sDate.Month = month;
	sDate.Year = year;
	sDate.WeekDay = week_day;
	HAL_RTC_SetDate(real_time_clock, &sDate, RTC_FORMAT_BIN);
}

void STM32_PLC_RTC_Get_Time(uint8_t *seconds, uint8_t *minutes, uint8_t *hours) {
	RTC_TimeTypeDef sTime = {0};
	HAL_RTC_GetTime(real_time_clock, &sTime, RTC_FORMAT_BIN);
	*seconds = sTime.Seconds;
	*minutes = sTime.Minutes;
	*hours = sTime.Hours;
}

void STM32_PLC_RTC_Set_Time(uint8_t seconds, uint8_t minutes, uint8_t hours) {
	RTC_TimeTypeDef sTime = {0};
	sTime.Seconds = seconds;
	sTime.Minutes = minutes;
	sTime.Hours = hours;
	sTime.TimeFormat = RTC_FORMAT_BIN;
	HAL_RTC_SetTime(real_time_clock, &sTime, RTC_FORMAT_BIN);
}

void STM32_PLC_RTC_Get_Alarm_A(uint8_t *date, uint8_t *hours, uint8_t *minutes) {
	RTC_AlarmTypeDef sAlarm = {0};
	HAL_RTC_GetAlarm(real_time_clock, &sAlarm, RTC_ALARM_A, RTC_FORMAT_BIN);
	*date = sAlarm.AlarmDateWeekDay;
	*hours = sAlarm.AlarmTime.Hours;
	*minutes = sAlarm.AlarmTime.Minutes;
}

void STM32_PLC_RTC_Get_Alarm_B(uint8_t *week_day, uint8_t *hours, uint8_t *minutes) {
	RTC_AlarmTypeDef sAlarm = {0};
	HAL_RTC_GetAlarm(real_time_clock, &sAlarm, RTC_ALARM_B, RTC_FORMAT_BIN);
	*week_day = sAlarm.AlarmDateWeekDay;
	*hours = sAlarm.AlarmTime.Hours;
	*minutes = sAlarm.AlarmTime.Minutes;
}

void STM32_PLC_RTC_Set_Alarm_A(uint8_t minutes, uint8_t hours, uint8_t date) {
	RTC_AlarmTypeDef sAlarm = {0};
	sAlarm.AlarmTime.Hours = hours;
	sAlarm.AlarmTime.Minutes = minutes;
	sAlarm.AlarmTime.Seconds = 0;
	sAlarm.AlarmTime.SubSeconds = 0;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmTime.TimeFormat = RTC_FORMAT_BIN;
	sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	sAlarm.AlarmDateWeekDay = date;
	sAlarm.Alarm = RTC_ALARM_A;
	HAL_RTC_SetAlarm_IT(real_time_clock, &sAlarm, RTC_FORMAT_BIN);
}

void STM32_PLC_RTC_Set_Alarm_B(uint8_t minutes, uint8_t hours, uint8_t week_day) {
	RTC_AlarmTypeDef sAlarm = {0};
	sAlarm.AlarmTime.Hours = hours;
	sAlarm.AlarmTime.Minutes = minutes;
	sAlarm.AlarmTime.Seconds = 0;
	sAlarm.AlarmTime.SubSeconds = 0;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmTime.TimeFormat = RTC_FORMAT_BIN;
	sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_WEEKDAY;
	sAlarm.AlarmDateWeekDay = week_day;
	sAlarm.Alarm = RTC_ALARM_B;
	HAL_RTC_SetAlarm_IT(real_time_clock, &sAlarm, RTC_FORMAT_BIN);
}

void HAL_RTCEx_AlarmBEventCallback(RTC_HandleTypeDef *hrtc){
	if(alarm_B_enabled){
		if(!alarm_B_is_active){
			alarm_B_is_active = true;
			STM32_PLC_PWM_Set(0, 0xFFFF);
			STM32_PLC_PWM_Set(1, 0xFFFF);
			STM32_PLC_PWM_Set(2, 0xFFFF);
			STM32_PLC_PWM_Set(3, 0xFFFF);
		}
	}
}

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc){
	if(alarm_A_enabled){
		if(!alarm_A_is_active){
			alarm_A_is_active = true;
			STM32_PLC_PWM_Set(4, 0xFFFF);
			STM32_PLC_PWM_Set(5, 0xFFFF);
			STM32_PLC_PWM_Set(6, 0xFFFF);
			STM32_PLC_PWM_Set(7, 0xFFFF);
		}
	}
}

void STM32_PLC_RTC_Deactivate_Alarm_A(){
	alarm_A_is_active = false;
	STM32_PLC_PWM_Set(4, 0x0);
	STM32_PLC_PWM_Set(5, 0x0);
	STM32_PLC_PWM_Set(6, 0x0);
	STM32_PLC_PWM_Set(7, 0x0);
}

void STM32_PLC_RTC_Enable_Alarm_A(bool enable){
	alarm_A_enabled = enable;
	STM32_PLC_Flash_Set_Alarm_Enable(alarm_A_enabled, alarm_B_enabled);
	if(!enable)
		STM32_PLC_RTC_Deactivate_Alarm_A();
}

bool STM32_PLC_RTC_Alarm_A_Is_Enabled(){
	return alarm_A_enabled;
}

bool STM32_PLC_RTC_Alarm_A_Is_Activated(){
	return alarm_A_is_active;
}

void STM32_PLC_RTC_Deactivate_Alarm_B(){
	alarm_B_is_active = false;
	STM32_PLC_PWM_Set(0, 0x0);
	STM32_PLC_PWM_Set(1, 0x0);
	STM32_PLC_PWM_Set(2, 0x0);
	STM32_PLC_PWM_Set(3, 0x0);
}

void STM32_PLC_RTC_Enable_Alarm_B(bool enable){
	alarm_B_enabled = enable;
	STM32_PLC_Flash_Set_Alarm_Enable(alarm_A_enabled, alarm_B_enabled);
	if(!enable)
		STM32_PLC_RTC_Deactivate_Alarm_B();
}

bool STM32_PLC_RTC_Alarm_B_Is_Enabled(){
	return alarm_B_enabled;
}

bool STM32_PLC_RTC_Alarm_B_Is_Activated(){
	return alarm_B_is_active;
}

