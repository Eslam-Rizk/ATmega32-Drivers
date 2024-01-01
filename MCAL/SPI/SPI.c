/*
 * SPI.c
 *
 *  Created on: Dec 28, 2023
 *      Author: Eslam Rizk
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO/DIO_private.h"
#include "../DIO/DIO_config.h"
#include "../DIO/DIO.h"

#include "SPI_private.h"
#include "SPI_config.h"

void MSPI_vInit(SPI_config_t cpy_Config)
{
	/*Set SPI Mode: master / slave*/
	if(cpy_Config.MSTR_MODE == MASTER_MODE)
	{
		MDIO_vSetPinDir(SPI_PORT , MOSI , PIN_OUTPUT);
		MDIO_vSetPinDir(SPI_PORT , SCK , PIN_OUTPUT);
		SET_BIT(SPCR , SPCR_MSTR);
	}
	else if(cpy_Config.MSTR_MODE ==SLAVE_MODE)
	{
		MDIO_vSetPinDir(SPI_PORT , MISO , PIN_OUTPUT);
		CLR_BIT(SPCR , SPCR_MSTR);
	}
	else
	{

	}
	/*Set Data Order*/
	if(cpy_Config.DATA_ORDER == 1 )
	{
		SET_BIT(SPCR , SPCR_DORD);
	}
	else
	{
		CLR_BIT(SPCR , SPCR_DORD);
	}
	/*Set Clock Polarity*/
	if(cpy_Config.CLOCK_POLARITY == 1 )
	{
		SET_BIT(SPCR , SPCR_CPOL);
	}
	else
	{
		CLR_BIT(SPCR , SPCR_CPOL);
	}
	/*Set Clock Phase*/
	if(cpy_Config.CLOCK_PHASE  == 1 )
	{
		SET_BIT(SPCR , SPCR_CPHA);
	}
	else
	{
		CLR_BIT(SPCR , SPCR_CPHA);
	}
	/*Set PreScaler*/
	if(cpy_Config.SPI_PRESCALER % 2)
	{
		SET_BIT(SPCR , SPCR_SPR0);
	}
	else
	{
		CLR_BIT(SPCR , SPCR_SPR0);
	}
	if(cpy_Config.SPI_PRESCALER / 2)
	{
		SET_BIT(SPCR , SPCR_SPR1);
	}
	else
	{
		CLR_BIT(SPCR , SPCR_SPR1);
	}

	/*Set SPI Speed Mode*/
	if(cpy_Config.SPIX2_MODE == 1 )
	{
		SET_BIT(SPCR , SPSR_SPIX2);
	}
	else
	{
		CLR_BIT(SPCR , SPSR_SPIX2);
	}

}

void MSPI_vEnable(void)
{
	/*Enable SPI*/
	SET_BIT(SPCR , SPCR_SPE);
}

void MSPI_vDisable(void)
{
	/*Enable SPI*/
	CLR_BIT(SPCR , SPCR_SPE);

}

void MSPI_vWrite(uint8 cpy_uint8Data)
{
	SPDR = cpy_uint8Data;
	while((GET_BIT(SPSR , SPSR_SPIF)) == 0);

}

uint8 MSPI_uint8Read(void)
{
	while((GET_BIT(SPSR , SPSR_SPIF)) == 0);
	TOGGLE_BIT(PORTB , PIN0);
	return SPDR;
}

void MSPI_vSlaveStoreData(uint8 cpy_uint8Data)
{
		SPDR = cpy_uint8Data;
}


void MSPI_vIntEnable(void)
{
	/*Enable or Disable Interrupt*/
	SET_BIT(SPCR , SPCR_SPIE);

}

void MSPI_vIntDisable(void)
{
	/*Enable or Disable Interrupt*/
	CLR_BIT(SPCR , SPCR_SPIE);

}

