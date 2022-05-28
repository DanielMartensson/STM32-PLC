/*
 * Save_Load_Struct.c
 *
 *  Created on: 22 sep. 2021
 *      Author: Daniel Mårtensson
 */

#include "../../Open SAE J1939/Hardware/Hardware.h"

/* Layers */
#include "../../Functions.h"

bool Save_Struct(uint8_t data[], uint32_t data_length, char file_name[]){
#if PROCESSOR_CHOICE == STM32

#elif PROCESSOR_CHOICE == ARDUINO
	/* Implement your memory handler function for the Arduino platform */
#elif PROCESSOR_CHOICE == PIC
	/* Implement your memory handler function for the PIC platform */
#elif PROCESSOR_CHOICE == AVR
	/* Implement your memory handler function for the AVR platform */
#endif
	return true;
}

bool Load_Struct(uint8_t data[], uint32_t data_length, char file_name[]){
#if PROCESSOR_CHOICE == STM32

#elif PROCESSOR_CHOICE == ARDUINO
	/* Implement your memory handler function for the Arduino platform */
#elif PROCESSOR_CHOICE == PIC
	/* Implement your memory handler function for the PIC platform */
#elif PROCESSOR_CHOICE == AVR
	/* Implement your memory handler function for the AVR platform */
#endif
	return true;
}
