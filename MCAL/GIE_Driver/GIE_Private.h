/*
 * GIE_Private.h
 *
 *  Created on: Nov 20, 2021
 *      Author: amgdRaghed
 */

#ifndef GIE_DRIVER_GIE_PRIVATE_H_
#define GIE_DRIVER_GIE_PRIVATE_H_

/* Definitions of Magic Number */
#define GIE_BIT_ONE			1

/* Definitions of Status Register */
#define SREG		( *((volatile u8*) 0x5F) )

/* Definitions of Bit7 I : Global Interrupt Enable bit */
#define GIE_I_Bit	7

#endif /* GIE_DRIVER_GIE_PRIVATE_H_ */
