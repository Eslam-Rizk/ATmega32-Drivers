/*
 * WATCHDOG_private.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_WATCHDOGTIMER_WATCHDOG_PRIVATE_H_
#define MCAL_WATCHDOGTIMER_WATCHDOG_PRIVATE_H_


#define MCUCSR			*((volatile uint8*)0x54)
#define MCUCSR_WDRF		3

#define WDTCR			*((volatile uint8*)0x41)
#define WDTCR_WDTOE		4
#define WDTCR_WDE		3
#define WDTCR_WDP2		2
#define WDTCR_WDP1		1
#define WDTCR_WDP0		0

#define WDPTime_16_3ms   0
#define WDPTime_32_5ms   1
#define WDPTime2_65ms    2
#define WDPTime3_130ms   3
#define WDPTime4_260ms   4
#define WDPTime5_520ms   5
#define WDPTime6_1000ms  6
#define WDPTime7_2100ms  7




#endif /* MCAL_WATCHDOGTIMER_WATCHDOG_PRIVATE_H_ */
