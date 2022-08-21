/*
 * STD_Types.h
 *
 *  Created on: Aug 20, 2022
 *      Author: Kiro Yousri
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define STD_HIGH    (1U)
#define STD_LOW     (0U)

#define STD_ON      (1U)
#define STD_OFF     (0U)

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))


/* This is used to define the void pointer to zero definition */
#define NULL_PTR          ((void *)0)

/* This is used to define the abstraction of compiler keyword inline */
#define INLINE            inline

/* This is used to define the local inline function */
#define LOCAL_INLINE      static inline

/* This is used to define the abstraction of compiler keyword static */
#define STATIC            static


typedef unsigned char         boolean;

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;


#endif /* STD_TYPES_H_ */
