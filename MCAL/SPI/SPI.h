/*
 * SPI.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

void MSPI_vInit(SPI_config_t);
void MSPI_vEnable(void);
void MSPI_vDisable(void);
void MSPI_vWrite(uint8);
uint8 MSPI_uint8Read(void);
void MSPI_vSlaveStoreData(uint8);
void MSPI_vIntEnable(void);
void MSPI_vIntDisable(void);

#endif /* MCAL_SPI_SPI_H_ */
