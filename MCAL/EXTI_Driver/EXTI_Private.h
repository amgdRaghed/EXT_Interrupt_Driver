/*
 * EXTI_Private.h
 *
 *  Created on: Nov 16, 2021
 *      Author: amgdRaghed
 */

#ifndef EXTI_DRIVER_EXTI_PRIVATE_H_
#define EXTI_DRIVER_EXTI_PRIVATE_H_

/* Definitions of External Interrupts Registers */
#define EXTI_MCUCR_REG		( *( (volatile u8*) 0x55) )		// MCU Control Register contains control bits for interrupt sense control "ISC11 : ISC00" for INT0,INT1
#define EXTI_MCUCSR_REG		( *( (volatile u8*) 0x54) )		// MCU Control and Status Register contains control bits for interrupt sense control "ISC2" for INT2
#define EXTI_GICR_REG		( *( (volatile u8*) 0x5B) )		// General Interrupt Control Register contains control bits for External Interrupt Request Enable
#define EXTI_GIFR_REG		( *( (volatile u8*) 0x5A) )		// General Interrupt Flag Register contains flag bits for External Interrupt Flag


/*        Definitions of MCUCR: MCU Control Register Bits         */
// Bit 0,1 – ISC01,ISC00: Interrupt Sense Control 0 Bit0 and Bit1
#define EXTI_ISC00_BIT		0
#define EXTI_ISC01_BIT		1
// Bit 2,3 – ISC11,ISC10: Interrupt Sense Control 1 Bit2 and Bit3
#define EXTI_ISC10_BIT		2
#define EXTI_ISC11_BIT		3


/*    Definitions of MCUCSR: MCU Control and Status Register Bits    */
//           Bit 6 – ISC2: Interrupt Sense Control 2
#define EXTI_ISC2_BIT		6


/*    Definitions of GICR: General Interrupt Control Register Bits   */
//  	Bit 7 – INT1: External Interrupt Request 1 Enable
#define EXTI_INT1_BIT		7
//    	Bit 6 – INT0: External Interrupt Request 0 Enable
#define EXTI_INT0_BIT		6
//     	Bit 5 – INT2: External Interrupt Request 2 Enable
#define EXTI_INT2_BIT		5


/*    Definitions of GIFR: General Interrupt Flag Register Bits   */
//  	Bit 7 – INTF1: External Interrupt Flag 1
#define EXTI_INTF1_BIT		7
//    	Bit 6 – INTF0: External Interrupt Flag 0
#define EXTI_INTF0_BIT		6
//     	Bit 5 – INTF2: External Interrupt Flag 2
#define EXTI_INTF2_BIT		5


/*   Definitions of External Interrupt Modes   */
#define LOW_LEVEL			0b00
#define ANY_CHANGE			0b01
#define FALLING_EDGE		0b10
#define RISING_EDGE			0b11


/*   Definitions of External Interrupt IDs   */
#define EXTI_INT0			6
#define EXTI_INT1			7
#define EXTI_INT2			5


/* Definitions of Magic Number */
#define EXTI_BIT_ONE		1
#define BIT_0				0
#define BIT_1				1

#endif /* EXTI_DRIVER_EXTI_PRIVATE_H_ */
