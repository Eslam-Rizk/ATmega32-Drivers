/*
 * STEPPER.C
 *
 *  Created on: Dec 14, 2023
 *      Author: Eslam Rizk
 */


/* Include necessary libraries */
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"

/* Include MCU Abstraction Layer (MCAL) */
#include "../../MCAL/DIO/DIO.h"

/* Include header files for HAL (Hardware Abstraction Layer) */
#include "STEPPER.h"
#include "STEPPER_private.h"
#include "STEPPER_config.h"

/* Function to initialize the stepper motor */
void HSTEPPER_vInit(void)
{
    HLCD_vInit(); // Initialize LCD for debugging
    MDIO_vSetPinDir(STEPPER_PORT, PINK_PIN, PIN_OUTPUT);
    MDIO_vSetPinDir(STEPPER_PORT, ORANGE_PIN, PIN_OUTPUT);
    MDIO_vSetPinDir(STEPPER_PORT, YELLOW_PIN, PIN_OUTPUT);
    MDIO_vSetPinDir(STEPPER_PORT, BLUE_PIN, PIN_OUTPUT);
    _delay_ms(1); // Delay for stabilization
    // Set all pins high initially
    MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_HIGH);
    MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_HIGH);
    MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_HIGH);
    MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH);
    _delay_ms(1); // Delay for stabilization
}

/* Function to stop the stepper motor */
void HSTEPPER_vStop()
{
    // Set all pins high to stop the motor
    MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_HIGH);
    MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_HIGH);
    MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_HIGH);
    MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH);
}

/* Function to set forward angle for the stepper motor */
void HSTEPPER_vSetStepperFAngle(uint8 cpy_uint8Angle)
{
    uint8 iterator = round(cpy_uint8Angle / CYCLE_ANGEL); // Calculate the number of steps needed
    while (iterator)
    {
        // Set the sequence for forward motion
        MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_LOW);
        MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH);
        _delay_ms(350 / SPEED); // Delay for step
        // Repeat for the other steps
        MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_LOW);
        MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH);
        _delay_ms(350 / SPEED);
        MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_LOW);
        MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH);
        _delay_ms(350 / SPEED);
        MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_LOW);
        _delay_ms(350 / SPEED);
        iterator--; // Decrement iterator
    }
    MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH); // Set last pin high
}

/* Function to set reverse angle for the stepper motor */
void HSTEPPER_vSetStepperRAngle(uint8 cpy_uint8Angle)
{
    uint8 iterator = round(cpy_uint8Angle / CYCLE_ANGEL); // Calculate the number of steps needed
    while (iterator)
    {
        // Set the sequence for reverse motion
        MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_LOW);
        _delay_ms(350 / SPEED); // Delay for step
        // Repeat for the other steps
        MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_LOW);
        MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH);
        _delay_ms(350 / SPEED);
        MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_LOW);
        MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH);
        _delay_ms(350 / SPEED);
        MDIO_vSetPinVal(STEPPER_PORT, PINK_PIN, PIN_LOW);
        MDIO_vSetPinVal(STEPPER_PORT, ORANGE_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, YELLOW_PIN, PIN_HIGH);
        MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH);
        _delay_ms(350 / SPEED);
        iterator--; // Decrement iterator
    }
    MDIO_vSetPinVal(STEPPER_PORT, BLUE_PIN, PIN_HIGH); // Set last pin high
}
