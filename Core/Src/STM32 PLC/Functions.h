/*
 * Functions.h
 *
 *  Created on: Jun 13, 2021
 *      Author: Daniel Mårtensson
 */

#ifndef SRC_STM32_PLC_FUNCTIONS_H_
#define SRC_STM32_PLC_FUNCTIONS_H_

#include "main.h"
#include <stdbool.h>
#include "usbd_cdc_if.h"
#include "Open SAE J1939/SAE J1939/SAE J1939-71 Application Layer/Application_Layer.h"
#include "Open SAE J1939/SAE J1939/SAE J1939-73 Diagnostics Layer/Diagnostics_Layer.h"
#include "Open SAE J1939/SAE J1939/SAE J1939-81 Network Management Layer/Network_Management_Layer.h"
#include "Open SAE J1939/ISO 11783/ISO 11783-7 Application Layer/Application_Layer.h"
#include "Open SAE J1939/Open SAE J1939/Open_SAE_J1939.h"
#include "Touch Screen/Touch_screen.h"
#include "ff.h"

/* This describes the program number */
void STM32_PLC_LED(uint8_t program_number);

/* PWM functions */
void STM32_PLC_Start_PWM(TIM_HandleTypeDef *htim2, TIM_HandleTypeDef *htim5);
void STM32_PLC_PWM_Set(uint8_t i, uint16_t ON_Period);
uint16_t STM32_PLC_PWM_Get(uint8_t i);
void STM32_PLC_PWM_Reset();
void STM32_PLC_PWM0_To_PWM3_Set_Prescaler(uint16_t prescaler);
void STM32_PLC_PWM4_To_PWM7_Set_Prescaler(uint16_t prescaler);

/* Input capture */
void STM32_PLC_Start_Input_Capture(TIM_HandleTypeDef* htim17, TIM_HandleTypeDef* htim16);
float STM32_PLC_Input_Capture_Get(uint8_t i);

/* Counters */
void STM32_PLC_Start_Encoder(TIM_HandleTypeDef *htim4, TIM_HandleTypeDef *htim19);
float STM32_PLC_Encoder_Get(uint8_t i);
int16_t STM32_PLC_Encoder_Get_Raw(uint8_t i);
void STM32_PLC_Encoder_Set_Pulses_Per_Revolutions(uint8_t i, uint16_t pulses_per_revolution);

/* Pulse counters */
void STM32_PLC_Pulse_Count_Set(uint8_t i);
uint32_t STM32_PLC_Pulse_Count_Get(uint8_t i);
void STM32_PLC_Pulse_Count_Reset();

/* Analog Output */
void STM32_PLC_Start_Analog_Output(DAC_HandleTypeDef *hdac1, DAC_HandleTypeDef *hdac2, TIM_HandleTypeDef *htim6);
void STM32_PLC_Analog_Output_Set(uint8_t i, uint16_t output);
void STM32_PLC_Analog_Output_Reset();
uint16_t STM32_PLC_Analog_Output_Get(uint8_t i);

/* Digital Input */
bool STM32_PLC_Digital_Input_Get(uint8_t i);
bool STM32_PLC_Digital_Input_Get_Stop();

/* Analog input */
void STM32_PLC_Start_Analog_Input(TIM_HandleTypeDef* htim12, TIM_HandleTypeDef* htim13, SDADC_HandleTypeDef* hsdadc1, SDADC_HandleTypeDef* hsdadc2, SDADC_HandleTypeDef* hsdadc3);
void STM32_PLC_Analog_Input_Set_Gain_Offset(uint8_t sdadc, uint8_t configuration_index, uint8_t gain, uint16_t offset);
float STM32_PLC_Analog_Input_ADC_Get(uint8_t i);
uint16_t STM32_PLC_Analog_Input_ADC_Get_Raw(uint8_t i);
float STM32_PLC_Analog_Input_DADC_Get(uint8_t i);
int16_t STM32_PLC_Analog_Input_DADC_Get_Raw(uint8_t i);
void STM32_PLC_Analog_Input_ADC_Set_Calibration(uint8_t i, float min_value, float max_value, float bias_value);
void STM32_PLC_Analog_Input_DADC_Set_Calibration(uint8_t i, float min_value, float max_value, float bias_value);

