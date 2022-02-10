/*
 * ADC_Private.h
 *
 *  Created on: Nov 22, 2021
 *      Author: amgdRaghed
 */

#ifndef MCAL_ADC_PRIVATE_H_
#define MCAL_ADC_PRIVATE_H_

#define ADMUX      *((volatile u8*)0x27)
#define ADCSRA     *((volatile u8*)0x26)
#define ADC        *((volatile u16*)0x24)
#define SFIOR      *((volatile u16*)0x50)

#define  ADC_AVCC_REFERENCEVOLATGE      	1
#define  ADC_INTERNAL_REFERENCEVOLATGE		2

#define ADC_BIT_MASKING_PRESCALER     0xF8
#define ADC_BIT_MASKING_CHANNEL       0x07
#define ADC_BIT_MASKING_REG_CHANNEL   0xE0

#define ADC_2_PRESCALER     1
#define ADC_4_PRESCALER     2
#define ADC_8_PRESCALER     3
#define ADC_16_PRESCALER    4
#define ADC_32_PRESCALER    5
#define ADC_64_PRESCALER    6
#define ADC_128_PRESCALER   7

#define ADC_RIGHT_ADJUST    0
#define ADC_LEFT_ADJUST     1

void __vector_16(void)    __attribute__((signal));

#endif /* MCAL_ADC_PRIVATE_H_ */
