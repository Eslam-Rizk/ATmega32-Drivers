/*
 * KEYPAD_config.h
 *
 *  Created on: Dec 12, 2023
 *      Author: Eslam Rizk
 */

#ifndef HAL_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_CONFIG_H_

/*============================== KeyPad Port and Pins configurations ==============================*/

#define KEYPAD_PORT 		DIO_PORTB

#define ROW_PIN0			PIN0
#define ROW_PIN1			PIN1
#define ROW_PIN2			PIN2
#define ROW_PIN3			PIN3

#define COL_PIN0			PIN4
#define COL_PIN1			PIN5
#define COL_PIN2			PIN6
#define COL_PIN3			PIN7

#define ROW_SIZE			4
#define COL_SIZE			4

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
