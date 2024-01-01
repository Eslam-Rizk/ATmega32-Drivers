/*
 * H_LCD_int.h
 *
 *  Created on: Dec 11, 2023
 *      Author: Eslam Rizk
 */

#ifndef HAL_LCD_H
#define HAL_LCD_H

/*=================================Functions Prototypes=================================*/
void HLCD_vInit( void );
void HLCD_vWriteChar( uint8 cpy_uint8Data );
void HLCD_vWriteString(const uint8 *ptr_uint8String );
void HLCD_vClearScreen(void);
void HLCD_vGotoXY( uint8 cpy_uint8PosX , uint8 cpy_uint8PosY);
void HLCD_vWriteNumber( uint16 cpy_uint16Number);


#endif /* HAL_LCD_H_ */
