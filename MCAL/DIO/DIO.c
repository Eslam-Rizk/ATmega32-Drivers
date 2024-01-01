/* ========================================lib ========================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


/* ====================================lower layer ====================================*/

/*======================================== HAL ========================================*/
#include "DIO_private.h"
#include "DIO_config.h"
#include "DIO.h"



/*==========================void function to set pin direction=========================*/

void MDIO_vSetPinDir(uint8 cpy_uint8Port, uint8 cpy_uint8Pin, uint8 cpy_uint8Dir)
{
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		if(cpy_uint8Dir ==PIN_INPUT)
		{
			CLR_BIT(DDRA , cpy_uint8Pin);
		}
		else if(cpy_uint8Dir == PIN_OUTPUT)
		{
			SET_BIT(DDRA , cpy_uint8Pin);
		}
		else
		{

		}
		break;
	case DIO_PORTB:
		if(cpy_uint8Dir ==PIN_INPUT)
		{
			CLR_BIT(DDRB , cpy_uint8Pin);
		}
		else if(cpy_uint8Dir == PIN_OUTPUT)
		{
			SET_BIT(DDRB , cpy_uint8Pin);
		}
		else
		{

		}
		break;
	case DIO_PORTC:
		if(cpy_uint8Dir ==PIN_INPUT)
		{
			CLR_BIT(DDRC , cpy_uint8Pin);
		}
		else if(cpy_uint8Dir == PIN_OUTPUT)
		{
			SET_BIT(DDRC , cpy_uint8Pin);
		}
		else
		{

		}
		break;
	case DIO_PORTD:
		if(cpy_uint8Dir ==PIN_INPUT)
		{
			CLR_BIT(DDRD , cpy_uint8Pin);
		}
		else if(cpy_uint8Dir == PIN_OUTPUT)
		{
			SET_BIT(DDRD , cpy_uint8Pin);
		}
		else
		{

		}
		break;
	default:
		break;
	}
}

/*==========================void function to set pin value==========================*/

void MDIO_vSetPinVal(uint8 cpy_uint8Port, uint8 cpy_uint8Pin, uint8 cpy_uint8Val)
{
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		if(cpy_uint8Val ==PIN_LOW)
		{
			CLR_BIT(PORTA , cpy_uint8Pin);
		}
		else if(cpy_uint8Val == PIN_HIGH)
		{
			SET_BIT(PORTA , cpy_uint8Pin);
		}
		else
		{

		}
		break;
	case DIO_PORTB:
		if(cpy_uint8Val ==PIN_LOW)
		{
			CLR_BIT(PORTB , cpy_uint8Pin);
		}
		else if(cpy_uint8Val == PIN_HIGH)
		{
			SET_BIT(PORTB , cpy_uint8Pin);
		}
		else
		{

		}
		break;
	case DIO_PORTC:
		if(cpy_uint8Val ==PIN_LOW)
		{
			CLR_BIT(PORTC , cpy_uint8Pin);
		}
		else if(cpy_uint8Val == PIN_HIGH)
		{
			SET_BIT(PORTC , cpy_uint8Pin);
		}
		else
		{

		}
		break;
	case DIO_PORTD:
		if(cpy_uint8Val ==PIN_LOW)
		{
			CLR_BIT(PORTD , cpy_uint8Pin);
		}
		else if(cpy_uint8Val == PIN_HIGH)
		{
			SET_BIT(PORTD , cpy_uint8Pin);
		}
		else
		{

		}
		break;
	default:
		break;
	}
}

/*==========================void function to get pin value==========================*/

uint8 MDIO_uint8GetPinVal(uint8 cpy_uint8Port, uint8 cpy_uint8Pin)
{
	uint8 uint8_returnState=0;
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		uint8_returnState = GET_BIT(PINA , cpy_uint8Pin);
		break;
	case DIO_PORTB:
		uint8_returnState = GET_BIT(PINB , cpy_uint8Pin);
		break;
	case DIO_PORTC:
		uint8_returnState = GET_BIT(PINC , cpy_uint8Pin);
		break;
	case DIO_PORTD:
		uint8_returnState = GET_BIT(PIND , cpy_uint8Pin);
		break;
	default:
		break;
	}
	return uint8_returnState;
}

/*==========================void function to set port direction==========================*/

void MDIO_vSetPortDir(uint8 cpy_uint8Port, uint8 cpy_uint8Dir)
{
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		if(cpy_uint8Dir ==PORT_INPUT)
		{
			DDRA = PORT_LOW;
		}
		else if(cpy_uint8Dir == PORT_OUTPUT)
		{
			DDRA = PORT_HIGH;
		}
		else
		{

		}
		break;
	case DIO_PORTB:
		if(cpy_uint8Dir ==PORT_INPUT)
		{
			DDRB = PORT_LOW;
		}
		else if(cpy_uint8Dir == PORT_OUTPUT)
		{
			DDRB = PORT_HIGH;
		}
		else
		{

		}
		break;
	case DIO_PORTC:
		if(cpy_uint8Dir ==PORT_INPUT)
		{
			DDRC = PORT_LOW;
		}
		else if(cpy_uint8Dir == PORT_OUTPUT)
		{
			DDRC = PORT_HIGH;
		}
		else
		{

		}
		break;
	case DIO_PORTD:
		if(cpy_uint8Dir ==PORT_INPUT)
		{
			DDRD = PORT_LOW;
		}
		else if(cpy_uint8Dir == PORT_OUTPUT)
		{
			DDRD = PORT_HIGH;
		}
		else
		{

		}
		break;
	default:
		break;
	}
}

/*==========================void function to set port value==========================*/

void MDIO_vSetPortVal(uint8 cpy_uint8Port, uint8 cpy_uint8Val)
{
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		PORTA = cpy_uint8Val;
		break;
	case DIO_PORTB:
		PORTB = cpy_uint8Val;
		break;
	case DIO_PORTC:
		PORTC = cpy_uint8Val;
		break;
	case DIO_PORTD:
		PORTD = cpy_uint8Val;
		break;
	default:
		break;
	}
}

/*==========================void function to get port value==========================*/

uint8 MDIO_uint8GetPortVal(uint8 cpy_uint8Port)
{
	uint8 uint8_returnState=0;
	switch (cpy_uint8Port)
	{
	case DIO_PORTA:
		uint8_returnState = PINA ;
		break;
	case DIO_PORTB:
		uint8_returnState = PINB;
		break;
	case DIO_PORTC:
		uint8_returnState = PINC;
		break;
	case DIO_PORTD:
		uint8_returnState = PIND;
		break;
	default:
		break;
	}
	return uint8_returnState;
}
