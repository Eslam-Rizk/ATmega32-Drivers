/*
 * STEPPER_config.h
 *
 *  Created on: Dec 14, 2023
 *      Author: Eslam Rizk
 */

#ifndef HAL_STEPPER_STEPPER_CONFIG_H_
#define HAL_STEPPER_STEPPER_CONFIG_H_

/*============================== Stepper Port and Pins configurations ==============================*/

#define STEPPER_PORT			DIO_PORTA
#define PINK_PIN				PIN2
#define ORANGE_PIN				PIN3
#define YELLOW_PIN				PIN4
#define BLUE_PIN				PIN5

/*========================================= Stepper Angles =========================================*/
#define STRIDE_ANGLE 	0.08789
#define FULL_STEP		0.17578
#define CYCLE_ANGEL		0.70312

/* SPEED from low to high 1,2,3,4,5*/
#define SPEED			5


#endif /* HAL_STEPPER_STEPPER_CONFIG_H_ */
