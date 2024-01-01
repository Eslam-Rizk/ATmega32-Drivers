/*
 * TIMER0_config.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_TIMER0_TIMER0_CONFIG_H_
#define MCAL_TIMER0_TIMER0_CONFIG_H_

/*PRESCALER OPTIONS:
 * 					1
 * 					8
 * 					64
 * 					256
 * 					1024
 * */
#define FREQUENCY_MHZ			8
#define PRESCALER_VALUE			1024

/*TIMER0 MODE OPTIONS:
 * 					NORMAL_MODE
 * 					PHASE_CORRECT_MODE
 * 					CTC_MODE
 * 					FAST_PWM
 * 					*/
#define TIMER0_MODE				CTC_MODE


#endif /* MCAL_TIMER0_TIMER0_CONFIG_H_ */
