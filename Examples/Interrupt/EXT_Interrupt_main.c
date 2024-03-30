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


void EXTI0_ISR(void);
void EXTI1_ISR(void);

int main()
{
	//led pins as output
	MDIO_vSetPinDir(DIO_PORTD , PIN0 , PIN_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTD , PIN5 , PIN_OUTPUT);
	MDIO_vSetPinDir(DIO_PORTD , PIN6 , PIN_OUTPUT);

	//external interrupt 0 , 1 pins
	MDIO_vSetPinDir(DIO_PORTD , PIN2 , PIN_INPUT);
	MDIO_vSetPinDir(DIO_PORTD , PIN3 , PIN_INPUT);

	//ACTIVATE PULLUP on INT0,INT1
	MDIO_vSetPinVal(DIO_PORTD , PIN2 , PIN_HIGH);
	MDIO_vSetPinVal(DIO_PORTD , PIN3 , PIN_HIGH);

	//set call back functions
	EXTI0_vSetCallBack(EXTI0_ISR);
	EXTI1_vSetCallBack(EXTI1_ISR);

	//enable interrupts
	MEXTI_vEnINT(EXT_INT0);
	MEXTI_vEnINT(EXT_INT1);
	GIE_vEnable();

	while(1)
	{
		MDIO_vSetPinVal(DIO_PORTD , PIN0 , PIN_HIGH);
		_delay_ms(1000);
		MDIO_vSetPinVal(DIO_PORTD , PIN0 , PIN_LOW);
		_delay_ms(1000);
	}
	return 0;
}


void EXTI0_ISR(void)
{
	MDIO_vSetPinVal(DIO_PORTD , PIN5 , PIN_HIGH);
	MDIO_vSetPinVal(DIO_PORTD , PIN6 , PIN_LOW);
}

void EXTI1_ISR(void)
{
	MDIO_vSetPinVal(DIO_PORTD , PIN6 , PIN_HIGH);
	MDIO_vSetPinVal(DIO_PORTD , PIN5 , PIN_LOW);
}

