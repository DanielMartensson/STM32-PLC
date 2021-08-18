/*
 * TSC2046.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Daniel Mårtensson
 */

#include "ILI9341.h"

// Send TSC2046 Command and wait for a response
static uint16_t TSC2046_SendCommand(uint8_t cmd) {
	uint8_t lcdBuf[3] = { 0, 0, 0 };
	uint16_t return16 = 0;
	HAL_GPIO_WritePin(lcd.TOUCH_CS_PORT, lcd.TOUCH_CS_PIN, GPIO_PIN_RESET);
	lcdBuf[0] = cmd;
	HAL_SPI_Transmit(lcd.touchSpi, lcdBuf, 1, 10);
	if (HAL_SPI_Receive(lcd.touchSpi, &lcdBuf[1], 2, 10) == HAL_OK)
		return16 = (lcdBuf[1] << 4) + (lcdBuf[2] >> 4);
	else
		return16 = 0;
	HAL_GPIO_WritePin(lcd.TOUCH_CS_PORT, lcd.TOUCH_CS_PIN, GPIO_PIN_SET);
	return return16;
}

// Get x-axis raw touch 12-bit value
static uint16_t TSC2046_getRaw_X() {
	return TSC2046_SendCommand(CMD_X_AXIS | lcd.CMD_Default);
}
// Get y-axis raw touch 12-bit value
static uint16_t TSC2046_getRaw_Y() {
	return TSC2046_SendCommand(CMD_Y_AXIS | lcd.CMD_Default);
}
/* Get z-axis raw touch 12-bit value - Not used any longer due to TS_IRQ
static uint16_t TSC2046_getRaw_Z() {
	return TSC2046_SendCommand(CMD_Z_AXIS | lcd.CMD_Default);
}*/

// Print calibration point - Top-Left corner point
static void TSC2046_TL_point() {
	ILI9341_fill_circle(1, 1, 3, COLOR_RED);
	ILI9341_print_text("Press here", 20, 30, COLOR_RED, COLOR_RED, 1);
}
// Print calibration point - Bottom-Right corner point
static void TSC2046_BR_point() {
	ILI9341_fill_circle(lcd.myTS_Calibrate.Width - 1, lcd.myTS_Calibrate.Height - 1, 3, COLOR_RED);
	ILI9341_print_text("Press here", lcd.myTS_Calibrate.Width - 80, lcd.myTS_Calibrate.Height - 40, COLOR_RED, COLOR_RED, 1);
}

// Poll for touch status
static void TSC2046_GetRawTouch() {

	// Assign raw touch based on orientation
	switch (lcd.ScreenOrientation) {
	case 1:
		lcd.localRawTouch.x_touch = 4095 - TSC2046_getRaw_X();
		lcd.localRawTouch.y_touch = TSC2046_getRaw_Y(lcd);
		lcd.myTS_Calibrate.Width = 230;
		lcd.myTS_Calibrate.Height = 320;
		break;

	case 2:
		lcd.localRawTouch.x_touch = 4095 - TSC2046_getRaw_Y();
		lcd.localRawTouch.y_touch = 4095 - TSC2046_getRaw_X();
		lcd.myTS_Calibrate.Width = 320;
		lcd.myTS_Calibrate.Height = 240;
		break;

	case 3:
		lcd.localRawTouch.x_touch = TSC2046_getRaw_X();
		lcd.localRawTouch.y_touch = 4095 - TSC2046_getRaw_Y();
		lcd.myTS_Calibrate.Width = 230;
		lcd.myTS_Calibrate.Height = 320;
		break;

	case 4:
		lcd.localRawTouch.x_touch = TSC2046_getRaw_Y();
		lcd.localRawTouch.y_touch = TSC2046_getRaw_X();
		lcd.myTS_Calibrate.Width = 320;
		lcd.myTS_Calibrate.Height = 240;
		break;
	}
	// These are for the calibration
	lcd.myRawTouchDef.x_touch = lcd.localRawTouch.x_touch;
	lcd.myRawTouchDef.y_touch = lcd.localRawTouch.y_touch;
}

