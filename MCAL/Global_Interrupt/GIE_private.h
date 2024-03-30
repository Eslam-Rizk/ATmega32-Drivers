/*
 * GIE_private.h
 *
 *  Created on: Dec 19, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_EXT_INT_V0_GIE_PRIVATE_H_
#define MCAL_EXT_INT_V0_GIE_PRIVATE_H_

// Define the Global Interrupt Enable bit in the Status Register (SREG)
#define SREG          *((volatile uint8*)0x5F)
#define SREG_GIE      7

#endif /* MCAL_EXT_INT_V0_GIE_PRIVATE_H_ */
