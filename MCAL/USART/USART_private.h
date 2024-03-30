/*
 * USART_private.h
 *
 *  Created on: Dec 27, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

//USART Data Register
#define UDR					*((volatile uint8*)0x2c)

//USART Control and Status Register A
#define UCSRA				*((volatile uint8*)0x2b)
#define UCSRA_RXC			7       // USART Receive Complete       		     initial value 0
#define UCSRA_TXC			6       // USART Transmit Complete      		     initial value 0
#define UCSRA_UDRE			5       // USART Data Register Empty    		     initial value 1
#define UCSRA_FE			4       // Frame Error                  		     initial value 0
#define UCSRA_DOR			3       // Data OverRun                              initial value 0
#define UCSRA_PE			2       // Parity Error                              initial value 0
#define UCSRA_U2X			1       // Double the USART Transmission Speed       initial value 0
#define UCSRA_MPCM			0       // Multi-processor Communication Mode        initial value 0

//USART Control and Status Register B
#define UCSRB				*((volatile uint8*)0x2a)
#define UCSRB_RXCIE         7       //RX Complete Interrupt Enable 				 initial value 0
#define UCSRB_TXCIE         6       //TX Complete Interrupt Enable 				 initial value 0
#define UCSRB_UDRIE         5       //USART Data Register Empty Interrupt Enable initial value 0
#define UCSRB_RXEN          4       //Receiver Enable 							 initial value 0
#define UCSRB_TXEN          3       //Transmitter Enabl 						 initial value 0
#define UCSRB_UCSZ2         2       //Character Size							 initial value 0
#define UCSRB_RXB8          1       //Receive Data Bit 8						 initial value 0
#define UCSRB_TXB8          0       //Transmit Data Bit 8						 initial value 0

//USART Control and Status Register C
#define UCSRC				*((volatile uint8*)0x40)
#define UCSRC_URSEL         7		//Register Select between UBRRH & UCSRC 	 initial value 1(UCSRC)
#define UCSRC_UMSEL         6       //USART Mode Select							 initial value 0(Asynch)
#define UCSRC_UPM1          5       //Parity Mode								 initial value 0
#define UCSRC_UPM0          4       //Parity Mode							 	 initial value 0
#define UCSRC_USBS          3       //Stop Bit Select							 initial value 0
#define UCSRC_UCSZ1         2       //Character Size							 initial value 1
#define UCSRC_UCSZ0         1       //Character Size							 initial value 1
#define UCSRC_UCPOL         0       //Clock Polarity							 initial value 0

#define UBRRH           *((volatile uint8*)0x40) // USART Baud Rate Register High
#define UBRRL           *((volatile uint8*)0x29) // USART Baud Rate Register Low

#endif /* MCAL_USART_USART_PRIVATE_H_ */
