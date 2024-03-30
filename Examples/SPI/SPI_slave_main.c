/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "util/delay.h"

#include "../MCAL/DIO/DIO_private.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/DIO/DIO.h"

#include "../MCAL/SPI/SPI_private.h"
#include "../MCAL/SPI/SPI_config.h"
#include "../MCAL/SPI/SPI.h"



int main()
{
	uint8 Data=0;
	SPI_config_t SPIconfig;
	MDIO_vSetPortDir(DIO_PORTD , PORT_OUTPUT);		//pordtD LEDs
	MDIO_vSetPortVal(DIO_PORTD , PORT_LOW);
	MDIO_vSetPinDir(DIO_PORTB ,PIN0 , PIN_OUTPUT);	//portB LED toggle after flag is set
	MDIO_vSetPinVal(DIO_PORTB ,PIN0 ,PIN_LOW);

	SPIconfig.MSTR_MODE = SLAVE_MODE;
	SPIconfig.DATA_ORDER = LSB_DATA_ORDER;
	SPIconfig.CLOCK_POLARITY = SCK_IDLE_LOW;
	SPIconfig.CLOCK_PHASE = LEADING_SCK_WRITE;
	SPIconfig.SPI_PRESCALER = SCK_PRESCALER_4;
	SPIconfig.SPIX2_MODE = SPIX2_OFF;

	MSPI_vSlaveStoreData(0xDB);

	MSPI_vInit(SPIconfig);
	MSPI_vEnable();

	while (1)
	{
		Data = MSPI_uint8Read();
		MDIO_vSetPortVal(DIO_PORTD , Data);

	}
}
