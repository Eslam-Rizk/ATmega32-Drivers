/*
 * USART.h
 *
 *  Created on: Dec 27, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_

/* Function prototypes */

/**
 * @brief Initialize the USART module.
 */
void MUART_vInit(void);

/**
 * @brief Transmit a single character over USART.
 * @param Cpy_data: The character to be transmitted.
 */
void MUART_vSendChar(uint8 Cpy_data);

/**
 * @brief Receive a single character over USART.
 * @return The received character.
 */
uint8 MUART_uint8GetChar(void);

/**
 * @brief Transmit a string over USART.
 * @param Cpy_StrPtr: Pointer to the string to be transmitted.
 */
void MUART_vSendString(const uint8 *Cpy_StrPtr);

/**
 * @brief Receive a string over USART.
 * @param Cpy_StrPtr: Pointer to the buffer to store the received string.
 */
void MUART_vGetString(uint8 *Cpy_StrPtr);

/**
 * @brief Receive data asynchronously with callback function support.
 * @param func: Pointer to the callback function to be called when data is received.
 * @param Cpy_DataPtr: Pointer to the buffer to store the received data.
 */
void MUART_uint8GetAsynch(void (*func)(void), uint8 *Cpy_DataPtr);

#endif /* MCAL_USART_USART_H_ */
