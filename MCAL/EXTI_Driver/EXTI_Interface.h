/*
 * EXTI_Interface.h
 *
 *  Created on: Nov 16, 2021
 *      Author: amgdRaghed
 */

#ifndef EXTI_DRIVER_EXTI_INTERFACE_H_
#define EXTI_DRIVER_EXTI_INTERFACE_H_

/* External Interrupt APIs Prototype */
void EXTI_voidEnable(u8 Copy_EXTI_ID, u8 Copy_EXTI_Mode);
void EXTI_voidDisable(u8 Copy_EXTI_ID);
void EXTI_voidSetCallBackINT0( void (*Copy_ptrFunctionINT0)(void) );
void EXTI_voidSetCallBackINT1( void (*Copy_ptrFunctionINT1)(void) );
void EXTI_voidSetCallBackINT2( void (*Copy_ptrFunctionINT2)(void) );

/*   Definitions of External Interrupt Modes   */
#define LOW_LEVEL			0b00
#define ANY_CHANGE			0b01
#define FALLING_EDGE		0b10
#define RISING_EDGE			0b11


/*   Definitions of External Interrupt IDs   */
#define EXTI_INT0			6
#define EXTI_INT1			7
#define EXTI_INT2			5

#endif /* EXTI_DRIVER_EXTI_INTERFACE_H_ */
