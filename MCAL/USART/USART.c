/*
 * USART.c
 *
 *  Created on: Dec 27, 2023
 *      Author: Eslam Rizk
 */

#include <stdlib.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "USART.h"
#include "USART_Private.h"
#include "USART_config.h"


void (* UART_G_PtrToFunc)(void) = NULL ;
uint8 *UART_DataPtr ;

void MUART_vInit(void)
{
	/* Enable RX and TX */
	SET_BIT(UCSRB , UCSRB_RXEN);
	SET_BIT(UCSRB , UCSRB_TXEN);

	/* Set to Asynch
	 * No parity
	 * One stop bit
	 * 8 bit mode
	 */
	UCSRC = 0b10000110  ;

	/* Set Buad rate to 9600 at Fosc = 8MHZ , Normal Speed Rate Ux2=0*/
	UBRRL = 51 ;
}


void MUART_vSendChar(uint8 Cpy_data)
{
	while (GET_BIT(UCSRA , UCSRA_UDRE) == 0);
	UDR = Cpy_data ;
}

uint8 MUART_uint8GetChar(void)
{
	while (GET_BIT(UCSRA , UCSRA_RXC) == 0);
	return UDR ;
}

void MUART_vSendString (const uint8 *Cpy_StrPtr)
{
	while (*Cpy_StrPtr != NULL)
	{
		MUART_vSendChar(*Cpy_StrPtr);
		Cpy_StrPtr++;
	}
}

void MUART_vGetString (uint8 *Cpy_StrPtr)
{
	do
	{
		*Cpy_StrPtr = MUART_uint8GetChar();
		Cpy_StrPtr++;
	}while (*(Cpy_StrPtr-1) != '\r');
	*(Cpy_StrPtr-1) = NULL;
}


void MUART_uint8GetAsynch (void (*func)(void) , uint8 *Cpy_DataPtr)
{
	if ((func != NULL) && (Cpy_DataPtr != NULL))
	{
		UART_G_PtrToFunc = func ;
		UART_DataPtr = Cpy_DataPtr;
	}
	else
	{

	}
	/* Enable Receive Interrupt */
	SET_BIT(UCSRB ,UCSRB_RXCIE);
}

void __vector_13 (void) __attribute__((signal)) ;
void __vector_13 (void)
{
	if (UART_G_PtrToFunc != NULL)
	{
		*UART_DataPtr = UDR ;
		UART_G_PtrToFunc();
	}
}
