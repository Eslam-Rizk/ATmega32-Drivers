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
    // Initialize watchdog timer with the specified sleep time
    _delay_ms(1000); // Delay to allow the system to stabilize before watchdog configuration
    MDIO_vSetPinDir(DIO_PORTB, PIN0, PIN_OUTPUT); // Set PIN0 of PORTB as output
    MDIO_vSetPinVal(DIO_PORTB, PIN0, PIN_HIGH);   // Set PIN0 high initially

    // Configure the watchdog timer sleep time and enable it
    MWATCHDOG_uint16SleepTime(WDPrescaler);
    MWATCHDOG_vEnable();

    while (1)
    {
        // Infinite loop to keep the microcontroller running
    }
}
