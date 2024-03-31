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
	MUART_vInit();
	while (1)
	{
		MUART_vSendChar(0xDB);
		_delay_ms(1000);
		MUART_vSendChar(0x8D);
		_delay_ms(1000);
		MUART_vSendChar(0xAA);
		_delay_ms(1000);

	}
}

