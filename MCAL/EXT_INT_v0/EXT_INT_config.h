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
#define EXTI0_SENSE			FALLING_EDGE
#define EXTI1_SENSE			RISING_EDGE
#define EXTI2_SENSE			RISING_EDGE				//RISING_EDGE OR FALLING_EDGE ONLY

#endif /* MCAL_EXT_INT_V0_EXT_INT_CONFIG_H_ */
