/*
 * EXT_INT.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_EXT_INT_V0_EXT_INT_H_
#define MCAL_EXT_INT_V0_EXT_INT_H_

/* Enumeration for external interrupt channels */
typedef enum
{
	EXT_INT0,		// External interrupt 0
	EXT_INT1,		// External interrupt 1
	EXT_INT2		// External interrupt 2
}EXTI_channel_t;

/* Function prototypes */
void MEXTI_vEnINT(EXTI_channel_t cpy_enumChannelNum);  // Enable external interrupt
void EXTI0_vSetCallBack(void (*pf)(void));  // Set callback function for external interrupt 0
void EXTI1_vSetCallBack(void (*pf)(void));  // Set callback function for external interrupt 1
void EXTI2_vSetCallBack(void (*pf)(void));  // Set callback function for external interrupt 2

#endif /* MCAL_EXT_INT_V0_EXT_INT_H_ */
