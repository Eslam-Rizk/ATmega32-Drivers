/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/LCD/H_LCD.h"
#include "../HAL/KEYPAD/H_KEYPAD.h"
#include "../HAL/STEPPER/STEPPER.h"
#include "../MCAL/DIO/DIO.h"


int main()
{
	HLCD_vInit();
	HKeypad_vInit();
	HSTEPPER_vInit();

	MDIO_vSetPinDir(DIO_PORTA , PIN0 , PIN_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTA , PIN1 , PIN_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTC , PIN4 , PIN_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTC , PIN5 , PIN_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTC , PIN6 , PIN_INPUT);
	MDIO_vSetPinDir(DIO_PORTC , PIN7 , PIN_INPUT);
	MDIO_vSetPinVal(DIO_PORTC , PIN4 , PIN_LOW);
	MDIO_vSetPinVal(DIO_PORTC , PIN5 , PIN_LOW);
	MDIO_vSetPinVal(DIO_PORTA , PIN0 , PIN_LOW);
	MDIO_vSetPinVal(DIO_PORTA , PIN1 , PIN_LOW);
	MDIO_vSetPinVal(DIO_PORTC , PIN6 , PIN_HIGH);	//pullup
	MDIO_vSetPinVal(DIO_PORTC , PIN7 , PIN_HIGH);	//pullup
	uint8 in1,in2;

	while(1)
	{
		in1=MDIO_uint8GetPinVal(DIO_PORTC , PIN6);
		in2=MDIO_uint8GetPinVal(DIO_PORTC , PIN7);

		if(in1 == PIN_LOW && in2 != PIN_LOW)						//if right switch is pressed /* Stepper and DCmotor3*/
		{

			HLCD_vClearScreen();
			HLCD_vWriteString("Motor3 right");
			HLCD_vGotoXY(0,1);
			HLCD_vWriteString("stepper +10 deg.");

			MDIO_vSetPinVal(DIO_PORTA , PIN0 , PIN_HIGH);			//DCmotor3 right
			MDIO_vSetPinVal(DIO_PORTA , PIN1 , PIN_LOW);
			HSTEPPER_vSetStepperFAngle(10);						// stepper forward
			_delay_ms(500);

			HLCD_vClearScreen();
			HLCD_vWriteString("Motor3 stop");
			HLCD_vGotoXY(0,1);
			HLCD_vWriteString("stepper stop");

			MDIO_vSetPinVal(DIO_PORTA , PIN0 , PIN_LOW);			//DCmotor3 stop
			MDIO_vSetPinVal(DIO_PORTA , PIN1 , PIN_LOW);
			HSTEPPER_vStop();									// stepper stop
			_delay_ms(1000);

			HLCD_vClearScreen();
			HLCD_vWriteString("Motor3 left");
			HLCD_vGotoXY(0,1);
			HLCD_vWriteString("stepper -5 deg.");

			MDIO_vSetPinVal(DIO_PORTA , PIN0 , PIN_LOW);			//DCmotor3 left
			MDIO_vSetPinVal(DIO_PORTA , PIN1 , PIN_HIGH);
			HSTEPPER_vSetStepperBAngle(5);						// stepper backwards
			_delay_ms(500);

			HLCD_vClearScreen();
			HLCD_vWriteString("Motor3 stop");
			HLCD_vGotoXY(0,1);
			HLCD_vWriteString("stepper stop");

			MDIO_vSetPinVal(DIO_PORTA , PIN0 , PIN_LOW);			//DCmotor3 stop
			MDIO_vSetPinVal(DIO_PORTA , PIN1 , PIN_LOW);
			HSTEPPER_vStop();									// stepper stop
			_delay_ms(1000);
		}
		else if(in2 == PIN_LOW && in1 != PIN_LOW)					//if left switch is pressed /* DCmotor1 and DCmotor2*/
		{

			HLCD_vClearScreen();
			MDIO_vSetPinVal(DIO_PORTC , PIN4 , PIN_HIGH);		//DCmotor1 and DCmotor2 go right
			MDIO_vSetPinVal(DIO_PORTC , PIN5 , PIN_LOW);
			HLCD_vWriteString("Motor1,2 right");
			_delay_ms(1000);

			HLCD_vClearScreen();
			MDIO_vSetPinVal(DIO_PORTC , PIN4 , PIN_LOW);		//DCmotor1 and DCmotor2 stop
			MDIO_vSetPinVal(DIO_PORTC , PIN5 , PIN_LOW);
			HLCD_vWriteString("Motor1,2 OFF");
			_delay_ms(1000);

			HLCD_vClearScreen();
			MDIO_vSetPinVal(DIO_PORTC , PIN4 , PIN_LOW);		//DCmotor1 and DCmotor2 go left
			MDIO_vSetPinVal(DIO_PORTC , PIN5 , PIN_HIGH);
			HLCD_vWriteString("Motor1,2 left");
			_delay_ms(1000);

			HLCD_vClearScreen();
			MDIO_vSetPinVal(DIO_PORTC , PIN4 , PIN_LOW);		//DCmotor1 and DCmotor2 stop
			MDIO_vSetPinVal(DIO_PORTC , PIN5 , PIN_LOW);
			HLCD_vWriteString("Motor1,2 OFF");
			_delay_ms(1000);
		}
		else
		{
			HLCD_vClearScreen();
			MDIO_vSetPinVal(DIO_PORTA , PIN0 , PIN_LOW);			//DCmotor3 stop
			MDIO_vSetPinVal(DIO_PORTA , PIN1 , PIN_LOW);
			HSTEPPER_vStop();									// stepper stop
			MDIO_vSetPinVal(DIO_PORTC , PIN4 , PIN_LOW);		//DCmotor1 and DCmotor2 stop
			MDIO_vSetPinVal(DIO_PORTC , PIN5 , PIN_LOW);
			HLCD_vWriteString("ALL OFF");

		}

	}
	return 0;
}