/* LCD */
void STM32_PLC_Start_LCD(SPI_HandleTypeDef *lcdSpi, SPI_HandleTypeDef *touchSpi, GPIO_TypeDef *LCD_CS_PORT, uint16_t LCD_CS_PIN, GPIO_TypeDef *LCD_DC_PORT, uint16_t LCD_DC_PIN, GPIO_TypeDef *LCD_RESET_PORT, uint16_t LCD_RESET_PIN, GPIO_TypeDef *TOUCH_CS_PORT, uint16_t TOUCH_CS_PIN);
void STM32_PLC_LCD_Calibrate_Touch();
void STM32_PLC_LCD_Get_Touch_Calibration_Parameters(float *Scale_X, float *Scale_Y, float *Bias_X, float *Bias_Y);
void STM32_PLC_LCD_Set_Touch_Calibration_Parameters(float *Scale_X, float *Scale_Y, float *Bias_X, float *Bias_Y);
void STM32_PLC_LCD_Get_Touch_Data();

/* RTC */
void STM32_PLC_Start_RTC(RTC_HandleTypeDef *hrtc);
void STM32_PLC_RTC_Get_Date(uint8_t *date, uint8_t *month, uint8_t *year);
void STM32_PLC_RTC_Set_Date(uint8_t date, uint8_t week_day, uint8_t month, uint8_t year);
void STM32_PLC_RTC_Get_Time(uint8_t *seconds, uint8_t *minutes, uint8_t *hours);
void STM32_PLC_RTC_Set_Time(uint8_t seconds, uint8_t minutes, uint8_t hours);
void STM32_PLC_RTC_Set_AlarmA(uint8_t minutes, uint8_t hours, uint8_t date);
void STM32_PLC_RTC_Set_AlarmB(uint8_t minutes, uint8_t hours, uint8_t week_day);
bool STM32_PLC_RTC_Get_AlarmAB(uint32_t alarm, uint8_t *minutes, uint8_t *hours, uint8_t *date, uint8_t *week_day);

/* SD Card */
void STM32_PLC_Start_SD(SPI_HandleTypeDef *hspi, GPIO_TypeDef *SD_CS_PORT, uint16_t SD_CS_PIN);
FRESULT STM32_PLC_SD_Mont_Card();
FRESULT STM32_PLC_SD_Unmount_Card();
FRESULT STM32_PLC_SD_Open_Existing_File_With_Read(char filename[]);
FRESULT STM32_PLC_SD_Open_Existing_File_With_Write(char filename[]);
FRESULT STM32_PLC_SD_Create_New_File_With_Read_Write(char filename[], char initial_string[], bool overwrite);
FRESULT STM32_PLC_SD_Close_File();
FRESULT STM32_PLC_SD_Check_Space(uint32_t *total_space, uint32_t *free_space);
char* STM32_PLC_SD_Read_File(char text[], int len);
int STM32_PLC_SD_Write_File(char text[]);

/* UART */
void STM32_PLC_UART_Start(UART_HandleTypeDef *huart1);
void STM32_PLC_UART_Transmit(uint8_t *pData, uint16_t Size);
uint8_t STM32_PLC_UART_Receive(uint8_t *pData);

/* CAN */
void STM32_PLC_Start_CAN(CAN_HandleTypeDef *hcan, J1939 *j1939);
HAL_StatusTypeDef STM32_PLC_CAN_Transmit(uint8_t TxData[], CAN_TxHeaderTypeDef *TxHeader);
void STM32_PLC_CAN_Get_ID_Data(uint32_t *ID, uint8_t data[], bool *is_new_message);

/* Start up */
void STM32_PLC_Initial_Startup(J1939 *j1939);

#endif /* SRC_STM32_PLC_FUNCTIONS_H_ */
