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
    /* Set SPI Mode: master / slave */
    if(cpy_Config.MSTR_MODE == MASTER_MODE)
    {
        // Set MOSI and SCK pins as output for master mode
        MDIO_vSetPinDir(SPI_PORT , MOSI , PIN_OUTPUT);
        MDIO_vSetPinDir(SPI_PORT , SCK , PIN_OUTPUT);
        // Set master mode
        SET_BIT(SPCR , SPCR_MSTR);
    }
    else if(cpy_Config.MSTR_MODE ==SLAVE_MODE)
    {
        // Set MISO pin as output for slave mode
        MDIO_vSetPinDir(SPI_PORT , MISO , PIN_OUTPUT);
        // Set slave mode
        CLR_BIT(SPCR , SPCR_MSTR);
    }
    else
    {
        // Error: Invalid SPI mode
    }

    /* Set Data Order */
    if(cpy_Config.DATA_ORDER == LSB_DATA_ORDER)
    {
        // Set LSB first
        SET_BIT(SPCR , SPCR_DORD);
    }
    else
    {
        // Set MSB first
        CLR_BIT(SPCR , SPCR_DORD);
    }

    /* Set Clock Polarity */
    if(cpy_Config.CLOCK_POLARITY == SCK_IDLE_HIGH)
    {
        // Set SCK idle high
        SET_BIT(SPCR , SPCR_CPOL);
    }
    else
    {
        // Set SCK idle low
        CLR_BIT(SPCR , SPCR_CPOL);
    }

    /* Set Clock Phase */
    if(cpy_Config.CLOCK_PHASE  == LEADING_SCK_WRITE)
    {
        // Set leading edge of SCK for data capture
        SET_BIT(SPCR , SPCR_CPHA);
    }
    else
    {
        // Set leading edge of SCK for data change
        CLR_BIT(SPCR , SPCR_CPHA);
    }

    /* Set PreScaler */
    if(cpy_Config.SPI_PRESCALER % 2)
    {
        // Set SPR0
        SET_BIT(SPCR , SPCR_SPR0);
    }
    else
    {
        // Clear SPR0
        CLR_BIT(SPCR , SPCR_SPR0);
    }

    if(cpy_Config.SPI_PRESCALER / 2)
    {
        // Set SPR1
        SET_BIT(SPCR , SPCR_SPR1);
    }
    else
    {
        // Clear SPR1
        CLR_BIT(SPCR , SPCR_SPR1);
    }

    /* Set SPI Speed Mode */
    if(cpy_Config.SPIX2_MODE == SPIX2_ON)
    {
        // Set SPI2X bit for double speed mode
        SET_BIT(SPCR , SPSR_SPIX2);
    }
    else
    {
        // Clear SPI2X bit for normal speed mode
        CLR_BIT(SPCR , SPSR_SPIX2);
    }
}

void MSPI_vEnable(void)
{
    /* Enable SPI */
    SET_BIT(SPCR , SPCR_SPE);
}

void MSPI_vDisable(void)
{
    /* Disable SPI */
    CLR_BIT(SPCR , SPCR_SPE);
}

void MSPI_vWrite(uint8 cpy_uint8Data)
{
    // Write data to SPDR register
    SPDR = cpy_uint8Data;
    // Wait until data transmission is complete
    while((GET_BIT(SPSR , SPSR_SPIF)) == 0);
}

uint8 MSPI_uint8Read(void)
{
    // Wait until data reception is complete
    while((GET_BIT(SPSR , SPSR_SPIF)) == 0);
    // Toggle an LED or any other indicator to visualize data reception
    TOGGLE_BIT(PORTB , PIN0);
    // Return the received data
    return SPDR;
}

void MSPI_vSlaveStoreData(uint8 cpy_uint8Data)
{
    // Write data to SPDR register
    SPDR = cpy_uint8Data;
}

void MSPI_vIntEnable(void)
{
    /* Enable SPI interrupt */
    SET_BIT(SPCR , SPCR_SPIE);
}

void MSPI_vIntDisable(void)
{
    /* Disable SPI interrupt */
    CLR_BIT(SPCR , SPCR_SPIE);
}
