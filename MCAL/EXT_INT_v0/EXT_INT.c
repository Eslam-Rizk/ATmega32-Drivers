/*
 * EXT_INT.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Eslam Rizk
 */

#include <stdlib.h>
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXT_INT.h"
#include "EXT_INT_private.h"
#include "EXT_INT_config.h"

//global function pointers to pass the address of the defined ISR functions from main to the ISR
void (*EXTI0_CallBack)(void) = NULL;
void (*EXTI1_CallBack)(void) = NULL;
void (*EXTI2_CallBack)(void) = NULL;

//call back functions to pass ISR function address from main to the functions pointers
void EXTI0_vSetCallBack(void (*pf)(void))
{
	EXTI0_CallBack = pf;
}
void EXTI1_vSetCallBack(void (*pf)(void))
{
	EXTI1_CallBack = pf;
}
void EXTI2_vSetCallBack(void (*pf)(void))
{
	EXTI2_CallBack = pf;
}

//enable external interrupts and set the sensing type
void MEXTI_vEnINT(EXTI_channel_t cpy_enumChannelNum)
{
	switch(cpy_enumChannelNum)
	{
	case EXT_INT0:
#if EXTI0_SENSE == LOW_LEVEL

		CLR_BIT(MCUCR ,MCUCR_ISC00);
		CLR_BIT(MCUCR ,MCUCR_ISC01);

#elif EXTI0_SENSE == ANY_CHANGE

		SET_BIT(MCUCR ,MCUCR_ISC00);
		CLR_BIT(MCUCR ,MCUCR_ISC01);

#elif EXTI0_SENSE == RISING_EDGE

		SET_BIT(MCUCR ,MCUCR_ISC00);
		SET_BIT(MCUCR ,MCUCR_ISC01);

#elif EXTI0_SENSE == FALLING_EDGE

		CLR_BIT(MCUCR ,MCUCR_ISC00);
		SET_BIT(MCUCR ,MCUCR_ISC01);

#else
#error "Invalid Sense Control"
#endif
		SET_BIT(GICR , GICR_INT0);			//enable INT0

		break;
	case EXT_INT1:
#if EXTI1_SENSE == LOW_LEVEL

		CLR_BIT(MCUCR ,MCUCR_ISC10);
		CLR_BIT(MCUCR ,MCUCR_ISC11);

#elif EXTI1_SENSE == ANY_CHANGE

		SET_BIT(MCUCR ,MCUCR_ISC10);
		CLR_BIT(MCUCR ,MCUCR_ISC11);

#elif EXTI1_SENSE == RISING_EDGE

		SET_BIT(MCUCR ,MCUCR_ISC10);
		SET_BIT(MCUCR ,MCUCR_ISC11);

#elif EXTI1_SENSE == FALLING_EDGE

		CLR_BIT(MCUCR ,MCUCR_ISC10);
		SET_BIT(MCUCR ,MCUCR_ISC11);

#else
#error "Invalid Sense Control"
#endif
		SET_BIT(GICR , GICR_INT1);			//enable INT1
		break;
	case EXT_INT2:
#if EXTI2_SENSE == RISING_EDGE

		SET_BIT(MCUCSR ,MCUCSR_ISC2);

#elif EXTI2_SENSE == FALLING_EDGE

		CLR_BIT(MCUCSR ,MCUCSR_ISC2);


#else
#error "Invalid Sense Control"
#endif
		SET_BIT(GICR , GICR_INT2);			//enable INT2
		break;
	default:
		break;
	}
}


//ISR of external INT0, INT1, INT2
void __vector_1(void)		__attribute__((signal));
void __vector_1(void)
{
	if(EXTI0_CallBack != NULL)
	{
		EXTI0_CallBack();
	}

}


void __vector_2(void)		__attribute__((signal));
void __vector_2(void)
{
	if(EXTI1_CallBack != NULL)
	{
		EXTI1_CallBack();
	}
}



void __vector_3(void)		__attribute__((signal));
void __vector_3(void)
{
	if(EXTI2_CallBack != NULL)
	{
		EXTI2_CallBack();
	}
}

