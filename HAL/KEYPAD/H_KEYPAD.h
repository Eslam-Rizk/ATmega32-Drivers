/*
 * H_KEYPAD.h
 *
 *  Created on: Dec 12, 2023
 *      Author: Eslam Rizk
 */

#ifndef HAL_H_KEYPAD_H_
#define HAL_H_KEYPAD_H_


#define Not_Pressed		0xFF

/*=================================Functions Prototypes=================================*/
void HKeypad_vInit(void);
uint8 HKeypad_uint8GetKey(void);

#endif /* HAL_H_KEYPAD_H_ */
