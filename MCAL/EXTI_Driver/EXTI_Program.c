/*
 * EXTI_Progarm.c
 *
 *  Created on: Nov 16, 2021
 *      Author: amgdRaghed
 */

/* Include Lib Layer */
#include "std_Types.h"

/* Include MCAL Layer */
#include "EXTI_Private.h"

#include "avr/interrupt.h"

// Global Static Variable Pointer to Function
static void (*ptr_functionINT0)(void) = NULL;
static void (*ptr_functionINT1)(void) = NULL;
static void (*ptr_functionINT2)(void) = NULL;

void EXTI_voidEnable(u8 Copy_EXTI_ID, u8 Copy_EXTI_Mode)
{
	// Step1 : Enable PIE "Peripheral Interrupt Enable"
	EXTI_GICR_REG |= (EXTI_BIT_ONE << Copy_EXTI_ID);

	// Step2 : Configure External Interrupt Mode
	switch (Copy_EXTI_ID)
	{
	case EXTI_INT0:
		// Bit Mask
		EXTI_MCUCR_REG &= ~(EXTI_BIT_ONE << EXTI_ISC00_BIT);
		EXTI_MCUCR_REG &= ~(EXTI_BIT_ONE << EXTI_ISC01_BIT);
		// Set EXTI_Mode to bits
		EXTI_MCUCR_REG |= ( ((Copy_EXTI_Mode >> BIT_0) & EXTI_BIT_ONE) << EXTI_ISC00_BIT );
		EXTI_MCUCR_REG |= ( ((Copy_EXTI_Mode >> BIT_1) & EXTI_BIT_ONE) << EXTI_ISC01_BIT );
		break;


	case EXTI_INT1:
		// Bit Mask
		EXTI_MCUCR_REG &= ~(EXTI_BIT_ONE << EXTI_ISC10_BIT);
		EXTI_MCUCR_REG &= ~(EXTI_BIT_ONE << EXTI_ISC11_BIT);
		// Set EXTI_Mode to bits
		EXTI_MCUCR_REG |= ( ((Copy_EXTI_Mode >> BIT_0) & EXTI_BIT_ONE) << EXTI_ISC10_BIT );
		EXTI_MCUCR_REG |= ( ((Copy_EXTI_Mode >> BIT_1) & EXTI_BIT_ONE) << EXTI_ISC11_BIT );
		break;


	case EXTI_INT2:
		// Bit Mask
		EXTI_MCUCSR_REG &= ~(EXTI_BIT_ONE << EXTI_ISC2_BIT);
		// Set EXTI_Mode to bits
		EXTI_MCUCSR_REG |= ( ((Copy_EXTI_Mode >> BIT_0) & EXTI_BIT_ONE) << EXTI_ISC2_BIT );
		break;
	}

}


void EXTI_voidDisable(u8 Copy_EXTI_ID)
{
	// Step1 : Disable PIE "Peripheral Interrupt Enable"
	EXTI_GICR_REG &= ~(EXTI_BIT_ONE << Copy_EXTI_ID);
}


void EXTI_voidSetCallBackINT0( void (*Copy_ptrFunctionINT0)(void) )
{
	ptr_functionINT0 = Copy_ptrFunctionINT0;
}


void EXTI_voidSetCallBackINT1( void (*Copy_ptrFunctionINT1)(void) )
{
	ptr_functionINT1 = Copy_ptrFunctionINT1;
}


void EXTI_voidSetCallBackINT2( void (*Copy_ptrFunctionINT2)(void) )
{
	ptr_functionINT2 = Copy_ptrFunctionINT2;
}


ISR(INT0_vect)
{
	ptr_functionINT0();
}

ISR(INT1_vect)
{
	ptr_functionINT1();
}

ISR(INT2_vect)
{
	ptr_functionINT2();
}
