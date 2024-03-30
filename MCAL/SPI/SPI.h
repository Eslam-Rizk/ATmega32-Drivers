/*
 * SPI.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "SPI_config.h"

void MSPI_vInit(SPI_config_t);      // Initialize SPI with the provided configuration
void MSPI_vEnable(void);             // Enable SPI module
void MSPI_vDisable(void);            // Disable SPI module
void MSPI_vWrite(uint8);             // Write data to SPI
uint8 MSPI_uint8Read(void);          // Read data from SPI
void MSPI_vSlaveStoreData(uint8);    // Store data to be transmitted by the slave
void MSPI_vIntEnable(void);          // Enable SPI interrupt
void MSPI_vIntDisable(void);         // Disable SPI interrupt

#endif /* MCAL_SPI_SPI_H_ */
