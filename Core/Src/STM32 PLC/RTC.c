/*
 * RTC.c
 *
 *  Created on: Jun 17, 2021
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"

static RTC_HandleTypeDef *real_time_clock;

void STM32_PLC_Start_RTC(RTC_HandleTypeDef *hrtc) {
	real_time_clock = hrtc;
}

void STM32_PLC_RTC_Get_Date(uint8_t *date, uint8_t *month, uint8_t *year) {
	RTC_DateTypeDef sDate = {0};
	HAL_RTC_GetDate(real_time_clock, &sDate, RTC_FORMAT_BIN);
	*date = sDate.Date;
	*month = sDate.Month;
	*year = sDate.Year;
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

void STM32_PLC_RTC_Set_AlarmA(uint8_t minutes, uint8_t hours, uint8_t date) {
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
	HAL_RTC_SetAlarm(real_time_clock, &sAlarm, RTC_FORMAT_BIN);
}

void STM32_PLC_RTC_Set_AlarmB(uint8_t minutes, uint8_t hours, uint8_t week_day) {
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
	HAL_RTC_SetAlarm(real_time_clock, &sAlarm, RTC_FORMAT_BIN);
}

bool STM32_PLC_RTC_Get_AlarmAB(uint32_t alarm, uint8_t *minutes, uint8_t *hours, uint8_t *date, uint8_t *week_day){
	/* Get the alarm, time and date */
	RTC_AlarmTypeDef sAlarm = {0};
	HAL_RTC_GetAlarm(real_time_clock, &sAlarm, alarm, RTC_FORMAT_BIN);
	RTC_TimeTypeDef sTime = {0};
	HAL_RTC_GetTime(real_time_clock, &sTime, RTC_FORMAT_BIN);
	RTC_DateTypeDef sDate = {0};
	HAL_RTC_GetDate(real_time_clock, &sDate, RTC_FORMAT_BIN);
	switch(alarm) {
	case RTC_ALARM_A:
		*minutes = sAlarm.AlarmTime.Minutes;
		*hours = sAlarm.AlarmTime.Hours;
		*date = sAlarm.AlarmDateWeekDay;
		/* Notice that hours and date need to be equal but minutes need to be equal or greater */
		if(sTime.Hours == *hours && sTime.Minutes >= *minutes && sDate.Date == *date)
			return true;
		else
			return false;
	case RTC_ALARM_B:
		*minutes = sAlarm.AlarmTime.Minutes;
		*hours = sAlarm.AlarmTime.Hours;
		*week_day = sAlarm.AlarmDateWeekDay;
		/* Notice that hours and week day need to be equal but minutes need to be equal or greater */
		if(sTime.Hours == *hours && sTime.Minutes >= *minutes && sDate.WeekDay == *week_day)
			return true;
		else
			return false;
	default:
		return false;
	}
}

