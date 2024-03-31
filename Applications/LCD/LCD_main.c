/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

/*LIB*/
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/H_LCD.h"

int main()
{
    const uint8 x = 25; // Declare and initialize a constant variable 'x'

    char arr[] = " c"; // Declare and initialize a character array 'arr' with value " c"
    
    // Initialize the LCD
    HLCD_vInit();
    
    // Write the tens digit of 'x' to the LCD
    HLCD_vWriteNumber(x / 10);
    
    // Write the ones digit of 'x' to the LCD
    HLCD_vWriteNumber(x % 10);
    
    // Write the string 'arr' to the LCD
    HLCD_vWriteString(arr);
    
    // Delay for 1 second
    _delay_ms(1000);

    // Infinite loop
    while(1)
    {
        // Display "Eslam" at position (0, 0) on the LCD
        HLCD_vGotoXY(0, 0);
        HLCD_vWriteString("Eslam");
        _delay_ms(400);
        
        // Clear the LCD screen
        HLCD_vClearScreen();
        _delay_ms(1);

        // Display "Eslam" at position (6, 1) on the LCD
        HLCD_vGotoXY(6, 1);
        HLCD_vWriteString("Eslam");
        _delay_ms(400);
        
        // Clear the LCD screen
        HLCD_vClearScreen();
        _delay_ms(1);

        // Display "Eslam" at position (11, 0) on the LCD
        HLCD_vGotoXY(11, 0);
        HLCD_vWriteString("Eslam");
        _delay_ms(400);
        
        // Clear the LCD screen
        HLCD_vClearScreen();
        _delay_ms(1);

        // Display "Eslam" at position (0, 1) on the LCD
        HLCD_vGotoXY(0, 1);
        HLCD_vWriteString("Eslam");
        _delay_ms(400);
        
        // Clear the LCD screen
        HLCD_vClearScreen();
        _delay_ms(1);

        // Display "Eslam" at position (6, 0) on the LCD
        HLCD_vGotoXY(6, 0);
        HLCD_vWriteString("Eslam");
        _delay_ms(400);
        
        // Clear the LCD screen
        HLCD_vClearScreen();
        _delay_ms(1);

        // Display "Eslam" at position (11, 1) on the LCD
        HLCD_vGotoXY(11, 1);
        HLCD_vWriteString("Eslam");
        _delay_ms(400);
        
        // Clear the LCD screen
        HLCD_vClearScreen();
        _delay_ms(1);
    }
    return 0;
}
