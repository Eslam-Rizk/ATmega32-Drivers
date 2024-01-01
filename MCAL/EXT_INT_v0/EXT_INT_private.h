/*
 * EXT_INT_private.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_EXT_INT_V0_EXT_INT_PRIVATE_H_
#define MCAL_EXT_INT_V0_EXT_INT_PRIVATE_H_

#define MCUCR		*((volatile uint8*)0x55)				//sensing register for int0,int1
#define MCUCR_ISC00		0
#define MCUCR_ISC01     1
#define MCUCR_ISC10		2
#define MCUCR_ISC11     3

#define MCUCSR		*((volatile uint8*)0x54)				//sensing register for int2
#define MCUCSR_ISC2     6

#define GICR		*((volatile uint8*)0x5B)				//interrupt enable register for int0,int1,int2
#define GICR_INT0     6
#define GICR_INT1     7
#define GICR_INT2     5

#define GIFR		*((volatile uint8*)0x5A)				//Flag register for int0, int1, int2
#define GIFR_INTF0		6
#define GIFR_INTF1		7
#define GIFR_INTF2		5

#define LOW_LEVEL		1
#define ANY_CHANGE		2
#define RISING_EDGE		3
#define FALLING_EDGE	4



#endif /* MCAL_EXT_INT_V0_EXT_INT_PRIVATE_H_ */
