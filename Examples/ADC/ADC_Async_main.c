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
#include "../MCAL/ADC/ADC_private.h"
#include "../MCAL/Global_Interrupt/GIE.h"


uint16 Async_adc_read=0;
uint8 flag=0;

void printTemp(void);
void ADC_ISR(void);

uint8 MAP_uint8Mappiny(uint32 out_max,uint32 out_min,uint32 in_max,uint32 in_min,uint32 input);
int main()
{
	HLCD_vInit();
	ADC_SetCallBack(ADC_ISR);			//set call back
	MDIO_vSetPortDir(DIO_PORTD,0xff);
	MADC_vAsyncAdcInit();
	GIE_vEnable(); 						//global interrupt

	while (1)
	{
		if(0 == flag)
		{
			MADC_vAsyncReadADC(ADC_CH1);
			flag=1;
		}
		if(2 == flag)
		{
			printTemp();
			flag=0;
		}

	}
}


uint8 MAP_uint8Mappiny(uint32 out_max,uint32 out_min,uint32 in_max,uint32 in_min,uint32 input){

	uint8 local_uint8OutValue=0;

	local_uint8OutValue= ( ((out_max-out_min)*(input-in_min)) /  (in_max-in_min) ) + out_min;

	return local_uint8OutValue;
}


void printTemp()
{
	uint32 mapped_value=0;
	uint16 voltage = 0;
	mapped_value=MAP_uint8Mappiny(255,0,1023,0,Async_adc_read);
	MDIO_vSetPortVal(DIO_PORTD,mapped_value);
	voltage = (mapped_value * 5000) /255 ;			//2^n = 256 to round to lower value
	HLCD_vWriteNumber(voltage);
	HLCD_vWriteString("mv");
	_delay_ms(1);
	HLCD_vClearScreen();
}



void ADC_ISR(void)
{
		/*read data*/
		Async_adc_read = ADC_DATA_REG;
		flag=2;
}

