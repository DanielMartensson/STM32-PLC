/*
 * LCD_ILI9341.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Daniel Mårtensson
 */

#include "ILI9341.h"
#include <string.h>

#define swap_ILI9341(a, b) { int16_t t = a; a = b; b = t; }

#define CHAR_WIDTH 6
#define CHAR_HEIGHT 7
static const unsigned char font[96][6] = {
	{0x00,0x00,0x00,0x00,0x00,0x00}, //
	{0x5c,0x00,0x00,0x00,0x00,0x00}, // !
	{0x06,0x00,0x06,0x00,0x00,0x00}, // "
	{0x28,0x7c,0x28,0x7c,0x28,0x00}, // #
	{0x5c,0x54,0xfe,0x54,0x74,0x00}, // $
	{0x44,0x20,0x10,0x08,0x44,0x00}, // %
	{0x28,0x54,0x54,0x20,0x50,0x00}, // &
	{0x06,0x00,0x00,0x00,0x00,0x00}, // '
	{0x38,0x44,0x00,0x00,0x00,0x00}, // (
	{0x44,0x38,0x00,0x00,0x00,0x00}, // )
	{0x02,0x07,0x02,0x00,0x00,0x00}, // *
	{0x10,0x10,0x7c,0x10,0x10,0x00}, // +
	{0xc0,0x00,0x00,0x00,0x00,0x00}, // ,
	{0x10,0x10,0x10,0x10,0x10,0x00}, // -
	{0x40,0x00,0x00,0x00,0x00,0x00}, // .
	{0x60,0x10,0x0c,0x00,0x00,0x00}, // /
	{0x7c,0x64,0x54,0x4c,0x7c,0x00}, // 0
	{0x48,0x7c,0x40,0x00,0x00,0x00}, // 1
	{0x64,0x54,0x54,0x54,0x48,0x00}, // 2
	{0x44,0x54,0x54,0x54,0x6c,0x00}, // 3
	{0x3c,0x20,0x70,0x20,0x20,0x00}, // 4
	{0x5c,0x54,0x54,0x54,0x24,0x00}, // 5
	{0x7c,0x54,0x54,0x54,0x74,0x00}, // 6
	{0x04,0x04,0x64,0x14,0x0c,0x00}, // 7
	{0x7c,0x54,0x54,0x54,0x7c,0x00}, // 8
	{0x5c,0x54,0x54,0x54,0x7c,0x00}, // 9
	{0x44,0x00,0x00,0x00,0x00,0x00}, // :
	{0xc4,0x00,0x00,0x00,0x00,0x00}, // ;
	{0x10,0x28,0x44,0x00,0x00,0x00}, // <
	{0x28,0x28,0x28,0x28,0x28,0x00}, // =
	{0x44,0x28,0x10,0x00,0x00,0x00}, // >
	{0x08,0x04,0x54,0x08,0x00,0x00}, // ?
	{0x7c,0x44,0x54,0x54,0x5c,0x00}, // @
	{0x7c,0x24,0x24,0x24,0x7c,0x00}, // A
	{0x7c,0x54,0x54,0x54,0x6c,0x00}, // B
	{0x7c,0x44,0x44,0x44,0x44,0x00}, // C
	{0x7c,0x44,0x44,0x44,0x38,0x00}, // D
	{0x7c,0x54,0x54,0x54,0x44,0x00}, // E
	{0x7c,0x14,0x14,0x14,0x04,0x00}, // F
	{0x7c,0x44,0x44,0x54,0x74,0x00}, // G
	{0x7c,0x10,0x10,0x10,0x7c,0x00}, // H
	{0x44,0x44,0x7c,0x44,0x44,0x00}, // I
	{0x60,0x40,0x40,0x44,0x7c,0x00}, // J
	{0x7c,0x10,0x10,0x28,0x44,0x00}, // K
	{0x7c,0x40,0x40,0x40,0x40,0x00}, // L
	{0x7c,0x08,0x10,0x08,0x7c,0x00}, // M
	{0x7c,0x08,0x10,0x20,0x7c,0x00}, // N
	{0x38,0x44,0x44,0x44,0x38,0x00}, // O
	{0x7c,0x14,0x14,0x14,0x08,0x00}, // P
	{0x3c,0x24,0x64,0x24,0x3c,0x00}, // Q
	{0x7c,0x14,0x14,0x14,0x68,0x00}, // R
	{0x5c,0x54,0x54,0x54,0x74,0x00}, // S
	{0x04,0x04,0x7c,0x04,0x04,0x00}, // T
	{0x7c,0x40,0x40,0x40,0x7c,0x00}, // U
	{0x0c,0x30,0x40,0x30,0x0c,0x00}, // V
	{0x3c,0x40,0x30,0x40,0x3c,0x00}, // W
	{0x44,0x28,0x10,0x28,0x44,0x00}, // X
	{0x0c,0x10,0x60,0x10,0x0c,0x00}, // Y
	{0x44,0x64,0x54,0x4c,0x44,0x00}, // Z
	{0x7c,0x44,0x00,0x00,0x00,0x00}, // [
	{0x0c,0x10,0x60,0x00,0x00,0x00}, // "\"
	{0x44,0x7c,0x00,0x00,0x00,0x00}, // ]
	{0x00,0x01,0x00,0x01,0x00,0x00}, // ^
	{0x40,0x40,0x40,0x40,0x40,0x40}, // _
	{0x00,0x01,0x00,0x00,0x00,0x00}, // `
	{0x7c,0x24,0x24,0x24,0x7c,0x00}, // a
	{0x7c,0x54,0x54,0x54,0x6c,0x00}, // b
	{0x7c,0x44,0x44,0x44,0x44,0x00}, // c
	{0x7c,0x44,0x44,0x44,0x38,0x00}, // d
	{0x7c,0x54,0x54,0x54,0x44,0x00}, // e
	{0x7c,0x14,0x14,0x14,0x04,0x00}, // f
	{0x7c,0x44,0x44,0x54,0x74,0x00}, // g
	{0x7c,0x10,0x10,0x10,0x7c,0x00}, // h
	{0x44,0x44,0x7c,0x44,0x44,0x00}, // i
	{0x60,0x40,0x40,0x44,0x7c,0x00}, // j
	{0x7c,0x10,0x10,0x28,0x44,0x00}, // k
	{0x7c,0x40,0x40,0x40,0x40,0x00}, // l
	{0x7c,0x08,0x10,0x08,0x7c,0x00}, // m
	{0x7c,0x08,0x10,0x20,0x7c,0x00}, // n
	{0x38,0x44,0x44,0x44,0x38,0x00}, // o
	{0x7c,0x14,0x14,0x14,0x08,0x00}, // p
	{0x3c,0x24,0x64,0x24,0x3c,0x00}, // q
	{0x7c,0x14,0x14,0x14,0x68,0x00}, // r
	{0x5c,0x54,0x54,0x54,0x74,0x00}, // s
	{0x04,0x04,0x7c,0x04,0x04,0x00}, // t
	{0x7c,0x40,0x40,0x40,0x7c,0x00}, // u
	{0x0c,0x30,0x40,0x30,0x0c,0x00}, // v
	{0x3c,0x40,0x30,0x40,0x3c,0x00}, // w
	{0x44,0x28,0x10,0x28,0x44,0x00}, // x
	{0x0c,0x10,0x60,0x10,0x0c,0x00}, // y
	{0x44,0x64,0x54,0x4c,0x44,0x00}, // z
	{0x10,0x7c,0x44,0x00,0x00,0x00}, // {
	{0x6c,0x00,0x00,0x00,0x00,0x00}, // |
	{0x44,0x7c,0x10,0x00,0x00,0x00}, // }
	{0x02,0x01,0x02,0x01,0x00,0x00}, // ~
	{0x00,0x00,0x00,0x00,0x00,0x00}
};

