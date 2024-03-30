/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "util/delay.h"

#include "../MCAL/DIO/DIO_private.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/DIO/DIO.h"

#include "../MCAL/USART/USART_private.h"
#include "../MCAL/USART/USART_config.h"
#include "../MCAL/USART/USART.h"

#include "../MCAL/Global_Interrupt/GIE.h"


int main()
{
	MDIO_vSetPortDir(DIO_PORTC , PORT_OUTPUT);
	MDIO_vSetPortVal(DIO_PORTC , PORT_LOW);

	MUART_vInit();
	uint8 data=0;
	while (1)
	{
		data=MUART_uint8GetChar();
		if(data != 0)
		{
			MDIO_vSetPortVal(DIO_PORTC , data);
		}
		_delay_ms(100);
	}
}

