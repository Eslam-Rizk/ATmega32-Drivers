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
#include "../MCAL/DIO/DIO_private.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER0/TIMER0_private.h"
#include "../MCAL/TIMER0/TIMER0_config.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/Global_Interrupt/GIE.h"

// Function prototypes
void toggle_pin(void);
void T0OV_ISR(void);

int main()
{
    // Initialize PIN2 of PORTA as an output pin and set it high initially
    MDIO_vSetPinDir(DIO_PORTA, PIN2, PIN_OUTPUT);
    MDIO_vSetPinVal(DIO_PORTA, PIN2, PIN_HIGH);

    // Set the overflow ISR callback function and initialize TIMER0
    T0OV_vSetCallBack(T0OV_ISR);
    MTIMER0_vInit();

    // Enable global interrupts
    GIE_vEnable();

    // Set TIMER0 delay to 1000 ms and start the timer
    MTIMER0_vSetDelay_ms(1000);
    MTIMER0_vStart();

    while (1)
    {
        // Infinite loop to keep the microcontroller running
    }
}

// Function to toggle PIN2 of PORTA
void toggle_pin(void)
{
    TOGGLE_BIT(PORTA, PIN2); // Toggle PIN2
}

// TIMER0 overflow ISR
void T0OV_ISR(void)
{
    toggle_pin(); // Call toggle_pin function
}
