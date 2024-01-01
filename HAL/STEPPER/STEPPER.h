/*
 * STEPPER.H
 *
 *  Created on: Dec 14, 2023
 *      Author: Eslam Rizk
 */

#ifndef HAL_STEPPER_STEPPER_H_
#define HAL_STEPPER_STEPPER_H_

/*=================================Functions Prototypes=================================*/
void HSTEPPER_vInit(void);
void HSTEPPER_vStop(void);
void HSTEPPER_vSetStepperFAngle(uint8 cpy_uint8Angle);
void HSTEPPER_vSetStepperRAngle(uint8 cpy_uint8Angle);

#endif /* HAL_STEPPER_STEPPER_H_ */
