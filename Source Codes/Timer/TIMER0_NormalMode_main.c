/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "util/delay.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/DIO/DIO_private.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER0/TIMER0_private.h"
#include "../MCAL/TIMER0/TIMER0_config.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/Global_Interrupt/GIE.h"


void T0OV_ISR(void);
void toggle_pin(void);

int main()
{
	MDIO_vSetPinDir(DIO_PORTA , PIN2 , PIN_OUTPUT);
	MDIO_vSetPinVal(DIO_PORTA , PIN2 , PIN_HIGH);
	T0OV_vSetCallBack(T0OV_ISR);			//set call back
	MTIMER0_vInit();
	GIE_vEnable();
	MTIMER0_vSetDelay_ms(1000);
	MTIMER0_vStart();

	while (1)
	{

	}
}

void toggle_pin(void)
{
	TOGGLE_BIT(PORTA , PIN2);
	//MTIMER0_vStop();

}

void T0OV_ISR(void)
{
	toggle_pin();
}

