/*
 * TIMER0_private.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_


#define TCCR0 						*((volatile uint8*)0x53)
#define TCCR0_CS00					0						//PreScaler pin0
#define TCCR0_CS01					1						//PreScaler pin1
#define TCCR0_CS02					2						//PreScaler pin2
#define TCCR0_WGM01					3						//Timer0 mode pin1
#define TCCR0_WGM00					6						//Timer0 mode pin0
#define TCCR0_COM00					4						//OC0 mode pin0
#define TCCR0_COM01					5						//OC0 mode pin1
#define TCCR0_FOC0					7						//Force Output Compare on OC0 pin
#define TCCR0_CSmax					7						//to mask the CS0 pins 0,1,2

//Registers
#define TCNT0						*((volatile uint8*)0x52)
#define OCR0						*((volatile uint8*)0x5C)

//Enables
#define TIMSK						*((volatile uint8*)0x59)
#define TIMSK_TOIE0					0
#define TIMSK_OCIE0					1

//Flags
#define TIFR						*((volatile uint8*)0x58)
#define TIFR_TOV0					0
#define TIFR_OCF0					1

//Timer Modes
#define NORMAL_MODE					0
#define PHASE_CORRECT_MODE			1
#define CTC_MODE					2
#define FAST_PWM					3


//PreScaler CS0 Pins Values
#define T0_PRESCALER_cs_1			1
#define T0_PRESCALER_cs_8			2
#define T0_PRESCALER_cs_64			3
#define T0_PRESCALER_cs_256			4
#define T0_PRESCALER_cs_1024		5

//PreScaler Values
#define T0_PRESCALER_1              1
#define T0_PRESCALER_8              8
#define T0_PRESCALER_64             64
#define T0_PRESCALER_256            256
#define T0_PRESCALER_1024           1024

//
#define COUNTER_RESOLUTION		256
#define MS_US_CONVERT				1000
#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
