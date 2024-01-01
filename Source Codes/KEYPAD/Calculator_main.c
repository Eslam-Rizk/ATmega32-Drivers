/*
 * main.c
 *
 *  Created on: Dec 10, 2023
 *      Author: Eslam Rizk
 */

#include <util/delay.h>
#include "../LIB/STD_TYPES.h"

#include "../HAL/LCD/H_LCD.h"
#include "../HAL/KEYPAD/H_KEYPAD.h"
#include "Calculator_private.h"


int main()
{
	uint16 op1=0,op2=0,flag=0,result;		                 //declare variables : operand1, operand2, flag to check for operation and operands, result of operation
	uint8 Data;								                 //variable to get data from KeyPad
	HLCD_vInit();							                 //initialize LCD
	HKeypad_vInit();						                 //initialize KeyPAd


	while(1)								                 //infinite loop
	{
		Data=HKeypad_uint8GetKey();			                 //read data from KeyPad
		if(Data!=Not_Pressed)								 //check if key is pressed
		{	/* check whether data is digit or operator */
			if('#' == Data)					                 //clear Calculator screen
			{
				flag=0;						                 //ready to read operand1
				op1=0;						                 //clear operand1
				op2=0;						                 //clear operand2
				HLCD_vClearScreen();		                 //clear LCD
			}
			else							                 //read operand or operation
			{
				if('+' == Data)				                 //summation
				{
					flag=1;					                 //summation flag and ready to read operand2
					HLCD_vWriteChar(Data);	                 //print operation symbol
				}
				else if('-' == Data)		                 //subtraction
				{
					flag=2;					                 //subtraction flag and ready to read operand2
					HLCD_vWriteChar(Data);	                 //print operation symbol
				}
				else if('*' == Data)                         //multiplication
				{
					flag=3;                                  //multiplication flag and ready to read operand2
					HLCD_vWriteChar(Data);                   //print operation symbol
				}
				else if('/' == Data)                         //division
				{
					flag=4;                                  //division flag and ready to read operand2
					HLCD_vWriteChar(Data);                   //print operation symbol
				}
				else if('=' == Data)		                 //end of input, get result of operation
				{
					switch(flag)			                 //check which operation to perform
					{
					case ADD:								 //addition
						result=op1+op2;						 //add operand1 ,operand2
						HLCD_vWriteChar(Data);				 //print operation symbol
						HLCD_vWriteNumber(result);			 //print result
						break;
					case SUBTRACT:
						if(op2 > op1)						 //check if there is gonna be a -ve result >> op2>op1
						{
							HLCD_vWriteChar(Data);			 //print subtraction symbol
							HLCD_vWriteChar('-');			 //print -ve sign
							result=op2-op1;					 //subtract operand1 from operand2
						}
						else
						{
							result=op1-op2;					 //normal subtraction because the is no -ve sign >> op1>op2
							HLCD_vWriteChar(Data);			 //print subtraction symbol

						}
						HLCD_vWriteNumber(result);			 //print result

						break;
					case MULTIPLY:                           //multiplication
						result=op1*op2;                      //multiply operand1 ,operand2
						HLCD_vWriteChar(Data);               //print operation symbol
						HLCD_vWriteNumber(result);           //print result
						break;
					case DIVIDE:							 //division
						if(0 == op2)						 //check if denominator equals zero
						{
							/* infinity */
							HLCD_vWriteChar(Data);
							HLCD_vWriteString("Infinity");	 //print infinity
						}
						else
						{
							result=op1/op2;					 //normal division
							HLCD_vWriteChar(Data);
							HLCD_vWriteNumber(result);		 //print result
							if((result*op2) != op1)			 //if there is a remainder from the division
							{
								HLCD_vWriteChar(' ');		 //print space
								HLCD_vWriteNumber(op1%op2);	 //print remainder
								HLCD_vWriteChar('/');		 //print division symbol /
								HLCD_vWriteNumber(op2);		 //print operand2
							}
						}
						break;
					default:
						break;
					}
					flag=0;									 //ready for operand1 of the next operation
				}
				else										 //store digits in operand1 and operand2
				{
					if(0 == flag) //op1						 //flag = 0 means store in operand1
					{
						if( 0 == op1)						 //if op1 = 0
						{
							op1=Data-'0';					 //assign data to op1 after converting from ASCII to decimal
						}
						else								 //if op1 != 0 which means it's more than 1 digit
						{
							op1=(op1*10)+Data-'0';			 //5 >> (5*10)+2 >> 52
						}
					}
					else	//op2
					{
						if( 0 == op2)                	     //if op1 = 0
						{
							op2=Data-'0';              		 //assign data to op1 after converting from ASCII to decimal
						}
						else                           		 //if op1 != 0 which means it's more than 1 digit
						{
							op2=(op2*10)+Data-'0';     		 //5 >> (5*10)+2 >> 52
						}
					}
					HLCD_vWriteChar(Data);             		 //print digits from KeyPad

				}
			}
		}
	}
	return 0;
}

