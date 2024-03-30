/*
 * SPI_private.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

// SPI Control Register (SPCR) bits definitions
#define SPCR            *((volatile uint8*)0x2d)
#define SPCR_SPIE       7   // SPI Interrupt Enable
#define SPCR_SPE        6   // SPI Enable
#define SPCR_DORD       5   // Data Order (0: MSB transmitted first, 1: LSB transmitted first)
#define SPCR_MSTR       4   // Master/Slave Select (0: Slave Mode, 1: Master Mode)
#define SPCR_CPOL       3   // Clock Polarity (0: SCK low when idle, 1: SCK high when idle)
#define SPCR_CPHA       2   // Clock Phase (0: Leading edge is sample, 1: Trailing edge is sample)
#define SPCR_SPR1       1   // SPI Clock Rate Select 1
#define SPCR_SPR0       0   // SPI Clock Rate Select 0

// SPI Status Register (SPSR) bits definitions
#define SPSR            *((volatile uint8*)0x2e)
#define SPSR_SPIF       7   // SPI Interrupt Flag (Set when transmission is complete)
#define SPSR_WCOL       6   // Write Collision Flag (Set if new data is written before the previous data has been transmitted)
#define SPSR_SPIX2      0   // Double SPI Speed Bit

// SPI Data Register (SPDR)
#define SPDR            *((volatile uint8*)0x2f)

// SPI pins
#define SPI_PORT        DIO_PORTB   // SPI port
#define SS              PIN4        // Slave Select pin
#define MOSI            PIN5        // Master Out Slave In pin
#define MISO            PIN6        // Master In Slave Out pin
#define SCK             PIN7        // Serial Clock pin

// Enable/disable definitions
#define SPI_ENABLE      1   // Enable SPI
#define SPI_DISABLE     0   // Disable SPI
#define SPI_INT_ENABLE  1   // Enable SPI interrupt
#define SPI_INT_DISABLE 0   // Disable SPI interrupt

// Modes definitions
#define SLAVE_MODE      0   // SPI Slave Mode
#define MASTER_MODE     1   // SPI Master Mode

// Data order definitions
#define LSB_DATA_ORDER  1   // LSB transmitted first
#define MSB_DATA_ORDER  0   // MSB transmitted first

// Clock polarity definitions
#define SCK_IDLE_HIGH   1   // SCK is high when idle
#define SCK_IDLE_LOW    0   // SCK is low when idle

// Clock phase definitions
#define LEADING_SCK_READ    0   // Sample on leading edge
#define LEADING_SCK_WRITE   1   // Sample on trailing edge

// SPIx2 speed definitions
#define SPIX2_OFF       0   // Disable SPIx2 speed
#define SPIX2_ON        1   // Enable SPIx2 speed

// SPI interrupt definitions
#define SPIE_ENABLE     1   // Enable SPI interrupt
#define SPIE_DISABLE    0   // Disable SPI interrupt

// Prescaler values
#define SCK_PRESCALER_4     0   // Prescaler: fosc/4
#define SCK_PRESCALER_16    1   // Prescaler: fosc/16
#define SCK_PRESCALER_64    2   // Prescaler: fosc/64
#define SCK_PRESCALER_128   3   // Prescaler: fosc/128

#define SCK_PRESCALER_X2_2  0   // Double speed mode: fosc/2
#define SCK_PRESCALER_X2_8  1   // Double speed mode: fosc/8
#define SCK_PRESCALER_X2_32 2   // Double speed mode: fosc/32
#define SCK_PRESCALER_X2_64 3   // Double speed mode: fosc/64

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
