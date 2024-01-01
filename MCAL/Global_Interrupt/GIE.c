/*
 * GIE.c
 *
 *  Created on: Dec 19, 2023
 *      Author: Eslam Rizk
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE.h"
#include "GIE_private.h"


void GIE_vEnable(void)
{
	SET_BIT(SREG , SREG_GIE);
}

void GIE_vDisable(void)
{
	CLR_BIT(SREG , SREG_GIE);
}
