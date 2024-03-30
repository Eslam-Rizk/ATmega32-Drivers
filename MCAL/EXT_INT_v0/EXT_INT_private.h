/*
 * EXT_INT_private.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_EXT_INT_V0_EXT_INT_PRIVATE_H_
#define MCAL_EXT_INT_V0_EXT_INT_PRIVATE_H_

// Definitions for registers related to external interrupts

#define MCUCR				*((volatile uint8*)0x55)	// MCU Control Register (sensing register for INT0 and INT1)
#define MCUCR_ISC00			0							// Interrupt Sense Control bit 0 for INT0
#define MCUCR_ISC01     	1							// Interrupt Sense Control bit 1 for INT0
#define MCUCR_ISC10			2							// Interrupt Sense Control bit 0 for INT1
#define MCUCR_ISC11     	3							// Interrupt Sense Control bit 1 for INT1

#define MCUCSR				*((volatile uint8*)0x54)	// MCU Control and Status Register (sensing register for INT2)
#define MCUCSR_ISC2     	6							// Interrupt Sense Control bit for INT2

#define GICR				*((volatile uint8*)0x5B)	// General Interrupt Control Register (interrupt enable register for INT0, INT1, and INT2)
#define GICR_INT0     		6							// Interrupt Enable bit for INT0
#define GICR_INT1     		7							// Interrupt Enable bit for INT1
#define GICR_INT2     		5							// Interrupt Enable bit for INT2

#define GIFR				*((volatile uint8*)0x5A)	// General Interrupt Flag Register (flag register for INT0, INT1, and INT2)
#define GIFR_INTF0			6							// Interrupt Flag bit for INT0
#define GIFR_INTF1			7							// Interrupt Flag bit for INT1
#define GIFR_INTF2			5							// Interrupt Flag bit for INT2

// Definitions for sensing types
#define LOW_LEVEL			1							// Low Level Sensing
#define ANY_CHANGE			2							// Any Logical Change Sensing
#define RISING_EDGE			3							// Rising Edge Sensing
#define FALLING_EDGE		4							// Falling Edge Sensing

#endif /* MCAL_EXT_INT_V0_EXT_INT_PRIVATE_H_ */