/* This is 240*320 divided by 8 and it's used for transferring data */
static uint8_t SPI_DATA[9600];

/* Write data to LCD with one byte */
void ILI9341_send_data(uint8_t data) {
	HAL_GPIO_WritePin(lcd.LCD_CS_PORT, lcd.LCD_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit(lcd.lcdSpi, &data, 1, 5);
	HAL_GPIO_WritePin(lcd.LCD_CS_PORT, lcd.LCD_CS_PIN, GPIO_PIN_SET);
}

/* Write data to LCD with array of bytes */
void ILI9341_send_data_array(uint8_t data[], uint16_t size) {
	HAL_GPIO_WritePin(lcd.LCD_CS_PORT, lcd.LCD_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit(lcd.lcdSpi, data, size, 100);
	HAL_GPIO_WritePin(lcd.LCD_CS_PORT, lcd.LCD_CS_PIN, GPIO_PIN_SET);
}

/* Write Command to LCD */
void ILI9341_send_command(uint8_t com) {
	HAL_GPIO_WritePin(lcd.LCD_DC_PORT, lcd.LCD_DC_PIN, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(lcd.LCD_CS_PORT, lcd.LCD_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit(lcd.lcdSpi, &com, 1, 5);
	HAL_GPIO_WritePin(lcd.LCD_CS_PORT, lcd.LCD_CS_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(lcd.LCD_DC_PORT, lcd.LCD_DC_PIN, GPIO_PIN_SET);
}

/* Set cursor position */
static void ILI9341_set_cursor_position(int16_t x1, int16_t y1, int16_t x2, int16_t y2) {
	ILI9341_send_command(ILI9341_COLUMN_ADDR);
	uint8_t data[4] = {x1 >> 8, x1 & 0xFF, x2 >> 8, x2 & 0xFF};
	ILI9341_send_data_array(data, 4);

	ILI9341_send_command(ILI9341_PAGE_ADDR);
	data[0] = y1 >> 8;
	data[1] = y1 & 0xFF;
	data[2] = y2 >> 8;
	data[3] = y2 & 0xFF;
	ILI9341_send_data_array(data, 4);
	ILI9341_send_command(ILI9341_GRAM);
}

/* Draw a pixel */
static void ILI9341_draw_pixel(int16_t x, int16_t y, uint16_t color) {
	ILI9341_set_cursor_position(x, y, x, y);
	uint8_t data[2] = {color >> 8, color};
	ILI9341_send_data_array(data, 2);
}

static void ILI9341_fill_circle_helper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color) {
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		if (cornername & 0x1) {
			ILI9341_draw_vertical_line(x0 + x, y0 - y, 2 * y + 1 + delta, color);
			ILI9341_draw_vertical_line(x0 + y, y0 - x, 2 * x + 1 + delta, color);
		}
		if (cornername & 0x2) {
			ILI9341_draw_vertical_line(x0 - x, y0 - y, 2 * y + 1 + delta, color);
			ILI9341_draw_vertical_line(x0 - y, y0 - x, 2 * x + 1 + delta, color);
		}
	}
}

/* This is a fast way to insert pixel data for rectangles. It uses inline for optimization purposes only */
inline static void ILI9341_insert_color_data(uint8_t data[], uint16_t iterations, uint8_t pixel_data[]){
	for(uint16_t i = 0; i < iterations; i++){
		memcpy(data, pixel_data, 2);
		data += 2;
	}
}

/* This is how turn a text string into an image */
static uint16_t ILI9341_text_to_image(char text[], uint8_t data[], uint16_t font_color, uint16_t background_color, uint8_t font_size) {
	/* Initial prepare */
	uint8_t font_color_16_bit[2] = {font_color >> 8, font_color};
	uint8_t background_color_16_bit[2] = {background_color >> 8, background_color};
	volatile uint8_t i, j, h, w, a, index_row;
	volatile char c;
	uint16_t pixels_added_into_data = 0;
	char *beginning = text;

	/* We need to call the string text CHAR_HEIGTH times because we are filling array data on row-major order */
	for(j = 0; j < CHAR_HEIGHT; j++) {
		/* h is on height */
		for(h = 0; h < font_size; h++) {
			while(*text) {
				/* Get character and it cannot be larger than ASCII 127 */
				c = *text++ & 0x7F;

				/* Find row index just by looking at char c */
				if (c < ' ')
					index_row = 0; /* This is the first row in the font array */
				else
					index_row = c - ' ';

				for (i = 0; i < CHAR_WIDTH; i++) {
					a = font[index_row][i] & (1 << j);
					/* w is on width */
					for(w = 0; w < font_size; w++) {
						if (a > 0){
							memcpy(data, font_color_16_bit, 2); /* We have a pixel 1 - Font pixel */
						}else{
							memcpy(data, background_color_16_bit, 2); /* We have a pixel 0 - Background pixel */
						}
						data += 2;
						pixels_added_into_data++;
					}
				}
			}
			text = beginning; /* Reset to first index */
		}
	}

	return pixels_added_into_data;
}

/* Fill the entire screen with a background color */
void ILI9341_fill_screen(uint16_t color) {
	uint32_t n = ILI9341_PIXEL_COUNT;
	if (lcd.rotationNum == 1 || lcd.rotationNum == 3) {
		ILI9341_set_cursor_position(0, 0, ILI9341_WIDTH - 1, ILI9341_HEIGHT - 1);
	} else if (lcd.rotationNum == 2 || lcd.rotationNum == 4) {
		ILI9341_set_cursor_position(0, 0, ILI9341_HEIGHT - 1, ILI9341_WIDTH - 1);
	}
	uint8_t color_16_bit[2] = {color >> 8, color};
	uint16_t size_of_SPI_DATA = sizeof(SPI_DATA);
	ILI9341_insert_color_data(SPI_DATA, size_of_SPI_DATA/2, color_16_bit);
	/* Begin with the first iterations. 2 times N pixels because it's 16-bit pixels, not 8-bit pixels */
	uint8_t iterations = (2*n)/(size_of_SPI_DATA/2);
	for(uint8_t i = 0; i < iterations; i++)
		ILI9341_send_data_array(SPI_DATA, size_of_SPI_DATA);

	/* Send the remaining */
	uint16_t remaning_bytes = (2*n) % (size_of_SPI_DATA/2);
	if(remaning_bytes > 0)
		ILI9341_send_data_array(SPI_DATA, remaning_bytes);
}

/* Create filled rectangle */
void ILI9341_fill_rect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
	uint32_t n = ((x1 + 1) - x0) * ((y1 + 1) - y0);
	if (n > ILI9341_PIXEL_COUNT)
		n = ILI9341_PIXEL_COUNT;
	ILI9341_set_cursor_position(x0, y0, x1, y1);
	uint8_t color_16_bit[2] = {color >> 8, color};
	uint16_t size_of_SPI_DATA = sizeof(SPI_DATA);
	ILI9341_insert_color_data(SPI_DATA, size_of_SPI_DATA/2, color_16_bit);
	/* Begin with the first iterations. 2 times N pixels because it's 16-bit pixels, not 8-bit pixels */
	uint8_t iterations = (2*n)/(size_of_SPI_DATA/2);
	for(uint8_t i = 0; i < iterations; i++)
		ILI9341_send_data_array(SPI_DATA, size_of_SPI_DATA);

	/* Send the remaining */
	uint16_t remaning_bytes = (2*n) % (size_of_SPI_DATA/2);
	if(remaning_bytes > 0)
		ILI9341_send_data_array(SPI_DATA, remaning_bytes);
}

/* Create hollow rectangle */
void ILI9341_hollow_rect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
	int16_t h = x1 - x0;
	int16_t v = y1 - y0 + 1;
	ILI9341_draw_horizontal_line(x0, y0, h, color);
	ILI9341_draw_horizontal_line(x0, y1, h, color);
	ILI9341_draw_vertical_line(x0, y0, v, color);
	ILI9341_draw_vertical_line(x1, y0, v, color);
}

/* Circle drawing functions */
void ILI9341_draw_circle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	ILI9341_draw_pixel(x0, y0 + r, color);
	ILI9341_draw_pixel(x0, y0 - r, color);
	ILI9341_draw_pixel(x0 + r, y0, color);
	ILI9341_draw_pixel(x0 - r, y0, color);

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		ILI9341_draw_pixel(x0 + x, y0 + y, color);
		ILI9341_draw_pixel(x0 - x, y0 + y, color);
		ILI9341_draw_pixel(x0 + x, y0 - y, color);
		ILI9341_draw_pixel(x0 - x, y0 - y, color);
		ILI9341_draw_pixel(x0 + y, y0 + x, color);
		ILI9341_draw_pixel(x0 - y, y0 + x, color);
		ILI9341_draw_pixel(x0 + y, y0 - x, color);
		ILI9341_draw_pixel(x0 - y, y0 - x, color);
	}
}

