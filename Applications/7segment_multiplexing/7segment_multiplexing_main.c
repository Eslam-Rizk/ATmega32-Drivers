/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

#include <avr/io.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO.h"
#include "../HAL/7_SEG/7SEG.h"


int main()
{
	uint8 i,j,k;
	MDIO_vSetPortDir(DIO_PORTD , PORT_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTB , PIN0 , PIN_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTB , PIN1 , PIN_OUTPUT);
	MDIO_vSetPinVal(DIO_PORTB , PIN0 , PIN_LOW);
	MDIO_vSetPinVal(DIO_PORTB , PIN1 , PIN_LOW);

	while(1)
	{
		j=0;
		for(i=0 ; i<10 ; i++)
		{
			for(k=0 ; k<12 ; k++)
			{
				MDIO_vSetPinVal(DIO_PORTB , PIN0 , PIN_HIGH);	 //LEFT On
				MDIO_vSetPinVal(DIO_PORTB , PIN1 , PIN_LOW);	 //RIGHT Off
				H7SEG_vPrint(DIO_PORTD , j);					 //right display
				_delay_ms(15);
				MDIO_vSetPinVal(DIO_PORTB , PIN0 , PIN_LOW);	 //LEFT off
				MDIO_vSetPinVal(DIO_PORTB , PIN1 , PIN_HIGH);	 //RIGHT on
				H7SEG_vPrint(DIO_PORTD , i);					 //left display
				_delay_ms(15);
			}
			if (9 == i && j!= 9)
			{
				i=-1;
				j+=1;
			}
		}

	}
	return 0;
}

