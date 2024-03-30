/*
 * HLCD_prog.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Eslam Rizk
 */

/* Include necessary libraries */
#include <util/delay.h>
#include <math.h>
#include "../../LIB/STD_TYPES.h"

/* Include MCU Abstraction Layer (MCAL) */
#include "../../MCAL/DIO/DIO.h"

/* Include header files for HAL (Hardware Abstraction Layer) */
#include "H_LCD.h"
#include "LCD_private.h"
#include "LCD_config.h"

/* Initialize the LCD */
void HLCD_vInit(void)
{
    // Set LCD pins configurations
    MDIO_vSetPortDir(Data_PORT, PORT_OUTPUT);
    MDIO_vSetPinDir(CTR_PORT, LCD_EN, PIN_OUTPUT);
    MDIO_vSetPinDir(CTR_PORT, LCD_RS, PIN_OUTPUT);
    MDIO_vSetPinDir(CTR_PORT, LCD_RW, PIN_OUTPUT);

    // Wait for 40 ms
    _delay_ms(40);

    // Send function set command
    HLCD_vSendCommand(LCD_FUNCTION_SET);

    // Send command "display on/off control"
    HLCD_vSendCommand(LCD_DISPLAY);

    // Send command "clear LCD screen"
    HLCD_vSendCommand(LCD_CLEAR_SCREEN);

    // Wait 2 ms
    _delay_ms(2);
}

/* Static function to send command to LCD */
static void HLCD_vSendCommand(uint8 cpy_uint8Command)
{
    // Clear RS to send command
    MDIO_vSetPinVal(CTR_PORT, LCD_RS, PIN_LOW);

    // Clear R/W to write
    MDIO_vSetPinVal(CTR_PORT, LCD_RW, PIN_LOW);

    // Send command
    MDIO_vSetPortVal(Data_PORT, cpy_uint8Command);

    // Set LCD EN
    MDIO_vSetPinVal(CTR_PORT, LCD_EN, PIN_HIGH);

    // Wait 1 ms
    _delay_ms(1);

    // Clear LCD EN
    MDIO_vSetPinVal(CTR_PORT, LCD_EN, PIN_LOW);
}

/* Function to write a character to LCD */
void HLCD_vWriteChar(uint8 cpy_uint8Data)
{
    // Set RS to send data
    MDIO_vSetPinVal(CTR_PORT, LCD_RS, PIN_HIGH);

    // Clear R/W to write
    MDIO_vSetPinVal(CTR_PORT, LCD_RW, PIN_LOW);

    // Send data
    MDIO_vSetPortVal(Data_PORT, cpy_uint8Data);

    // Set LCD EN
    MDIO_vSetPinVal(CTR_PORT, LCD_EN, PIN_HIGH);

    // Wait 1 ms
    _delay_ms(1);

    // Clear LCD EN
    MDIO_vSetPinVal(CTR_PORT, LCD_EN, PIN_LOW);
}

/* Function to write a string to LCD */
void HLCD_vWriteString(const uint8 *ptr_uint8String)
{
    while (*ptr_uint8String)
    {
        // Write each character in the string
        HLCD_vWriteChar(*ptr_uint8String);
        ptr_uint8String++;
        _delay_ms(5);
    }
}

/* Function to clear LCD screen */
void HLCD_vClearScreen(void)
{
    // Send command to clear LCD screen
    HLCD_vSendCommand(LCD_CLEAR_SCREEN);

    // Set cursor to home
    HLCD_vGotoXY(0, 0);
}

/* Function to go to (x,y) position in LCD */
void HLCD_vGotoXY(uint8 cpy_uint8PosX, uint8 cpy_uint8PosY)
{
    uint8 Local_uint8Position;

    // Calculate position based on row
    if (cpy_uint8PosY == FIRST_ROW)
    {
        Local_uint8Position = cpy_uint8PosX;
    }
    else if (cpy_uint8PosY == SECOND_ROW)
    {
        Local_uint8Position = cpy_uint8PosX + 0x40;
    }
    else
    {
        // No action needed
    }

    // Send command to set cursor position
    HLCD_vSendCommand(Local_uint8Position + 128);
}

/* Function to write a number to LCD */
void HLCD_vWriteNumber(uint16 cpy_uint16Number)
{
    uint16 temp = cpy_uint16Number;
    uint8 i = 0;

    // Count number of digits
    if (cpy_uint16Number != 0)
    {
        while (temp)
        {
            i++;
            temp /= 10;
        }
        temp = 1;
        while (i - 1)
        {
            temp *= 10;
            i--;
        }
        while (temp != 1)
        {
            // Write each digit of the number
            HLCD_vWriteChar((cpy_uint16Number / temp) + 0x30);
            cpy_uint16Number %= temp;
            temp /= 10;
        }
    }
    else
    {
        // No action needed
    }

    // Write the last digit
    HLCD_vWriteChar(cpy_uint16Number + 0x30);
}
