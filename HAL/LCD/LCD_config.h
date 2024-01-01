
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*============================== LCD Port and Pins configurations ==============================*/
#define Data_PORT		DIO_PORTD
#define CTR_PORT		DIO_PORTC
#define LCD_RS			PIN0
#define LCD_RW			PIN1
#define LCD_EN			PIN2

/*======================================== LCD Commands ========================================*/
#define LCD_FUNCTION_SET		0x38
/* LCD_DISPLAY >> 0x0F to enable cursor.. 0x0C to disable cursor */
#define LCD_DISPLAY				0x0C
#define LCD_CLEAR_SCREEN		0x01
#define SET_ENTRY_MODE			0x07




#endif /* LCD_CONFIG_H */
