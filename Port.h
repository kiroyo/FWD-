/*
 * Port.h
 *
 *  Created on: Aug 20, 2022
 *      Author: Kiro Yousri
 */

#ifndef PORT_H_
#define PORT_H_
#include "Std_Types.h"



/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C




/*******************************************
 * API TYPES
 ******************************************/

typedef uint8 Port_PinType

typedef enum {
    INPUT ,
    OUTPUT
}Port_PinDirectionType;

typedef enum {
            PORT_PIN_MODE_UART,
            PORT_PIN_MODE_CAN,
            PORT_PIN_MODE_SPI,
            PORT_PIN_MODE_I2C,
            PORT_PIN_MODE_PWM,
            PORT_PIN_MODE_ADC,
            PORT_PIN_MODE_ACOMPARTOR,
            PORT_PIN_MODE_DIO_GPT,
            PORT_PIN_MODE_QEI,
            PORT_PIN_MODE_USB,
            PORT_PIN_MODE_DIO,
}Port_PinModeType;


typedef enum {
    PULL_UP,
    PULL_DOWN
}Port_PininternalAttachType;


typedef enum {

}Port_PinOutputCurrentType;

typedef enum{
    low ,
    high
}Port_Pinlevel;

typedef struct {
    Port_PinType pin;
    Port_PinDirectionType direction;
    Port_PinModeType mode;
    Port_PininternalAttachType resistor;
    Port_Pinlevel level;
}Port_ConfigType;

/*******************************************
 * API FUNCTIONS
 ******************************************/

void Port_Init(const  Port_ConfigType* );




#endif /* PORT_H_ */
