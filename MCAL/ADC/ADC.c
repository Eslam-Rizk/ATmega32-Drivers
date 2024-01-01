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

void (*G_pf) (void)=NULL;						//global pointer to function to carry address of ADC_ISR

void ADC_SetCallBack(void (*pf) (void))			//assign ADC_ISR function address to G_pf pointer
{
	G_pf=pf;
}

void MADC_vAsyncAdcInit(void)
{
	/*select volt ref. AVCC REF.*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*select the adjust Right adjust*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	/*enable ADC powers the ADC circuit */
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	/*set the pre-scaller --64*/
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);

}

//adc ASynchronans function
void MADC_vAsyncReadADC(ADC_channel_t cpy_enumChannelADC)
{

	/*mask the bits for channel before overwrite*/
	ADMUX &=0xE0; //or binary 0b11100000
	/*select channel */
	ADMUX |=cpy_enumChannelADC;

	/*enable adc interrupt */
	SET_BIT( ADCSRA , ADCSRA_ADIE);

	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

}

void __vector_16 (void)	__attribute__((signal));
void __vector_16 (void)									//ADC vector handler
{
	if(NULL != G_pf)
	{
		G_pf();											//call ADC_ISR function which is pointed at by G_pf pointer
	}

}


#elif ADC_SYNC_MODE == SYNC_MODE

void MADC_vAdcInit(){
	/*select volt ref. AVCC REF.*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*select the adjust Right adjust*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	/*enable ADC powers the circuit itself */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	/*enable adc interrupt */

	/*set the pre-scaller --64*/
	CLR_BIT(ADCSRA,ADCSRA_ADPS0);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
}

//adc Synchronans function
uint16 MADC_uint16ReadADC(ADC_channel_t cpy_enumChannelADC){

	/*mask the bits for channel before overwrite*/
	ADMUX &=0xE0; //or binary 0b11100000
	/*select channel */
	ADMUX |=cpy_enumChannelADC;
	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*busy wait for ADC flag*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);
	/*clr flag*/
	//SET_BIT(ADCSRA,ADCSRA_ADIF);				//not required in free running mode
	return ADC_DATA_REG;
}

#endif


