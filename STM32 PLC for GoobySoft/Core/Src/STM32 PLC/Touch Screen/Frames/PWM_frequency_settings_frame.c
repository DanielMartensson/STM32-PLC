/*
 * PWM_frequency_settings_frame.c
 *
 *  Created on: 25 juli 2021
 *      Author: Daniel Mårtensson
 */

#include "../Touch_screen.h"
#include "../Hardware/ILI9341.h"
#include "../../Functions.h"


void STM32_PLC_LCD_Show_PWM_Frequency_Settings_Frame(uint8_t *frame_id) {
	/* Clear the screen , but not the icons */
	ILI9341_fill_rect(51, 6, 314, 234, COLOR_NAVY);

	/* Write the title */
	ILI9341_draw_horizontal_line(50, 30, 265, COLOR_GREEN);
	ILI9341_print_text("Set PWM frequency", 55, 10, COLOR_YELLOW, COLOR_NAVY, 1);

	/*
	 * For TIM2 and TIM5
	 * Timer clock: 48 Mhz
	 * Prescaler: Selected below
	 * Counter: 65535 (0xffff)
	 * Update frequency: See PWM choices
	 * MATLAB formula:
	 * for i = [0 1 2 4 6 13 72 145 182 243 365 731 1462 2193 2924 3655 4880 7310 65535]
    		disp(sprintf("Hz = %i at prescaler = %i", (48*10^6/(1+i))/0xFFFF, i));
		end
	 */

	/* Show all calibration inputs */
	ILI9341_print_text("PWM Hz choices to select:", 55, 35, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("Hz=((48*10^6/(s+1))/65535", 55, 45, COLOR_YELLOW, COLOR_NAVY, 1);
	ILI9341_print_text("s=Prescaler 0 to 65535", 55, 55, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Show selected frequency */
	char text[50];
	uint16_t prescaler_for_PWM_0_3, prescaler_for_PWM_4_7;
	STM32_PLC_Flash_Get_PWM_Prescalers(&prescaler_for_PWM_0_3, &prescaler_for_PWM_4_7);
	ILI9341_print_text("Current prescaler settings:", 55, 65, COLOR_YELLOW, COLOR_NAVY, 1);
	sprintf(text, "PWM0 to PWM3:%i PWM4 to PWM7:%i", prescaler_for_PWM_0_3, prescaler_for_PWM_4_7);
	ILI9341_print_text(text, 55, 75, COLOR_YELLOW, COLOR_NAVY, 1);

	/* Select settings button */
	ILI9341_fill_rect(85, 195, 273, 220, COLOR_GREEN);
	ILI9341_hollow_rect(85, 195, 273, 220, COLOR_BLACK);
	ILI9341_print_text("Select PWM freq", 90, 200, COLOR_BLACK, COLOR_GREEN, 2);

	/* Logic for request button */
	STM32_PLC_LCD_Call_One_Button_Logic(85, 195, 273, 220);

	/* Ask the user if */
	if(STM32_PLC_LCD_Show_Question_Yes_No_Dialog("Do you want to set PWM frequency?") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Ask for which PWM */
	bool minusbutton_show = false;
	bool decimalbutton_show = false;
	float number_value;
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Set setting for PWM0-PWM3=0 or PWM4-PWM7=1") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint8_t PWM_TIM;
	if(number_value < 0)
		PWM_TIM = 0;
	else if(number_value > 1)
		PWM_TIM = 1;
	else
		PWM_TIM = (uint8_t) number_value;

	/* Ask for prescaler */
	if(STM32_PLC_LCD_Show_Numpad_Frame(decimalbutton_show, minusbutton_show, &number_value, "Enter prescaler 0 to 65535") == 0) {
		STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
		return;
	}

	/* Check */
	uint16_t prescaler;
	if(number_value < 0)
		prescaler = 0;
	else if(number_value > 65535)
		prescaler = 65535;
	else
		prescaler = (uint16_t) number_value;

	/* Apply them */
	if(PWM_TIM == 0)
		STM32_PLC_PWM0_To_PWM3_Set_Prescaler(prescaler, true);
	else
		STM32_PLC_PWM4_To_PWM7_Set_Prescaler(prescaler, true);


	/* Show main frame again */
	STM32_PLC_LCD_Show_Main_Frame(frame_id, false);
}
