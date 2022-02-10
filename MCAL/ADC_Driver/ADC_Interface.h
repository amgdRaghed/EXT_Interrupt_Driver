/*
 * ADC_Interface.h
 *
 *  Created on: Nov 22, 2021
 *      Author: amgdRaghed
 */

#ifndef MCAL_ADC_INTERFACE_H_
#define MCAL_ADC_INTERFACE_H_

#define CHANNEL_0     0
#define CHANNEL_1     1
#define CHANNEL_2     2
#define CHANNEL_3     3
#define CHANNEL_4     4
#define CHANNEL_5     5
#define CHANNEL_6     6
#define CHANNEL_7     7

/* ADC Initialization */
void MADC_VidInit(void);
void MADC_VidADCInterruptEnable(void);

/* ADC Start Conversion-->Polling , Return ADC Value */
u16 MADC_u16ADC_StartConversion(u8 Copy_u8Channel);

/* ADC Start Conversion using Interrupt, ADC Value Return with ISR */
void MADC_u16ADC_StartConversion_With_Interrupt(u8 Copy_u8Channel);
u16 MADC_u16ADCRead(void);
void MADC_VidSetCallBack(void (*Copy_pFun)(void));




#endif /* MCAL_ADC_INTERFACE_H_ */
