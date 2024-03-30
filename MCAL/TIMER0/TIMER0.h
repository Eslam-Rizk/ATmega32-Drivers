/*
 * TIMER0.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_

// Include guard to prevent multiple inclusion of the header file
#if NORMAL_MODE == TIMER0_MODE
// Function prototype to set a callback function for Timer0 overflow interrupt
void T0OV_vSetCallBack(void (*pf)(void));
#elif CTC_MODE == TIMER0_MODE
// Function prototype to set a callback function for Timer0 CTC interrupt
void T0OC_vSetCallBack(void (*pf)(void));
#endif

// Function prototypes for Timer0 initialization, delay, start, and stop
void MTIMER0_vInit(void);
void MTIMER0_vSetDelay_ms(uint64 cpy_uint32Time);
void MTIMER0_vStart(void);
void MTIMER0_vStop(void);

#endif /* MCAL_TIMER0_TIMER0_H_ */
