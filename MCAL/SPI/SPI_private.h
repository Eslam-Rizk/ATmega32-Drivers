/*
 * SPI_private.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

//SPI Control Register
#define SPCR 					  *((volatile uint8*)0x2d)
#define SPCR_SPIE				  7
#define SPCR_SPE				  6
#define SPCR_DORD				  5
#define SPCR_MSTR				  4
#define SPCR_CPOL				  3
#define SPCR_CPHA				  2
#define SPCR_SPR1				  1
#define SPCR_SPR0				  0

//SPI Status Register
#define SPSR					  *((volatile uint8*)0x2e)
#define SPSR_SPIF				  7
#define SPSR_WCOL				  6
#define SPSR_SPIX2				  0

//SPI Data Register
#define SPDR 					  *((volatile uint8*)0x2f)

//SPI pins
#define SPI_PORT				  DIO_PORTB
#define	SS						  PIN4
#define	MOSI					  PIN5
#define	MISO					  PIN6
#define	SCK						  PIN7

//Enable SPI
#define SPI_ENABLE				  1
#define SPI_DISABLE				  0

//SPI Interrupt
#define SPI_INT_ENABLE			  1
#define SPI_INT_DISABLE			  0
//Modes
#define   SLAVE_MODE			  0
#define   MASTER_MODE			  1

#define   LSB_DATA_ORDER		  1
#define   MSB_DATA_ORDER		  0

#define   SCK_IDLE_HIGH		      1
#define   SCK_IDLE_LOW		      0

#define   LEADING_SCK_READ	      0
#define   LEADING_SCK_WRITE	      1

#define   SPIX2_OFF			      0
#define   SPIX2_ON			      1

#define	  SPIE_ENABLE			  1
#define	  SPIE_DISABLE			  0

//PreScaler values
#define   SCK_PRESCALER_4	   	  0
#define   SCK_PRESCALER_16	      1
#define   SCK_PRESCALER_64	      2
#define   SCK_PRESCALER_128	      3

#define   SCK_PRESCALER_X2_2	  0
#define   SCK_PRESCALER_X2_8	  1
#define   SCK_PRESCALER_X2_32	  2
#define   SCK_PRESCALER_X2_64	  3



#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
