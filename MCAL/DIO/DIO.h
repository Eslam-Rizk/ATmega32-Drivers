/*
 * ADC.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Eslam Rizk
 */
 
/* File Guard */
#ifndef DIO_H
#define DIO_H

/*=====================================Pin Direction====================================*/
#define PIN_INPUT  0
#define PIN_OUTPUT 1

/*======================================Pin State=======================================*/
#define PIN_HIGH 1
#define PIN_LOW 0

/*====================================Port Direction====================================*/
#define PORT_OUTPUT 0xFF																  //255
#define PORT_INPUT  0

/*======================================Port State======================================*/
#define PORT_HIGH	0xFF
#define PORT_LOW	0

/*=======================================Pin Index======================================*/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

/*======================================Port Index======================================*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/*=================================Functions Prototypes=================================*/

void MDIO_vSetPinDir(uint8 cpy_uint8Port, uint8 cpy_uint8Pin, uint8 cpy_uint8Dir); 		//MCAL DIO VOID SET PIN DIRECTION
void MDIO_vSetPinVal(uint8 cpy_uint8Port, uint8 cpy_uint8Pin, uint8 cpy_uint8Val); 		//MCAL DIO VOID SET PIN VALUE
uint8 MDIO_uint8GetPinVal(uint8 cpy_uint8Port, uint8 cpy_uint8Pin);					    //MCAL DIO VOID GET PIN VALUE

void MDIO_vSetPortDir(uint8 cpy_uint8Port, uint8 cpy_uint8Dir); 						//MCAL DIO VOID SET PORT DIRECTION
void MDIO_vSetPortVal(uint8 cpy_uint8Port, uint8 cpy_uint8Val);						    //MCAL DIO VOID SET PORT VALUE
uint8 MDIO_uint8GetPortVal(uint8 cpy_uint8Port);										//MCAL DIO VOID GET PORT VALUE



#endif
