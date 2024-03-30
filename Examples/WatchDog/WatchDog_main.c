/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "util/delay.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/WatchDogTimer/WATCHDOG.h"
#include "../MCAL/WatchDogTimer/WATCHDOG_private.h"
#include "../MCAL/WatchDogTimer/WATCHDOG_config.h"

int main()
{
	_delay_ms(1000);
	MDIO_vSetPinDir(DIO_PORTB , PIN0 , PIN_OUTPUT);
	MDIO_vSetPinVal(DIO_PORTB , PIN0 , PIN_HIGH);

	MWATCHDOG_uint16SleepTime(WDPrescaler);
	MWATCHDOG_vEnable();
	while (1)
	{

	}
}