/* Create a round circle */
void ILI9341_fill_circle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
	ILI9341_draw_vertical_line(x0, y0 - r, 2 * r + 1, color);
	ILI9341_fill_circle_helper(x0, y0, r, 3, 0, color);
}

/* Draw a line */
void ILI9341_draw_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
	int16_t steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep) {
		swap_ILI9341(x0, y0);
		swap_ILI9341(x1, y1);
	}

	if (x0 > x1) {
		swap_ILI9341(x0, x1);
		swap_ILI9341(y0, y1);
	}

	int16_t dx, dy;
	dx = x1 - x0;
	dy = abs(y1 - y0);

	int16_t err = dx / 2;
	int16_t ystep;

	if (y0 < y1) {
		ystep = 1;
	} else {
		ystep = -1;
	}

	for (; x0 <= x1; x0++) {
		if (steep) {
			ILI9341_draw_pixel(y0, x0, color);
		} else {
			ILI9341_draw_pixel(x0, y0, color);
		}
		err -= dy;
		if (err < 0) {
			y0 += ystep;
			err += dx;
		}
	}
}

/* Draw a fast horizontal line */
void ILI9341_draw_horizontal_line(int16_t x, int16_t y, int16_t w, uint16_t color) {
	uint8_t color_16_bit[2] = {color >> 8, color};
	ILI9341_insert_color_data(SPI_DATA, x + w - 1, color_16_bit);
	ILI9341_set_cursor_position(x, y, x + w - 1, y);
	ILI9341_send_data_array(SPI_DATA, 2*(x + w - 1));
}