// Calibrate resistive touch panel
void TSC2046_Calibrate() {
	// Set rotation
	ILI9341_set_rotation(2);

	// Reset
	lcd.myTS_Calibrate.TL_X = 0;
	lcd.myTS_Calibrate.TL_Y = 0;
	lcd.myTS_Calibrate.BR_X = 0;
	lcd.myTS_Calibrate.BR_Y = 0;
	lcd.myRawTouchDef.y_touch = 0;
	lcd.myRawTouchDef.x_touch = 0;

	// Get Top-Left corner calibration coordinate
	TSC2046_TL_point();
	while (1) {
		if (TSC2046_isPressed()) {
			for (uint8_t i = 0; i < 10; i++) {
				TSC2046_GetRawTouch();
				lcd.myTS_Calibrate.TL_X += lcd.myRawTouchDef.x_touch;
				lcd.myTS_Calibrate.TL_Y += lcd.myRawTouchDef.y_touch;
			}
			break;
		}
		HAL_Delay(10);
	}
	HAL_Delay(1000);

	// Get Bottom-Right corner calibration coordinate
	TSC2046_BR_point();
	while (1) {
		if (TSC2046_isPressed()) {
			for (uint8_t i = 0; i < 10; i++) {
				TSC2046_GetRawTouch();
				lcd.myTS_Calibrate.BR_X += lcd.myRawTouchDef.x_touch;
				lcd.myTS_Calibrate.BR_Y += lcd.myRawTouchDef.y_touch;
			}
			break;
		}
		HAL_Delay(10);
	}

	lcd.myTS_Calibrate.TL_X *= 0.1;
	lcd.myTS_Calibrate.TL_Y *= 0.1;

	lcd.myTS_Calibrate.BR_X *= 0.1;
	lcd.myTS_Calibrate.BR_Y *= 0.1;

	// Calculate scalar
	lcd.myTS_Calibrate.Scale_X = (lcd.myTS_Calibrate.Width + 0.0f) / (lcd.myTS_Calibrate.BR_X - lcd.myTS_Calibrate.TL_X + 0.0f);
	lcd.myTS_Calibrate.Scale_Y = (lcd.myTS_Calibrate.Height + 0.0f) / (lcd.myTS_Calibrate.BR_Y - lcd.myTS_Calibrate.TL_Y + 0.0f);

	// Calculate bias
	lcd.myTS_Calibrate.Bias_X = -1 - lcd.myTS_Calibrate.Scale_X * lcd.myTS_Calibrate.TL_X; // -1 is for bias. Change this so you have 100% accuracy at center of the LCD
	lcd.myTS_Calibrate.Bias_Y = -1 - lcd.myTS_Calibrate.Scale_Y * lcd.myTS_Calibrate.TL_Y; // -1 is for bias. Change this so you have 100% accuracy at center of the LCD
}

void TSC2046_GetTouchCalibrationParameters(float *Scale_X, float *Scale_Y, float *Bias_X, float *Bias_Y) {
	*Scale_X = lcd.myTS_Calibrate.Scale_X;
	*Scale_Y = lcd.myTS_Calibrate.Scale_Y;
	*Bias_X = lcd.myTS_Calibrate.Bias_X;
	*Bias_Y = lcd.myTS_Calibrate.Bias_Y;
}

void TSC2046_SetTouchCalibrationParameters(float *Scale_X, float *Scale_Y, float *Bias_X, float *Bias_Y) {
	lcd.myTS_Calibrate.Scale_X = *Scale_X;
	lcd.myTS_Calibrate.Scale_Y = *Scale_Y;
	lcd.myTS_Calibrate.Bias_X = *Bias_X;
	lcd.myTS_Calibrate.Bias_Y = *Bias_Y;
}

// Get touch screen data when calibration is already made
void TSC2046_GetTouchData() {
	// Reset
	uint16_t temp16x = 0, temp16y = 0;
	// Read touch data
	for (uint8_t i = 0; i < 10; i++) {
		TSC2046_GetRawTouch(lcd);
		temp16x += lcd.localRawTouch.x_touch;
		temp16y += lcd.localRawTouch.y_touch;
	}
	lcd.localRawTouch.x_touch = temp16x * 0.1;
	lcd.localRawTouch.y_touch = temp16y * 0.1;

	// X-axis value
	lcd.myTsData.X = lcd.myTS_Calibrate.Scale_X * lcd.localRawTouch.x_touch + lcd.myTS_Calibrate.Bias_X;

	// Y-axis value
	lcd.myTsData.Y = lcd.myTS_Calibrate.Scale_Y * lcd.localRawTouch.y_touch + lcd.myTS_Calibrate.Bias_Y;
}


bool TSC2046_isPressed() {
	static uint8_t count = 0;
	static bool has_been_pressed = false;
	bool pressed = (bool) !HAL_GPIO_ReadPin(TS_IRQ_GPIO_Port, TS_IRQ_Pin); // TS_IRQ goes low when LCD being pressed on
	if(pressed == true && has_been_pressed == false){
		has_been_pressed = true;
		count = 0;
		HAL_Delay(100); /* Wait until the finger have fully pressed the LCD screen. The Touch SPI and Touch Interrupt are different things */
		return true;
	} else {
		/* This is only for debouncing */
		if(pressed == false && has_been_pressed == true) {
			count = 1 + count;
			if(count >= 10)
				has_been_pressed = false;
		}else{
			count = 0;
		}
		return false;
	}
}
