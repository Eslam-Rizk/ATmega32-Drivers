/*
 * H_KEYPAD.c
 *
 *  Created on: Dec 12, 2023
 *      Author: Eslam Rizk
 */

/* Include necessary libraries */
#include "../../LIB/STD_TYPES.h"

/* Include MCU Abstraction Layer (MCAL) */
#include "../../MCAL/DIO/DIO.h"

/* Include header files for HAL (Hardware Abstraction Layer) */
#include "H_KEYPAD.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

/* Initialize the Keypad */
void HKeypad_vInit(void)
{
    // Set keypad pins configurations
    // Set row pins as PIN_INPUT
    MDIO_vSetPinDir(KEYPAD_PORT , ROW_PIN0 , PIN_INPUT);
    MDIO_vSetPinDir(KEYPAD_PORT , ROW_PIN1 , PIN_INPUT);
    MDIO_vSetPinDir(KEYPAD_PORT , ROW_PIN2 , PIN_INPUT);
    MDIO_vSetPinDir(KEYPAD_PORT , ROW_PIN3 , PIN_INPUT);

    // Set columns pins as PIN_OUTPUT
    MDIO_vSetPinDir(KEYPAD_PORT , COL_PIN0 , PIN_OUTPUT);
    MDIO_vSetPinDir(KEYPAD_PORT , COL_PIN1 , PIN_OUTPUT);
    MDIO_vSetPinDir(KEYPAD_PORT , COL_PIN2 , PIN_OUTPUT);
    MDIO_vSetPinDir(KEYPAD_PORT , COL_PIN3 , PIN_OUTPUT);

    // Activate pullup resistors for all rows
    MDIO_vSetPinVal(KEYPAD_PORT , ROW_PIN0 , PIN_HIGH);
    MDIO_vSetPinVal(KEYPAD_PORT , ROW_PIN1 , PIN_HIGH);
    MDIO_vSetPinVal(KEYPAD_PORT , ROW_PIN2 , PIN_HIGH);
    MDIO_vSetPinVal(KEYPAD_PORT , ROW_PIN3 , PIN_HIGH);

    // Deactivate all columns
    MDIO_vSetPinVal(KEYPAD_PORT , COL_PIN0 , PIN_HIGH);
    MDIO_vSetPinVal(KEYPAD_PORT , COL_PIN1 , PIN_HIGH);
    MDIO_vSetPinVal(KEYPAD_PORT , COL_PIN2 , PIN_HIGH);
    MDIO_vSetPinVal(KEYPAD_PORT , COL_PIN3 , PIN_HIGH);
}

/* Read pressed key from Keypad */
uint8 HKeypad_uint8GetKey(void)
{
    uint8 Local_uint8ReturnPressedKey = Not_Pressed;
    uint8 Local_uint8PressedKey;
    uint8 Col_Iterator, Row_Iterator, flag = 0;
    uint8 KeyPad_arr[ROW_SIZE][COL_SIZE] = {{'7','8','9','/'},
                                             {'4','5','6','*'},
                                             {'1','2','3','-'},
                                             {'#','0','=','+'}};
    uint8 Col_arr[COL_SIZE] = {COL_PIN0, COL_PIN1, COL_PIN2, COL_PIN3};
    uint8 Row_arr[ROW_SIZE] = {ROW_PIN0, ROW_PIN1, ROW_PIN2, ROW_PIN3};

    for (Col_Iterator = 0; Col_Iterator < COL_SIZE && flag != 1; Col_Iterator++)
    {
        // Activate current column
        MDIO_vSetPinVal(KEYPAD_PORT , Col_arr[Col_Iterator] , PIN_LOW);

        for (Row_Iterator = 0; Row_Iterator < ROW_SIZE && flag != 1; Row_Iterator++)
        {
            // Check all rows
            Local_uint8PressedKey = MDIO_uint8GetPinVal(KEYPAD_PORT , Row_arr[Row_Iterator]);

            if (PIN_LOW == Local_uint8PressedKey)
            {
                // Retrieve the pressed key
                Local_uint8ReturnPressedKey = KeyPad_arr[Row_Iterator][Col_Iterator];
                /* busy wait until key is released */
                while (PIN_LOW == Local_uint8PressedKey)
                {
                    Local_uint8PressedKey = MDIO_uint8GetPinVal(KEYPAD_PORT , Row_arr[Row_Iterator]);
                }
                flag = 1;
                
            }
            else
            {
                // No code needed
            }
        }
        /* Deactivate current column */
        MDIO_vSetPinVal(KEYPAD_PORT , Col_arr[Col_Iterator] , PIN_HIGH);
    }

    return Local_uint8ReturnPressedKey;
}