/* Draw vertical line */
void ILI9341_draw_vertical_line(int16_t x, int16_t y, int16_t h, uint16_t color) {
	uint8_t color_16_bit[2] = {color >> 8, color};
	ILI9341_insert_color_data(SPI_DATA, y + h - 1, color_16_bit);
	ILI9341_set_cursor_position(x, y, x, y + h - 1);
	ILI9341_send_data_array(SPI_DATA, 2*(y + h - 1));
}

/* Draw triangle */
void ILI9341_draw_triangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
	ILI9341_draw_line(x0, y0, x1, y1, color);
	ILI9341_draw_line(x1, y1, x2, y2, color);
	ILI9341_draw_line(x2, y2, x0, y0, color);
}

/* Fill triangle */
void ILI9341_fill_triangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
	int16_t a, b, y, last;

	// Sort coordinates by Y order (y2 >= y1 >= y0)
	if (y0 > y1) {
		swap_ILI9341(y0, y1);
		swap_ILI9341(x0, x1);
	}
	if (y1 > y2) {
		swap_ILI9341(y2, y1);
		swap_ILI9341(x2, x1);
	}
	if (y0 > y1) {
		swap_ILI9341(y0, y1);
		swap_ILI9341(x0, x1);
	}

	if (y0 == y2) { // Handle awkward all-on-same-line case as its own thing
		a = b = x0;
		if (x1 < a)
			a = x1;
		else if (x1 > b)
			b = x1;
		if (x2 < a)
			a = x2;
		else if (x2 > b)
			b = x2;
		ILI9341_draw_horizontal_line(a, y0, b - a + 1, color);
		return;
	}

	int16_t dx01 = x1 - x0, dy01 = y1 - y0, dx02 = x2 - x0, dy02 = y2 - y0, dx12 = x2 - x1, dy12 = y2 - y1, sa = 0, sb = 0;

	/*
	 * For upper part of triangle, find scanline crossings for segments
	 * 0-1 and 0-2.  If y1=y2 (flat-bottomed triangle), the scanline y1
	 * is included here (and second loop will be skipped, avoiding a /0
	 * error there), otherwise scanline y1 is skipped here and handled
	 * in the second loop...which also avoids a /0 error here if y0=y1
	 * (flat-topped triangle).
	 */
	if (y1 == y2)
		last = y1;   /* Include y1 scanline */
	else
		last = y1 - 1; /* Skip it */

	for (y = y0; y <= last; y++) {
		a = x0 + sa / dy01;
		b = x0 + sb / dy02;
		sa += dx01;
		sb += dx02;

		if (a > b)
			swap_ILI9341(a, b);
		ILI9341_draw_horizontal_line(a, y, b - a + 1, color);
	}

	/* For lower part of triangle, find scanline crossings for segments 0-2 and 1-2.  This loop is skipped if y1=y2 */
	sa = dx12 * (y - y1);
	sb = dx02 * (y - y0);
	for (; y <= y2; y++) {
		a = x1 + sa / dy12;
		b = x0 + sb / dy02;
		sa += dx12;
		sb += dx02;

		if (a > b)
			swap_ILI9341(a, b);
		ILI9341_draw_horizontal_line(a, y, b - a + 1, color);
	}
}

