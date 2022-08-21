/*
 * Dio.h
 *
 *  Created on: Aug 20, 2022
 *      Author: Kiro Yousri
 */

#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"

/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000




#define GPIO_PORTA_DATA_REG       (*((volatile uint32 *)0x400043FC))
#define GPIO_PORTB_DATA_REG       (*((volatile uint32 *)0x400053FC))
#define GPIO_PORTC_DATA_REG       (*((volatile uint32 *)0x400063FC))
#define GPIO_PORTD_DATA_REG       (*((volatile uint32 *)0x400073FC))
#define GPIO_PORTE_DATA_REG       (*((volatile uint32 *)0x400243FC))
#define GPIO_PORTF_DATA_REG       (*((volatile uint32 *)0x400253FC))

/*********************************port numbers********************************************/
#define TOTAL_PINS      43
#define PORTS_OF_TIVA_C   6
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3
#define PORTE    4
#define PORTF    5
/*****************************************************************************************/
typedef enum{PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,
             PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,
             PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,
             PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7,
             PE0,PE1,PE2,PE3,PE4,PE5,
             PF0,PF1,PF2,PF3,PF4}PINS;


/*******************************************
 * API TYPES
 ******************************************/
typedef unsigned int Dio_ChannelType;
typedef unsigned int Dio_PortType;
typedef unsigned char Dio_LevelType;
typedef unsigned char Dio_PortLevelType;


/*******************************************
 * API FUNCTIONS
 ******************************************/

Dio_LevelType Dio_ReadChannel(
Dio_ChannelType ChannelId
);

void Dio_WriteChannel(
Dio_ChannelType ChannelId,
Dio_LevelType Level
);

Dio_PortLevelType Dio_ReadPort(
Dio_PortType PortId
);

void Dio_WritePort(
Dio_PortType PortId,
Dio_PortLevelType Level
);

Dio_LevelType Dio_FlipChannel(
Dio_ChannelType ChannelId
);



#endif /* DIO_H_ */
