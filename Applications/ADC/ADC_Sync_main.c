/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "util/delay.h"
#include "../MCAL/DIO/DIO_config.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/ADC/ADC.h"
#include "../HAL/LCD/H_LCD.h"



uint8 MAP_uint8Mappiny(uint32 out_max,uint32 out_min,uint32 in_max,uint32 in_min,uint32 input);
int main()
{
	HLCD_vInit();
	MDIO_vSetPortDir(DIO_PORTD,0xff);
	MADC_vAdcInit();
	uint16 adc_value=0;
	uint32 mapped_value=0;
	uint16 voltage = 0;
	while (1)
	{
		adc_value=MADC_uint16ReadADC(ADC_CH1);
		mapped_value=MAP_uint8Mappiny(255,0,1023,0,adc_value);
		MDIO_vSetPortVal(DIO_PORTD,mapped_value);
		voltage = (mapped_value * 5000) /256 ;			//2^n = 256 to round to lower value
		HLCD_vWriteNumber(voltage);
		HLCD_vWriteString("mv");
		_delay_ms(5);
		HLCD_vClearScreen();
	}
}


//app to map the 1024 from ADC to 255
//in from 0 to 1024
//out from 0 to 255
uint8 MAP_uint8Mappiny(uint32 out_max,uint32 out_min,uint32 in_max,uint32 in_min,uint32 input){

	uint8 local_uint8OutValue=0;

	local_uint8OutValue= ( ((out_max-out_min)*(input-in_min)) /  (in_max-in_min) ) + out_min;


	return local_uint8OutValue;
}