/* Print a string */
void ILI9341_print_text(char text[], int16_t x0, int16_t y0, uint16_t font_color, uint16_t background_color, uint8_t font_size) {
	/* Quick check */
	if (lcd.rotationNum == 1 || lcd.rotationNum == 3) {
		if ((x0 >= ILI9341_WIDTH) || // Clip right
				(y0 >= ILI9341_HEIGHT) || // Clip bottom
				((x0 + 6 * font_size - 1) < 0) || // Clip left
				((y0 + 8 * font_size - 1) < 0))   // Clip top
			return;
	} else {
		if ((y0 >= ILI9341_WIDTH) || // Clip right
				(x0 >= ILI9341_HEIGHT) || // Clip bottom
				((y0 + 6 * font_size - 1) < 0) || // Clip left
				((x0 + 8 * font_size - 1) < 0))   // Clip top
			return;
	}

	uint16_t pixels_added_into_data = ILI9341_text_to_image(text, SPI_DATA, font_color, background_color, font_size);
	uint16_t x1 = x0 + font_size*CHAR_WIDTH*strlen(text) - 1;
	uint8_t y1 = y0 + font_size*CHAR_HEIGHT;
	ILI9341_set_cursor_position(x0, y0, x1, y1);
	ILI9341_send_data_array(SPI_DATA, 2*pixels_added_into_data); /* Because it's 16-bit pixels with 8-bit data */

}


