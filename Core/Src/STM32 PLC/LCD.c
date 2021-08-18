/*
 * LCD.c
 *
 *  Created on: May 22, 2020
 *      Author: Daniel Mårtensson
 */

#include "Functions.h"
#include "Touch Screen/Hardware/ILI9341.h"

/*
 * Initialize LCD and touch
 * SPI settings:
 * CPHA = 1 Edge
 * Prescaler = 8 (be careful for this. Lower than 8 can cause trouble with the touch)
 * First bit = MBS first
 * CPOL = Low
 */
void STM32_PLC_Start_LCD(SPI_HandleTypeDef *lcdSpi, SPI_HandleTypeDef *touchSpi, GPIO_TypeDef *LCD_CS_PORT, uint16_t LCD_CS_PIN, GPIO_TypeDef *LCD_DC_PORT, uint16_t LCD_DC_PIN, GPIO_TypeDef *LCD_RESET_PORT, uint16_t LCD_RESET_PIN, GPIO_TypeDef *TOUCH_CS_PORT, uint16_t TOUCH_CS_PIN) {
	/* Copy SPI settings */
	lcd.lcdSpi = lcdSpi;
	lcd.LCD_CS_PORT = LCD_CS_PORT;
	lcd.LCD_CS_PIN = LCD_CS_PIN;
	lcd.LCD_DC_PORT = LCD_DC_PORT;
	lcd.LCD_DC_PIN = LCD_DC_PIN;
	HAL_GPIO_WritePin(lcd.LCD_DC_PORT, lcd.LCD_DC_PIN, GPIO_PIN_SET);
	lcd.LCD_RESET_PORT = LCD_RESET_PORT;
	lcd.LCD_RESET_PIN = LCD_RESET_PIN;
	HAL_GPIO_WritePin(lcd.LCD_RESET_PORT, lcd.LCD_RESET_PIN, GPIO_PIN_SET); /* Turn LCD ON */
	lcd._cp437 = 0; // False
	lcd.rotationNum = 1;

	/* Reset */
	ILI9341_send_command(ILI9341_RESET);                                     /* software reset command */
	HAL_Delay(100);
	ILI9341_send_command(ILI9341_DISPLAY_OFF);                               /* display off */

	/* Power Control */
	ILI9341_send_command(ILI9341_POWER1);                                    /* power control */
	ILI9341_send_data(0x26);                                                 /* GVDD = 4.75v */
	ILI9341_send_command(ILI9341_POWER2);                                    /* power control */
	ILI9341_send_data(0x11);                                                 /* AVDD = VCIx2, VGH = VCIx7, VGL =-VCIx3 */

	/* VCOM */
	ILI9341_send_command(ILI9341_VCOM1);                                     /* VCOM control */
	ILI9341_send_data(0x35);                                                 /* Set the VCOMH voltage (0x35 = 4.025v) */
	ILI9341_send_data(0x3e);                                                 /* Set the VCOML voltage (0x3E = -0.950v) */
	ILI9341_send_command(ILI9341_VCOM2);                                     /* VCOM control */
	ILI9341_send_data(0xbe);

	/* Memory Access Control */
	ILI9341_send_command(ILI9341_MAC);
	ILI9341_send_data(0x48);

	/* Pixel Format Set - 16-bit per pixel */
	ILI9341_send_command(ILI9341_PIXEL_FORMAT);
	ILI9341_send_data(0x55);

	ILI9341_send_command(ILI9341_FRC);
	ILI9341_send_data(0);
	ILI9341_send_data(0x1F);

	/* DDRAM */
	ILI9341_send_command(ILI9341_COLUMN_ADDR);                               /* column set */
	ILI9341_send_data(0x00);                                                 /* x0_HIGH---0 */
	ILI9341_send_data(0x00);                                                 /* x0_LOW----0 */
	ILI9341_send_data(0x00);                                                 /* x1_HIGH---240 */
	ILI9341_send_data(0xEF);                                                 /* x1_LOW----240 */
	ILI9341_send_command(ILI9341_PAGE_ADDR);                                 /* page address set */
	ILI9341_send_data(0x00);                                                 /* y0_HIGH---0 */
	ILI9341_send_data(0x00);                                                 /* y0_LOW----0 */
	ILI9341_send_data(0x01);                                                 /* y1_HIGH---320 */
	ILI9341_send_data(0x3F);                                                 /* y1_LOW----320 */

	ILI9341_send_command(ILI9341_TEARING_OFF);                               /* tearing effect off */
	//LCD_write_cmd(ILI9341_TEARING_ON);                                    /* tearing effect on */
	//LCD_write_cmd(ILI9341_DISPLAY_INVERSION);                             /* display inversion */
	ILI9341_send_command(ILI9341_Entry_Mode_Set);                            /* entry mode set */
	/* Deep Standby Mode: OFF
	 * Set the output level of gate driver G1-G320: Normal display
	 * Low voltage detection: Disable
	 */
	ILI9341_send_data(0x07);

	/* Display */
	ILI9341_send_command(ILI9341_DFC);                                       /* display function control */
	/* Set the scan mode in non-display area
	 * Determine source/VCOM output in a non-display area in the partial display mode
	 */
	ILI9341_send_data(0x0a);
	/* Select whether the liquid crystal type is normally white type or normally black type
	 * Sets the direction of scan by the gate driver in the range determined by SCN and NL
	 * Select the shift direction of outputs from the source driver
	 * Sets the gate driver pin arrangement in combination with the GS bit to select the optimal scan mode for the module
	 * Specify the scan cycle interval of gate driver in non-display area when PTG to select interval scan
	 */
	ILI9341_send_data(0x82);
	/* Sets the number of lines to drive the LCD at an interval of 8 lines */
	ILI9341_send_data(0x27);
	ILI9341_send_data(0x00);                                                 /* clock divisor */

	ILI9341_send_command(ILI9341_SLEEP_OUT);                                 /* sleep out */
	HAL_Delay(100);
	ILI9341_send_command(ILI9341_DISPLAY_ON);                                /* display on */
	HAL_Delay(100);
	ILI9341_send_command(ILI9341_GRAM);                                      /* memory write */
	HAL_Delay(5);

	/* Touch Screen SPI */
	TS_TOUCH_RAW_Def myRawTouchDef = {0};
	TS_TOUCH_RAW_Def localRawTouch = {0};
	TS_CALIBRATE_Def myTS_Calibrate = {0};
	lcd.myTS_Calibrate = myTS_Calibrate;
	lcd.localRawTouch = localRawTouch;
	lcd.myRawTouchDef = myRawTouchDef;
	lcd.touchSpi = touchSpi;
	lcd.TOUCH_CS_PORT = TOUCH_CS_PORT;
	lcd.TOUCH_CS_PIN = TOUCH_CS_PIN;
	lcd.CMD_Default = 0x84;
}

void STM32_PLC_LCD_Calibrate_Touch() {
	TSC2046_Calibrate();
}

void STM32_PLC_LCD_Get_Touch_Calibration_Parameters(float *Scale_X, float *Scale_Y, float *Bias_X, float *Bias_Y){
	TSC2046_GetTouchCalibrationParameters(Scale_X, Scale_Y, Bias_X, Bias_Y);
}

void STM32_PLC_LCD_Set_Touch_Calibration_Parameters(float *Scale_X, float *Scale_Y, float *Bias_X, float *Bias_Y){
	TSC2046_SetTouchCalibrationParameters(Scale_X, Scale_Y, Bias_X, Bias_Y);
}

void STM32_PLC_LCD_Get_Touch_Data() {
	TSC2046_GetTouchData();
}
