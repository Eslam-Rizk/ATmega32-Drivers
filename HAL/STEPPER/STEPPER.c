/*
 * STEPPER.C
 *
 *  Created on: Dec 14, 2023
 *      Author: Eslam Rizk
 */


/* ========================================lib ========================================*/
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"

/* ======================================= MCAL =======================================*/
#include "../../MCAL/DIO/DIO.h"

/* ======================================== HAL =======================================*/
#include "STEPPER.h"
#include "STEPPER_private.h"
#include "STEPPER_config.h"

/*======================void function to initialize Stepper Motor======================*/
void HSTEPPER_vInit(void)
{
	HLCD_vInit();
	MDIO_vSetPinDir(STEPPER_PORT , PINK_PIN   , PIN_OUTPUT);
	MDIO_vSetPinDir(STEPPER_PORT , ORANGE_PIN , PIN_OUTPUT);
	MDIO_vSetPinDir(STEPPER_PORT , YELLOW_PIN , PIN_OUTPUT);
	MDIO_vSetPinDir(STEPPER_PORT , BLUE_PIN   , PIN_OUTPUT);
	_delay_ms(1);
	MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN   , PIN_HIGH);
	MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN , PIN_HIGH);
	MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN , PIN_HIGH);
	MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN   , PIN_HIGH);
	_delay_ms(1);
}

/*======================void function to stop Stepper Motor======================*/
void HSTEPPER_vStop()
{
	MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN    , PIN_HIGH);
	MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN  , PIN_HIGH);
	MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN  , PIN_HIGH);
	MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_HIGH);
}

/*==================void function to set Stepper Forward Angle===================*/
void HSTEPPER_vSetStepperFAngle(uint8 cpy_uint8Angle)
{
	uint8 iterator=round(cpy_uint8Angle / CYCLE_ANGEL);			//round number to nearest decimal

	while(iterator)
	{
		MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN    , PIN_LOW);
		MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_HIGH);
		_delay_ms(350/SPEED);


		MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN    , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN  , PIN_LOW);
		MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_HIGH);
		_delay_ms(350/SPEED);

		MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN    , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN  , PIN_LOW);
		MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_HIGH);
		_delay_ms(350/SPEED);

		MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN    , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_LOW);
		_delay_ms(350/SPEED);

		iterator--;
	}
	MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_HIGH);

}

/*==================void function to set Stepper Reverse Angle===================*/
void HSTEPPER_vSetStepperRAngle(uint8 cpy_uint8Angle)
{
	uint8 iterator=round(cpy_uint8Angle / CYCLE_ANGEL);			//round number to nearest decimal

	while(iterator)
	{
		MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN    , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_LOW);
		_delay_ms(350/SPEED);

		MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN    , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN  , PIN_LOW);
		MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_HIGH);
		_delay_ms(350/SPEED);

		MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN    , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN  , PIN_LOW);
		MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_HIGH);
		_delay_ms(350/SPEED);

		MDIO_vSetPinVal(STEPPER_PORT , PINK_PIN    , PIN_LOW);
		MDIO_vSetPinVal(STEPPER_PORT , ORANGE_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , YELLOW_PIN  , PIN_HIGH);
		MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_HIGH);
		_delay_ms(350/SPEED);

		iterator--;
	}
	MDIO_vSetPinVal(STEPPER_PORT , BLUE_PIN    , PIN_HIGH);

}

