/*
 * ADC.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Eslam Rizk
 */

/* Include necessary libraries */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/* Include lower layer header files */
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO.h"

/* Function to set pin direction */
void MDIO_vSetPinDir(uint8 cpy_uint8Port, uint8 cpy_uint8Pin, uint8 cpy_uint8Dir)
{
	/* Select the port and set pin direction based on the input parameters */
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		if (cpy_uint8Dir == PIN_INPUT)
		{
			CLR_BIT(DDRA, cpy_uint8Pin);  // Clear the corresponding bit in the DDRA register to set the pin as input
		}
		else if (cpy_uint8Dir == PIN_OUTPUT)
		{
			SET_BIT(DDRA, cpy_uint8Pin);  // Set the corresponding bit in the DDRA register to set the pin as output
		}
		break;
	case DIO_PORTB:
		if (cpy_uint8Dir == PIN_INPUT)
		{
			CLR_BIT(DDRB, cpy_uint8Pin);  // Clear the corresponding bit in the DDRB register to set the pin as input
		}
		else if (cpy_uint8Dir == PIN_OUTPUT)
		{
			SET_BIT(DDRB, cpy_uint8Pin);  // Set the corresponding bit in the DDRB register to set the pin as output
		}
		break;
	case DIO_PORTC:
		if (cpy_uint8Dir == PIN_INPUT)
		{
			CLR_BIT(DDRC, cpy_uint8Pin);  // Clear the corresponding bit in the DDRC register to set the pin as input
		}
		else if (cpy_uint8Dir == PIN_OUTPUT)
		{
			SET_BIT(DDRC, cpy_uint8Pin);  // Set the corresponding bit in the DDRC register to set the pin as output
		}
		break;
	case DIO_PORTD:
		if (cpy_uint8Dir == PIN_INPUT)
		{
			CLR_BIT(DDRD, cpy_uint8Pin);  // Clear the corresponding bit in the DDRD register to set the pin as input
		}
		else if (cpy_uint8Dir == PIN_OUTPUT)
		{
			SET_BIT(DDRD, cpy_uint8Pin);  // Set the corresponding bit in the DDRD register to set the pin as output
		}
		break;
	default:
		break;
	}
}

/* Function to set pin value */
void MDIO_vSetPinVal(uint8 cpy_uint8Port, uint8 cpy_uint8Pin, uint8 cpy_uint8Val)
{
	/* Select the port and set pin value based on the input parameters */
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		if (cpy_uint8Val == PIN_LOW)
		{
			CLR_BIT(PORTA, cpy_uint8Pin);  // Clear the corresponding bit in the PORTA register to set the pin value low
		}
		else if (cpy_uint8Val == PIN_HIGH)
		{
			SET_BIT(PORTA, cpy_uint8Pin);  // Set the corresponding bit in the PORTA register to set the pin value high
		}
		break;
	case DIO_PORTB:
		if (cpy_uint8Val == PIN_LOW)
		{
			CLR_BIT(PORTB, cpy_uint8Pin);  // Clear the corresponding bit in the PORTB register to set the pin value low
		}
		else if (cpy_uint8Val == PIN_HIGH)
		{
			SET_BIT(PORTB, cpy_uint8Pin);  // Set the corresponding bit in the PORTB register to set the pin value high
		}
		break;
	case DIO_PORTC:
		if (cpy_uint8Val == PIN_LOW)
		{
			CLR_BIT(PORTC, cpy_uint8Pin);  // Clear the corresponding bit in the PORTC register to set the pin value low
		}
		else if (cpy_uint8Val == PIN_HIGH)
		{
			SET_BIT(PORTC, cpy_uint8Pin);  // Set the corresponding bit in the PORTC register to set the pin value high
		}
		break;
	case DIO_PORTD:
		if (cpy_uint8Val == PIN_LOW)
		{
			CLR_BIT(PORTD, cpy_uint8Pin);  // Clear the corresponding bit in the PORTD register to set the pin value low
		}
		else if (cpy_uint8Val == PIN_HIGH)
		{
			SET_BIT(PORTD, cpy_uint8Pin);  // Set the corresponding bit in the PORTD register to set the pin value high
		}
		break;
	default:
		break;
	}
}

