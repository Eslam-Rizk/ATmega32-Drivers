/*
 * WATCHDOG.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Eslam Rizk
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO.h"
#include "WATCHDOG_private.h"
#include "WATCHDOG_config.h"
#include "WATCHDOG.h"

void MWATCHDOG_vEnable(void)
{
	// Enable watchdog timer by setting the WDE bit in the WDTCR register
	SET_BIT(WDTCR , WDTCR_WDE);
}

void MWATCHDOG_vDisable(void)
{
	// Disable watchdog timer by writing specific sequence to the WDTCR register
	WDTCR |= (uint8)(0x18);
	WDTCR &= ~(uint8)(0x8);
}

void MWATCHDOG_uint16SleepTime(uint8 cpy_uint8Prescaler)
{
	// Set the watchdog timer sleep time by setting the prescaler bits in the WDTCR register
	WDTCR |= cpy_uint8Prescaler;
}
