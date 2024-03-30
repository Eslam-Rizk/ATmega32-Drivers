/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/EXT_INT_v0/EXT_INT.h"
#include "../MCAL/EXT_INT_v0/GIE.h"

// Function prototypes for the ISR (Interrupt Service Routines)
void EXTI0_ISR(void);
void EXTI1_ISR(void);

int main()
{
    // Configure LED pins as output
    MDIO_vSetPinDir(DIO_PORTD, PIN0, PIN_OUTPUT);
    MDIO_vSetPinDir(DIO_PORTD, PIN5, PIN_OUTPUT);
    MDIO_vSetPinDir(DIO_PORTD, PIN6, PIN_OUTPUT);

    // Configure external interrupt pins
    MDIO_vSetPinDir(DIO_PORTD, PIN2, PIN_INPUT);
    MDIO_vSetPinDir(DIO_PORTD, PIN3, PIN_INPUT);

    // Activate pull-up resistors on INT0 and INT1
    MDIO_vSetPinVal(DIO_PORTD, PIN2, PIN_HIGH);
    MDIO_vSetPinVal(DIO_PORTD, PIN3, PIN_HIGH);

    // Set callback functions for external interrupts
    EXTI0_vSetCallBack(EXTI0_ISR);
    EXTI1_vSetCallBack(EXTI1_ISR);

    // Enable interrupts for INT0 and INT1
    MEXTI_vEnINT(EXT_INT0);
    MEXTI_vEnINT(EXT_INT1);
    
    // Enable global interrupts
    GIE_vEnable();

    while(1)
    {
        // Toggle LED on PIN0 every 1 second
        MDIO_vSetPinVal(DIO_PORTD, PIN0, PIN_HIGH);
        _delay_ms(1000);
        MDIO_vSetPinVal(DIO_PORTD, PIN0, PIN_LOW);
        _delay_ms(1000);
    }
    return 0;
}

// External Interrupt 0 ISR
void EXTI0_ISR(void)
{
    // Set PIN5 high and PIN6 low
    MDIO_vSetPinVal(DIO_PORTD, PIN5, PIN_HIGH);
    MDIO_vSetPinVal(DIO_PORTD, PIN6, PIN_LOW);
}

// External Interrupt 1 ISR
void EXTI1_ISR(void)
{
    // Set PIN6 high and PIN5 low
    MDIO_vSetPinVal(DIO_PORTD, PIN6, PIN_HIGH);
    MDIO_vSetPinVal(DIO_PORTD, PIN5, PIN_LOW);
}
