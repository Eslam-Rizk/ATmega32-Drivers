/*
 * ADC.h
 *
 *  Created on: Dec 20, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

typedef enum CH_ADC
{
	ADC_CH0=0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7
}ADC_channel_t;

#if ADC_SYNC_MODE == SYNC_MODE
/* Function prototypes for synchronous ADC mode */
void MADC_vAdcInit(void);
uint16 MADC_uint16ReadADC(ADC_channel_t cpy_enumChannelADC);

#elif ADC_SYNC_MODE == ASYNC_MODE
/* Function prototypes for asynchronous ADC mode */
void MADC_vAsyncAdcInit(void);
void MADC_vAsyncReadADC(ADC_channel_t cpy_enumChannelADC);
void ADC_SetCallBack(void (*pf)(void));

#endif

#endif /* MCAL_ADC_ADC_H_ */
