/*
 * LCD_ILI9341.h
 *
 * 	Created on: Feb 8, 2020
 *      Author: Daniel Mårtensson
 */

#ifndef SRC_STM32_PLC_TOUCH_SCREEN_HARDWARE_ILI9341_H_
#define SRC_STM32_PLC_TOUCH_SCREEN_HARDWARE_ILI9341_H_

#include "main.h"
#include <stdlib.h>
#include <stdbool.h>

/* LCD dimensions defines */
#define ILI9341_WIDTH       					240
#define ILI9341_HEIGHT      					320
#define ILI9341_PIXEL_COUNT						ILI9341_WIDTH * ILI9341_HEIGHT

/* ILI9341 LCD commands */
#define ILI9341_RESET			 		    	0x01
#define ILI9341_SLEEP_OUT		  				0x11
#define ILI9341_GAMMA			    			0x26
#define ILI9341_DISPLAY_OFF						0x28
#define ILI9341_DISPLAY_ON						0x29
#define ILI9341_COLUMN_ADDR						0x2A
#define ILI9341_PAGE_ADDR			  			0x2B
#define ILI9341_GRAM				    		0x2C
#define ILI9341_TEARING_OFF						0x34
#define ILI9341_TEARING_ON						0x35
#define ILI9341_DISPLAY_INVERSION				0xb4
#define ILI9341_MAC			        			0x36
#define ILI9341_PIXEL_FORMAT    				0x3A
#define ILI9341_WDB			    	  			0x51
#define ILI9341_WCD				      			0x53
#define ILI9341_RGB_INTERFACE   				0xB0
#define ILI9341_FRC					    		0xB1
#define ILI9341_BPC					    		0xB5
#define ILI9341_DFC				 	    		0xB6
#define ILI9341_Entry_Mode_Set					0xB7
#define ILI9341_POWER1							0xC0
#define ILI9341_POWER2							0xC1
#define ILI9341_VCOM1							0xC5
#define ILI9341_VCOM2							0xC7
#define ILI9341_POWERA							0xCB
#define ILI9341_POWERB							0xCF
#define ILI9341_PGAMMA							0xE0
#define ILI9341_NGAMMA							0xE1
#define ILI9341_DTCA							0xE8
#define ILI9341_DTCB							0xEA
#define ILI9341_POWER_SEQ						0xED
#define ILI9341_3GAMMA_EN						0xF2
#define ILI9341_INTERFACE						0xF6
#define ILI9341_PRC				   	  			0xF7
#define ILI9341_VERTICAL_SCROLL 				0x33

#define ILI9341_MEMCONTROL         				0x36
#define ILI9341_MADCTL_MY  						0x80
#define ILI9341_MADCTL_MX 						0x40
#define ILI9341_MADCTL_MV  						0x20
#define ILI9341_MADCTL_ML  						0x10
#define ILI9341_MADCTL_RGB 						0x00
#define ILI9341_MADCTL_BGR 						0x08
#define ILI9341_MADCTL_MH  						0x04

/* List of colors */
#define COLOR_BLACK           					0x0000
#define COLOR_NAVY           	 				0x000F
#define COLOR_DGREEN          					0x03E0
#define COLOR_DCYAN           					0x03EF
#define COLOR_MAROON          					0x7800
#define COLOR_PURPLE          					0x780F
#define COLOR_OLIVE           					0x7BE0
#define COLOR_LGRAY           					0xC618
#define COLOR_DGRAY           					0x7BEF
#define COLOR_BLUE            					0x001F
#define COLOR_BLUE2			      				0x051D
#define COLOR_GREEN           					0x07E0
#define COLOR_GREEN2		      				0xB723
#define COLOR_GREEN3		      				0x8000
#define COLOR_CYAN            					0x07FF
#define COLOR_RED             					0xF800
#define COLOR_MAGENTA         					0xF81F
#define COLOR_YELLOW          					0xFFE0
#define COLOR_WHITE           					0xFFFF
#define COLOR_ORANGE          					0xFD20
#define COLOR_GREENYELLOW     					0xAFE5
#define COLOR_BROWN 			    			0xBC40
#define COLOR_BRRED 			    			0xFC07

/* Axis measurement */
#define CMD_X_AXIS								0x50
#define CMD_Y_AXIS								0x10
#define CMD_Z_AXIS								0x30

/* Touch coordinates */
typedef struct {
	uint16_t x_touch;
	uint16_t y_touch;
}TS_TOUCH_RAW_Def;

/* Calibration */
typedef struct {
	uint16_t TL_X;
	uint16_t TL_Y;

	uint16_t BR_X;
	uint16_t BR_Y;

	float Scale_X;
	float Scale_Y;

	float Bias_X;
	float Bias_Y;

	uint16_t Width;
	uint16_t Height;
}TS_CALIBRATE_Def;

/* Touch Screen Data */
typedef struct {
	uint16_t X;
	uint16_t Y;
}TS_TOUCH_DATA_Def;

/* Objective structure for LCD */
typedef struct {
	// This is for LCD
	uint8_t rotationNum;
	uint8_t _cp437; // 0 or 1
	SPI_HandleTypeDef* lcdSpi;
	GPIO_TypeDef* LCD_CS_PORT;
	uint16_t LCD_CS_PIN;
	GPIO_TypeDef* LCD_DC_PORT;
	uint16_t LCD_DC_PIN;
	GPIO_TypeDef* LCD_RESET_PORT;
	uint16_t LCD_RESET_PIN;

	// This is for the touch
	SPI_HandleTypeDef* touchSpi;
	GPIO_TypeDef* TOUCH_CS_PORT;
	uint16_t TOUCH_CS_PIN;
	uint8_t CMD_Default;
	uint8_t ScreenOrientation;
	TS_TOUCH_RAW_Def myLocalTs_Def;
	TS_TOUCH_RAW_Def localRawTouch;
	TS_TOUCH_RAW_Def myRawTouchDef;
	TS_TOUCH_DATA_Def myTsData;
	TS_CALIBRATE_Def myTS_Calibrate;

}ILI9341_SPI;

ILI9341_SPI lcd;

/* SPI functions */
void ILI9341_send_data(uint8_t data);
void ILI9341_send_data_array(uint8_t data[], uint16_t size);
void ILI9341_send_command(uint8_t com);

/* User functions */
void ILI9341_fill_screen(uint16_t color);
void ILI9341_fill_rect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void ILI9341_hollow_rect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void ILI9341_draw_circle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void ILI9341_fill_circle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void ILI9341_draw_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void ILI9341_draw_horizontal_line(int16_t x, int16_t y, int16_t w, uint16_t color);
void ILI9341_draw_vertical_line(int16_t x, int16_t y, int16_t h, uint16_t color);
void ILI9341_draw_triangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void ILI9341_fill_triangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void ILI9341_print_text(char text[], int16_t x0, int16_t y0, uint16_t font_color, uint16_t background_color, uint8_t font_size);
void ILI9341_print_image(int16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t data[], uint32_t size);
void ILI9341_set_rotation(uint8_t rotate);
uint8_t ILI9341_get_rotation();

/* Touch - Public functions */
void TSC2046_Calibrate();
void TSC2046_GetTouchData();
void TSC2046_GetTouchCalibrationParameters(float *Scale_X, float *Scale_Y, float *Bias_X, float *Bias_Y);
void TSC2046_SetTouchCalibrationParameters(float *Scale_X, float *Scale_Y, float *Bias_X, float *Bias_Y);
bool TSC2046_isPressed();

#endif /* SRC_STM32_PLC_TOUCH_SCREEN_HARDWARE_ILI9341_H_ */
