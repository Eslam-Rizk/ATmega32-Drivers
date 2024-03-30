/*
 * ADC.c
 *
 *  Created on: Dec 20, 2023
 *      Author: Eslam Rizk
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "stdlib.h"

#include "../DIO/DIO_config.h"
#include "../DIO/DIO.h"

#include "../ADC/ADC_private.h"
#include "../ADC/ADC_config.h"
#include "../ADC/ADC.h"

#if ADC_SYNC_MODE == ASYNC_MODE

static void (*G_pf)(void) = NULL; // Global pointer to function to carry the address of ADC_ISR

static void ADC_SetCallBack(void (*pf)(void)) // Assign ADC_ISR function address to G_pf pointer
{
    G_pf = pf;
}


void MADC_vAsyncAdcInit(void)
{
    /* Select voltage reference AVCC REF. */
    SET_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);
    /* Select the adjust Right adjust */
    CLR_BIT(ADMUX, ADMUX_ADLAR);
    /* Enable ADC powers the ADC circuit */
    SET_BIT(ADCSRA, ADCSRA_ADEN);

    /* Set the pre-scaler --64 */
    CLR_BIT(ADCSRA, ADCSRA_ADPS0);
    SET_BIT(ADCSRA, ADCSRA_ADPS1);
    SET_BIT(ADCSRA, ADCSRA_ADPS2);
}

// ADC Asynchronous function
void MADC_vAsyncReadADC(ADC_channel_t cpy_enumChannelADC)
{
    /* Mask the bits for the channel before overwriting */
    ADMUX &= 0xE0; // or binary 0b11100000
    /* Select channel */
    ADMUX |= cpy_enumChannelADC;

    /* Enable ADC interrupt */
    SET_BIT(ADCSRA, ADCSRA_ADIE);

    /* Start conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void) // ADC vector handler
{
    if (NULL != G_pf)
    {
        G_pf(); // Call ADC_ISR function which is pointed at by G_pf pointer
    }
}

#elif ADC_SYNC_MODE == SYNC_MODE

void MADC_vAdcInit()
{
    /* Select voltage reference AVCC REF. */
    SET_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);
    /* Select the adjust Right adjust */
    CLR_BIT(ADMUX, ADMUX_ADLAR);
    /* Enable ADC powers the circuit itself */
    SET_BIT(ADCSRA, ADCSRA_ADEN);
    /* Set the pre-scaler --64 */
    CLR_BIT(ADCSRA, ADCSRA_ADPS0);
    SET_BIT(ADCSRA, ADCSRA_ADPS1);
    SET_BIT(ADCSRA, ADCSRA_ADPS2);
}

// ADC Synchronous function
uint16 MADC_uint16ReadADC(ADC_channel_t cpy_enumChannelADC)
{
    /* Mask the bits for the channel before overwriting */
    ADMUX &= 0xE0; // or binary 0b11100000
    /* Select channel */
    ADMUX |= cpy_enumChannelADC;
    /* Start conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);
    /* Busy wait for ADC flag */
    while ((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0)
	{
		//wait
	}
    /* Clear flag */
    //SET_BIT(ADCSRA,ADCSRA_ADIF); // Not required in free running mode
    return ADC_DATA_REG;
}

#endif
