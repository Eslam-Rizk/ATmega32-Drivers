/*
 * ADC_private.h
 *
 *  Created on: Dec 20, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/*===========================       ADC Multiplexer Selection Register        ===========================*/
#define ADMUX 			*((volatile uint8*)(0x27))

//select the voltage reference for the ADC
#define ADMUX_REFS0 		 6  							//no. of bit 6 inside the ADMUX register
#define ADMUX_REFS1 		 7								//no. of bit 7 inside the ADMUX register

//Left Adjust 0 or Right Adjust  1
#define ADMUX_ADLAR 		 5								//no. of bit 5 inside the ADMUX register

//Analog Channel and Gain Selection Bits
#define ADMUX_MUX0 			 0								//no. of bit 0 inside the ADMUX register
#define ADMUX_MUX1 			 1								//no. of bit 1 inside the ADMUX register
#define ADMUX_MUX2 			 2								//no. of bit 2 inside the ADMUX register
#define ADMUX_MUX3 			 3								//no. of bit 3 inside the ADMUX register
#define ADMUX_MUX4 			 4								//no. of bit 4 inside the ADMUX register


/*===========================         ADC Control and Status Register A        ===========================*/
#define ADCSRA 				*((volatile uint8*)(0x26))
//ADC Enable
#define ADCSRA_ADEN  		 7								//no. of bit 7 inside the ADCSRA register
//ADC Start Conversion
#define ADCSRA_ADSC  		 6								//no. of bit 6 inside the ADCSRA register
 //Auto Trigger
#define ADCSRA_ADATE		 5								//no. of bit 5 inside the ADCSRA register
//C Interrupt Flag PIF
#define ADCSRA_ADIF 		 4								//no. of bit 4 inside the ADCSRA register
// ADC Interrupt Enable PIE
#define ADCSRA_ADIE  	   	 3								//no. of bit 3 inside the ADCSRA register

//: ADC Prescaler bits
#define ADCSRA_ADPS0		 0								//no. of bit 0 inside the ADCSRA register
#define ADCSRA_ADPS1		 1								//no. of bit 1 inside the ADCSRA register
#define ADCSRA_ADPS2 		 2								//no. of bit 2 inside the ADCSRA register


/*=========================== ADLAR Data register on 0x24 & 0x25 thus the "uint16" ===========================*/
#define ADC_DATA_REG 	*((volatile uint16*)(0x24))


/*===========================     Special FunctionIO Register to select ADC mode   ===========================*/
#define SFIOR 			*((volatile uint8*)(0x50))

//ADC synchronization mode
#define SYNC_MODE		0
#define ASYNC_MODE		1

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
