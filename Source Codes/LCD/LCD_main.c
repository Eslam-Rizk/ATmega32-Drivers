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
	const uint8 x=25;

	char arr[]=" c";
	HLCD_vInit();
	HLCD_vWriteNumber(x/10);
	HLCD_vWriteNumber(x%10);
	HLCD_vWriteString(arr);
	_delay_ms(1000);
	while(1)
	{
		HLCD_vGotoXY(0,0);
		HLCD_vWriteString("Eslam");
		_delay_ms(400);
		HLCD_vClearScreen();
		_delay_ms(1);

		HLCD_vGotoXY(6,1);
		HLCD_vWriteString("Eslam");
		_delay_ms(400);
		HLCD_vClearScreen();
		_delay_ms(1);

		HLCD_vGotoXY(11,0);
		HLCD_vWriteString("Eslam");
		_delay_ms(400);
		HLCD_vClearScreen();
		_delay_ms(1);

		HLCD_vGotoXY(0,1);
		HLCD_vWriteString("Eslam");
		_delay_ms(400);
		HLCD_vClearScreen();
		_delay_ms(1);

		HLCD_vGotoXY(6,0);
		HLCD_vWriteString("Eslam");
		_delay_ms(400);
		HLCD_vClearScreen();
		_delay_ms(1);

		HLCD_vGotoXY(11,1);
		HLCD_vWriteString("Eslam");
		_delay_ms(400);
		HLCD_vClearScreen();
		_delay_ms(1);
	}
	return 0;
}

