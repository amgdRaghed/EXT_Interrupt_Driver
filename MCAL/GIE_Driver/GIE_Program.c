/*
 * GIE_Program.c
 *
 *  Created on: Nov 20, 2021
 *      Author: amgdRaghed
 */

#include "std_Types.h"
#include "GIE_Private.h"


void GIE_voidEnable(void)
{
	// Set I Bit in SREG
	SREG |= (GIE_BIT_ONE<<GIE_I_Bit);
}

void GIE_voidDisable(void)
{
	// Clear I Bit in SREG
	SREG &= ~(GIE_BIT_ONE<<GIE_I_Bit);
}
