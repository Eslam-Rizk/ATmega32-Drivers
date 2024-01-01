/*
 * TIMER0.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Eslam Rizk
 */

#include <stdlib.h>
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0.h"

uint32 OV_Number = 0;

#if NORMAL_MODE == TIMER0_MODE

void (*T0OV_CallBack)(void) = NULL;

//call back functions to pass ISR function address from main to the functions pointers
void T0OV_vSetCallBack(void (*pf)(void))
{
	T0OV_CallBack = pf;
}

#elif CTC_MODE == TIMER0_MODE

void (*T0OC_CallBack)(void) = NULL;

//call back functions to pass ISR function address from main to the functions pointers
void T0OC_vSetCallBack(void (*pf)(void))
{
	T0OC_CallBack = pf;
}

#endif

void MTIMER0_vInit(void)
{
#if NORMAL_MODE == TIMER0_MODE
	/*Clear Force Compare on OC0 in Normal Mode*/
	CLR_BIT(TCCR0 , TCCR0_FOC0);
	/*Set Timer Mode TO Normal Mode*/
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);
	/*Disconnect OC0*/
	CLR_BIT(TCCR0 , TCCR0_COM00);
	CLR_BIT(TCCR0 , TCCR0_COM01);
	/*Clear On_Compare_Interrupt_Enable*/
	CLR_BIT(TIMSK , TIMSK_OCIE0);
	/*SET Timer_OverFlow_Interrupt_Enable*/
	SET_BIT(TIMSK , TIMSK_TOIE0);

#elif CTC_MODE == TIMER0_MODE
	/*Clear Force Compare on OC0 in CTC Mode*/
	CLR_BIT(TCCR0 , TCCR0_FOC0);
	/*Set Timer Mode To CTC Mode*/
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);
	/*Disconnect OC0*/
	CLR_BIT(TCCR0 , TCCR0_COM00);
	CLR_BIT(TCCR0 , TCCR0_COM01);
	/*SET On_Compare_Interrupt_Enable*/
	SET_BIT(TIMSK , TIMSK_OCIE0);
	/*CLR Timer_OverFlow_Interrupt_Enable*/
	CLR_BIT(TIMSK , TIMSK_TOIE0);

#endif


}
void MTIMER0_vSetDelay_ms(uint64 cpy_uint32Time)
{
#if NORMAL_MODE == TIMER0_MODE
	uint8 PreLoad=0;
	uint32 TickTime = PRESCALER_VALUE / FREQUENCY_MHZ;
	uint32 TotalTicks = cpy_uint32Time * MS_US_CONVERT / TickTime;
	PreLoad = COUNTER_RESOLUTION - (TotalTicks % COUNTER_RESOLUTION);  //preload =256 >> preload = 0 because it's of uint8 type which will write 1 at the 8th bit(1 0000 0000)
	if(COUNTER_RESOLUTION == PreLoad)
	{
		OV_Number = TotalTicks / COUNTER_RESOLUTION;
	}
	else
	{
		OV_Number = (TotalTicks / COUNTER_RESOLUTION) + 1;
		/*Store PreLoad value to the TCNT0 register*/
		TCNT0 = PreLoad;
	}
#elif CTC_MODE == TIMER0_MODE

	uint8 resolution = COUNTER_RESOLUTION-1;
	uint32 TickTime = PRESCALER_VALUE / FREQUENCY_MHZ;
	uint32 TotalTicks = cpy_uint32Time * MS_US_CONVERT / TickTime;

	while((TotalTicks % (resolution+1)))
	{
		resolution--;
	}
	OCR0 = resolution;
	OV_Number = TotalTicks / resolution;

#endif
}
void MTIMER0_vStart(void)
{
	/*Set PreScaler Value */
#if T0_PRESCALER_1 == PRESCALER_VALUE
	TCCR0 = (TCCR0 & TCCR0_CSmax) | T0_PRESCALER_cs_1;
#elif T0_PRESCALER_8 == PRESCALER_VALUE
	TCCR0 = (TCCR0 & TCCR0_CSmax) | T0_PRESCALER_cs_8;
#elif T0_PRESCALER_64 == PRESCALER_VALUE
	TCCR0 = (TCCR0 & TCCR0_CSmax) | T0_PRESCALER_cs_64;
#elif T0_PRESCALER_256 == PRESCALER_VALUE
	TCCR0 = (TCCR0 & TCCR0_CSmax) | T0_PRESCALER_cs_256;
#elif T0_PRESCALER_1024 == PRESCALER_VALUE
	TCCR0 = (TCCR0 & TCCR0_CSmax) | T0_PRESCALER_cs_1024;
#endif


}

void MTIMER0_vStop(void)
{
	/*Clear CS pins & 11111000*/
	TCCR0 &= ~TCCR0_CSmax;
}

#if NORMAL_MODE == TIMER0_MODE

void __vector_11(void)		__attribute__((signal));
void __vector_11(void)
{
	static uint32 counter=0;

	counter++;
	if(OV_Number == counter)
	{
		if(T0OV_CallBack != NULL)
		{
			T0OV_CallBack();
		}
		counter=0;
	}
	else
	{

	}

}

#elif CTC_MODE == TIMER0_MODE

void __vector_10(void)		__attribute__((signal));
void __vector_10(void)
{
	static uint32 counter=0;

	counter++;
	if(OV_Number == counter)
	{

		if(T0OC_CallBack != NULL)
		{
			T0OC_CallBack();
		}
		counter=0;
	}
	else
	{

	}
}

#endif
