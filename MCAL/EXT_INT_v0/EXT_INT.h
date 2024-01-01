/*
 * EXT_INT.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_EXT_INT_V0_EXT_INT_H_
#define MCAL_EXT_INT_V0_EXT_INT_H_

typedef enum
{
	EXT_INT0,		//0
	EXT_INT1,		//1
	EXT_INT2		//2
}EXTI_channel_t;

//pre_build
void MEXTI_vEnINT(EXTI_channel_t cpy_enumChannelNum);
void EXTI0_vSetCallBack(void (*pf)(void));
void EXTI1_vSetCallBack(void (*pf)(void));
void EXTI2_vSetCallBack(void (*pf)(void));

#endif /* MCAL_EXT_INT_V0_EXT_INT_H_ */
