/*
 * EXT_INT_config.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_EXT_INT_V0_EXT_INT_CONFIG_H_
#define MCAL_EXT_INT_V0_EXT_INT_CONFIG_H_

/*Sense options
 * 				1-LOW_LEVEL
 * 				2-ANY_CHANGE
 * 				3-RISING_EDGE
 * 				4-FALLING_EDGE
 * */
#define EXTI0_SENSE		FALLING_EDGE	// Sensing type for external interrupt 0
#define EXTI1_SENSE		RISING_EDGE		// Sensing type for external interrupt 1
#define EXTI2_SENSE		RISING_EDGE		// Sensing type for external interrupt 2 (RISING_EDGE or FALLING_EDGE only)

#endif /* MCAL_EXT_INT_V0_EXT_INT_CONFIG_H_ */
