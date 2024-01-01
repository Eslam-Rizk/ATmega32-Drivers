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
	SET_BIT(WDTCR , WDTCR_WDE);
}

void MWATCHDOG_vDisable(void)
{
	WDTCR |= (0x18);
	WDTCR &= ~(0x8);

}

void MWATCHDOG_uint16SleepTime(uint8 cpy_uint8Prescaler)
{
	WDTCR |= cpy_uint8Prescaler;
}
