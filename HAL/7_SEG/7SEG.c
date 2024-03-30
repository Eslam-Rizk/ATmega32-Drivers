/*
 * 7SEG.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

/* Include necessary libraries */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include MCU Abstraction Layer (MCAL) */
#include "../../MCAL/DIO/DIO.h"

/* Include header files for HAL (Hardware Abstraction Layer) */
#include "7SEG.h"
#include "7SEG_private.h"
#include "7SEG_config.h"

/* Array to hold numbers from 0 to 9 in HEX */
uint8 arr_7SEG[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

/* Function to write a number to 7-segment display */
void H7SEG_vPrint(uint8 cpy_uint8Num, uint8 cpy_uint8Val)
{
    // Set the output pins of the 7-segment display to display the given number
    MDIO_vSetPortVal(cpy_uint8Num , arr_7SEG[cpy_uint8Val]);
}
