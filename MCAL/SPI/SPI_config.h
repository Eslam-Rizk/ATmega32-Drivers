/*
 * SPI_config.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

/*OPTIONS:
 * 			SPI_MODE:
 * 		        	SLAVE_MODE
		        	MASTER_MODE

		    DATA_ORDER:
		        	LSB_DATA_ORDER
		        	MSB_DATA_ORDER

		    CLOCK_POLARITY:
		        	SCK_IDLE_HIGH
		        	SCK_IDLE_LOW

		    CLOCK_PHASE:
		        	LEADING_SCK_READ
		        	LEADING_SCK_WRITE

		    SPIX2_MODE:
		    		SPIX2_ON
		    		SPIX2_OFF

		    SCK_PRESCALER (SPIX2 Cleared):
		        	SCK_PRESCALER_4
		        	SCK_PRESCALER_16
		        	SCK_PRESCALER_64
		        	SCK_PRESCALER_128

		    SCK_PRESCALER (SPIX2 set):
		        	SCK_PRESCALER_X2_2
		        	SCK_PRESCALER_X2_8
		        	SCK_PRESCALER_X2_32
		        	SCK_PRESCALER_X2_64
 *
 * */

/*Make an object of SPI_config_t in APP before MSPI_vInit(SPI_config_t) to set SPI configuration*/
typedef struct
{
	uint8 SPI_PRESCALER:2;
	uint8 CLOCK_PHASE:1;
	uint8 CLOCK_POLARITY:1;
	uint8 MSTR_MODE:1;
	uint8 DATA_ORDER:1;
	uint8 SPIX2_MODE:1;

}SPI_config_t;

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
