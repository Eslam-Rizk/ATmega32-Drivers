/*
 * WATCHDOG.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_WATCHDOGTIMER_WATCHDOG_H_
#define MCAL_WATCHDOGTIMER_WATCHDOG_H_

void MWATCHDOG_vEnable(void);
void MWATCHDOG_vDisable(void);
void MWATCHDOG_uint16SleepTime(uint8 cpy_uint8Prescaler);

#endif /* MCAL_WATCHDOGTIMER_WATCHDOG_H_ */