/* Image print (RGB 565, 2 bytes per pixel) */
void ILI9341_print_image(int16_t x, uint16_t y, uint16_t w, uint16_t h, const uint8_t data[], uint32_t size) {
	ILI9341_set_cursor_position(x, y, w + x - 1, h + y - 1);
	ILI9341_send_data_array(SPI_DATA, size);
}

/* Set screen rotation */
void ILI9341_set_rotation(uint8_t rotate) {
	if(lcd.ScreenOrientation == rotate)
		return; /* No action */

	lcd.ScreenOrientation = rotate;
	switch (rotate) {
	case 1:
		lcd.rotationNum = 1;
		ILI9341_send_command(ILI9341_MEMCONTROL);
		ILI9341_send_data(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
		break;
	case 2:
		lcd.rotationNum = 2;
		ILI9341_send_command(ILI9341_MEMCONTROL);
		ILI9341_send_data(ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
		break;
	case 3:
		lcd.rotationNum = 3;
		ILI9341_send_command(ILI9341_MEMCONTROL);
		ILI9341_send_data(ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);
		break;
	case 4:
		lcd.rotationNum = 4;
		ILI9341_send_command(ILI9341_MEMCONTROL);
		ILI9341_send_data(ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
		break;
	default:
		lcd.rotationNum = 1;
		ILI9341_send_command(ILI9341_MEMCONTROL);
		ILI9341_send_data(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
		break;
	}
}

/* Get screen rotation */
uint8_t ILI9341_get_rotation() {
	return lcd.rotationNum;
}
