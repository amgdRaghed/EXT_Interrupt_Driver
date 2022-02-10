/*
 * ADC_Program.c
 *
 *  Created on: Nov 22, 2021
 *      Author: amgdRaghed
 */

/* Include Lib Layer */
#include "std_Types.h"
#include "Bit_Math.h"

/* Include MCAL Layer */
#include"ADC_Private.h"
#include"ADC_Config.h"

void (*ADC_CallBack)(void);

/* ADC Initialization */
void ADC_VidInit(void)
{
	// Select Reference Voltage
#if ADC_SET_REFERENCEVOLATGE == ADC_AVCC_REFERENCEVOLATGE
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
#elif ADC_SET_REFERENCEVOLATGE == ADC_2.56V_REFERENCEVOLATGE
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#else
#error"ADC Reference Voltage Option I s not valid...."
#endif

	// Set Prescaler
	ADCSRA &= ADC_BIT_MASKING_PRESCALER;
	ADCSRA |= ADC_SET_PRESCALER;

	// Select Left adjust option
#if ADC_SET_ADJUST == ADC_LEFT_ADJUST
	SET_BIT(ADMUX,5);
#elif ADC_SET_ADJUST == ADC_RIGHT_ADJUST
	CLR_BIT(ADMUX,5);
#else
#error"ADC Left adjust option is not valid...."
#endif

	// Enable ADC
	SET_BIT(ADCSRA,7);
}

/* ADC Interrupt Enable */
void ADC_VidADCInterruptEnable(void)
{
	SET_BIT(ADCSRA,3);
}

/* ADC Start Conversion using Polling, Return ADC Value */
u16 ADC_u16ADC_StartConversion(u8 Copy_u8Channel)
{
	// Select Channel
	Copy_u8Channel &= ADC_BIT_MASKING_CHANNEL;
	ADMUX &= ADC_BIT_MASKING_REG_CHANNEL;
	ADMUX |= Copy_u8Channel;
	
	// Send Start Conversion
	SET_BIT(ADCSRA,6);
	
	// Wait On ADC Conversion Completed Flag is set to one
	while( !( GET_BIT(ADCSRA,4) ) );		//GET_BIT(ADCSRA,4)==0

	return ADC;
}

/* ADC Start Conversion using Interrupt, ADC Value Return with ISR */
void ADC_u16ADC_StartConversion_With_Interrupt(u8 Copy_u8Channel)
{
	// Select Channel
	Copy_u8Channel &= ADC_BIT_MASKING_CHANNEL;
	ADMUX &= ADC_BIT_MASKING_REG_CHANNEL;
	ADMUX |= Copy_u8Channel;
	
	//send Start Conversion
	SET_BIT(ADCSRA,6);
}

u16 ADC_u16ADCRead(void)
{
	return ADC;
}

void ADC_VidSetCallBack(void (*Copy_pFun)(void))
{
	ADC_CallBack=Copy_pFun;
}

void __vector_16(void)
{
	ADC_CallBack();
}