/* Function to get pin value */
uint8 MDIO_uint8GetPinVal(uint8 cpy_uint8Port, uint8 cpy_uint8Pin)
{
	uint8 uint8_returnState = 0;
	/* Select the port and get pin value */
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		uint8_returnState = GET_BIT(PINA, cpy_uint8Pin);  // Get the value of the specified pin in the PORTA register
		break;
	case DIO_PORTB:
		uint8_returnState = GET_BIT(PINB, cpy_uint8Pin);  // Get the value of the specified pin in the PORTB register
		break;
	case DIO_PORTC:
		uint8_returnState = GET_BIT(PINC, cpy_uint8Pin);  // Get the value of the specified pin in the PORTC register
		break;
	case DIO_PORTD:
		uint8_returnState = GET_BIT(PIND, cpy_uint8Pin);  // Get the value of the specified pin in the PORTD register
		break;
	default:
		break;
	}
	return uint8_returnState;
}

/* Function to set port direction */
void MDIO_vSetPortDir(uint8 cpy_uint8Port, uint8 cpy_uint8Dir)
{
	/* Select the port and set port direction based on the input parameters */
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		if (cpy_uint8Dir == PORT_INPUT)
		{
			DDRA = PORT_LOW;  // Set the PORTA register to set all pins as input
		}
		else if (cpy_uint8Dir == PORT_OUTPUT)
		{
			DDRA = PORT_HIGH;  // Set the PORTA register to set all pins as output
		}
		break;
	case DIO_PORTB:
		if (cpy_uint8Dir == PORT_INPUT)
		{
			DDRB = PORT_LOW;  // Set the PORTB register to set all pins as input
		}
		else if (cpy_uint8Dir == PORT_OUTPUT)
		{
			DDRB = PORT_HIGH;  // Set the PORTB register to set all pins as output
		}
		break;
	case DIO_PORTC:
		if (cpy_uint8Dir == PORT_INPUT)
		{
			DDRC = PORT_LOW;  // Set the PORTC register to set all pins as input
		}
		else if (cpy_uint8Dir == PORT_OUTPUT)
		{
			DDRC = PORT_HIGH;  // Set the PORTC register to set all pins as output
		}
		break;
	case DIO_PORTD:
		if (cpy_uint8Dir == PORT_INPUT)
		{
			DDRD = PORT_LOW;  // Set the PORTD register to set all pins as input
		}
		else if (cpy_uint8Dir == PORT_OUTPUT)
		{
			DDRD = PORT_HIGH;  // Set the PORTD register to set all pins as output
		}
		break;
	default:
		break;
	}
}

/* Function to set port value */
void MDIO_vSetPortVal(uint8 cpy_uint8Port, uint8 cpy_uint8Val)
{
	/* Select the port and set port value based on the input parameters */
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		PORTA = cpy_uint8Val;  // Set the value of PORTA register
		break;
	case DIO_PORTB:
		PORTB = cpy_uint8Val;  // Set the value of PORTB register
		break;
	case DIO_PORTC:
		PORTC = cpy_uint8Val;  // Set the value of PORTC register
		break;
	case DIO_PORTD:
		PORTD = cpy_uint8Val;  // Set the value of PORTD register
		break;
	default:
		break;
	}
}

/* Function to get port value */
uint8 MDIO_uint8GetPortVal(uint8 cpy_uint8Port)
{
	uint8 uint8_returnState = 0;
	/* Select the port and get port value */
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		uint8_returnState = PINA;  // Get the value of PORTA register
		break;
	case DIO_PORTB:
		uint8_returnState = PINB;  // Get the value of PORTB register
		break;
	case DIO_PORTC:
		uint8_returnState = PINC;  // Get the value of PORTC register
		break;
	case DIO_PORTD:
		uint8_returnState = PIND;  // Get the value of PORTD register
		break;
	default:
		break;
	}
	return uint8_returnState;
}
