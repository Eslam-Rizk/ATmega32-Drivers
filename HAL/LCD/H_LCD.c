/*
 * HLCD_prog.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Eslam Rizk
 */

/* ======================================== lib ========================================*/
#include <util/delay.h>
#include <math.h>
#include "../../LIB/STD_TYPES.h"

/* ======================================== MCAL ========================================*/
#include "../../MCAL/DIO/DIO.h"

/*========================================= HAL =========================================*/
#include "H_LCD.h"
#include "LCD_private.h"
#include "LCD_config.h"


/*=========================== void function to initialize LCD ===========================*/
void HLCD_vInit( void )
{
	//set LCD pins configrations
	MDIO_vSetPortDir( Data_PORT , PORT_OUTPUT);
	MDIO_vSetPinDir( CTR_PORT , LCD_EN , PIN_OUTPUT);
	MDIO_vSetPinDir( CTR_PORT , LCD_RS , PIN_OUTPUT);
	MDIO_vSetPinDir( CTR_PORT , LCD_RW , PIN_OUTPUT);

	// wait for 40 ms
	_delay_ms(40);

	//send function set command
	HLCD_vSendCommand( LCD_FUNCTION_SET );

	//wait for 1 ms >> inside HLCD_vSendCommand();

	//send command "display on/off control"
	HLCD_vSendCommand(LCD_DISPLAY);

	//wait 1 ms >> inside HLCD_vSendCommand();

	// send command "clear LCD screen"
	HLCD_vSendCommand(LCD_CLEAR_SCREEN);

	//wait 2 ms
	_delay_ms(2);
}

/*=========================== static void function to send command to LCD ===========================*/

static void HLCD_vSendCommand( uint8 cpy_uint8Command )	//static to prevent using it in other files
{
	//clear RS to send command
	MDIO_vSetPinVal(CTR_PORT , LCD_RS ,PIN_LOW);

	//clear r/w to write
	MDIO_vSetPinVal(CTR_PORT , LCD_RW ,PIN_LOW);

	//send command
	MDIO_vSetPortVal(Data_PORT , cpy_uint8Command);

	//set LCD EN
	MDIO_vSetPinVal(CTR_PORT , LCD_EN ,PIN_HIGH);

	//wait 1 ms
	_delay_ms(1);

	//clear LCD EN
	MDIO_vSetPinVal(CTR_PORT , LCD_EN ,PIN_LOW);
}

/*=========================== void function to write char to LCD ===========================*/

void HLCD_vWriteChar( uint8 cpy_uint8Data )
{
	//Set RS to send Data
	MDIO_vSetPinVal(CTR_PORT , LCD_RS ,PIN_HIGH);

	//clear r/w to write
	MDIO_vSetPinVal(CTR_PORT , LCD_RW ,PIN_LOW);

	//send command
	MDIO_vSetPortVal(Data_PORT , cpy_uint8Data);

	//set LCD EN
	MDIO_vSetPinVal(CTR_PORT , LCD_EN ,PIN_HIGH);

	//wait 1 ms
	_delay_ms(1);

	//clear LCD EN
	MDIO_vSetPinVal(CTR_PORT , LCD_EN ,PIN_LOW);
}

/*=========================== void function to write string to LCD ===========================*/

void HLCD_vWriteString(const uint8 *ptr_uint8String ) //constant to prevent editing the string
{

	while(*ptr_uint8String )
	{
		HLCD_vWriteChar(*ptr_uint8String);
		ptr_uint8String++;
		_delay_ms(5);
	}
}

/*=========================== void function to clear LCD ===========================*/
void HLCD_vClearScreen(void)
{
	HLCD_vSendCommand(LCD_CLEAR_SCREEN);
	HLCD_vGotoXY(0,0);
}

/*=========================== void function to go to (x,y) position in LCD ===========================*/
void HLCD_vGotoXY( uint8 cpy_uint8PosX , uint8 cpy_uint8PosY)
{
	uint8 Local_uint8Position;

	if(cpy_uint8PosY==FIRST_ROW)
	{
		Local_uint8Position=cpy_uint8PosX;
	}
	else if(cpy_uint8PosY ==SECOND_ROW)
	{
		Local_uint8Position=cpy_uint8PosX+0x40;
	}
	else
	{

	}
	HLCD_vSendCommand(Local_uint8Position+128);
}

/*=========================== void function to write number to LCD ===========================*/
void HLCD_vWriteNumber( uint16 cpy_uint16Number)
{
	uint16 temp=cpy_uint16Number;
	uint8 i=0;
	if(cpy_uint16Number !=0)
	{
		while(temp)
		{
			i++;
			temp/=10;
		}
		temp=1;
		while(i-1)
		{
			temp*=10;
			i--;
		}
		while(temp !=1)
		{
			HLCD_vWriteChar((cpy_uint16Number/temp)+0x30);
			cpy_uint16Number%=temp;
			temp/=10;
		}
	}
	else
	{

	}
	HLCD_vWriteChar(cpy_uint16Number+0x30);
}


