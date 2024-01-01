/*
 * USART.h
 *
 *  Created on: Dec 27, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_

void MUART_vInit(void);
void MUART_vSendChar(uint8 Cpy_data);
uint8 MUART_uint8GetChar(void);
void MUART_vSendString (const uint8 *Cpy_StrPtr);
void MUART_vGetString (uint8 *Cpy_StrPtr);
void MUART_uint8GetAsynch (void (*func)(void), uint8 *Cpy_DataPtr);

#endif /* MCAL_USART_USART_H_ */
