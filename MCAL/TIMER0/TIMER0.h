/*
 * TIMER0.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_

#if NORMAL_MODE == TIMER0_MODE
void T0OV_vSetCallBack(void (*pf)(void));
#elif CTC_MODE == TIMER0_MODE
void T0OC_vSetCallBack(void (*pf)(void));
#endif
void MTIMER0_vInit(void);
void MTIMER0_vSetDelay_ms(uint64 cpy_uint32Time);
void MTIMER0_vStart(void);
void MTIMER0_vStop(void);

#endif /* MCAL_TIMER0_TIMER0_H_ */
