/*
 * 7SEG.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

/* ========================================lib ========================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* ======================================== MCAL ========================================*/
#include "../../MCAL/DIO/DIO.h"

/* ======================================== HAL ========================================*/
#include "7SEG.h"
#include "7SEG_private.h"
#include "7SEG_config.h"



/* array to hold numbers from 0 to 9 in HEX */
uint8 arr_7SEG[10]={0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x7, 0x7F, 0x6F};

/*======================= void function to write a number on 7seg output pins =======================*/
void H7SEG_vPrint(uint8 cpy_uint8Num, uint8 cpy_uint8Val)
{
	MDIO_vSetPortVal(cpy_uint8Num , arr_7SEG[cpy_uint8Val]);
}

