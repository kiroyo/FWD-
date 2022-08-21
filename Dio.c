/*
 * Dio.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Kiro Yousri
 */
#include "Dio.h"
#include "tm4c123gh6pm_registers.h"

Dio_PortType array_of_base_address[PORTS_OF_TIVA_C]={
 GPIO_PORTA_BASE_ADDRESS,
 GPIO_PORTB_BASE_ADDRESS,
 GPIO_PORTC_BASE_ADDRESS,
 GPIO_PORTD_BASE_ADDRESS,
 GPIO_PORTE_BASE_ADDRESS,
 GPIO_PORTF_BASE_ADDRESS

};


/**********************  DIO_READ_CHANNEL   *************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
Dio_PortType *NEW_BASE_ADDRESS_PTR=NULL_PTR;
Dio_LevelType  Port_Level;

if(ChannelId>(TOTAL_PINS-1)){
// DET ERROR
}
 if(ChannelId > 37){
    ChannelId+=2;//something to handle the 8 pins
  }
NEW_BASE_ADDRESS_PTR=(Dio_PortType *)(array_of_base_address[ChannelId/8]+((0X0004)<<(ChannelId%8)));//get the address of the register control that pin
Port_Level=(*NEW_BASE_ADDRESS_PTR)>>(ChannelId%8);// get the value of the needed pin and store it in a variable then return it
  return Port_Level;
}
/************************ DIO_WRITE_CHANNEL   ************************************************************************/

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level){
Dio_PortType *NEW_BASE_ADDRESS_PTR=NULL_PTR;

if(ChannelId>(TOTAL_PINS-1)){
// DET ERROR
}


if(ChannelId > 37){
    ChannelId+=2;//something to handle the 8 pins
}

/*note the new base address ptr  points on address but it return
the whole data register not the needed pin but in the
whole register we can only modify the needed pin not the rest pins
and if we make change happens to that pin only not affect the rest */
NEW_BASE_ADDRESS_PTR=(Dio_PortType*)(array_of_base_address[ChannelId/8]+((0X0004)<<(ChannelId%8)));
// the pointer now points to register that control that pin
(*NEW_BASE_ADDRESS_PTR)=Level<<(ChannelId%8);// put the level to the position of specified pin

}

/****************************   DIO_READ_PORT     *********************************************************************************************/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){
    //volatile Dio_PortType* Port_Ptr=NULL_PTR;
    Dio_PortType ReadDataPort;
    switch(PortId){
    case PORTA:    ReadDataPort=GPIO_PORTA_DATA_REG;//Port_Ptr = &GPIO_PORTA_DATA_REG
    break;
    case PORTB:    ReadDataPort=GPIO_PORTB_DATA_REG;
    break;
    case PORTC:    ReadDataPort=GPIO_PORTC_DATA_REG;
    break;
    case PORTD:    ReadDataPort=GPIO_PORTD_DATA_REG;
    break;
    case PORTE:    ReadDataPort=GPIO_PORTE_DATA_REG;
    break;
    case PORTF:    ReadDataPort=GPIO_PORTF_DATA_REG;
    break;
    }
    //ReadDataPort=*Port_Ptr
    return ReadDataPort;

}

/****************************** DIO_WRITE_PORT   ***********************************************************************************/

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){
    //volatile Dio_PortType* Port_Ptr=NULL_PTR;

    switch(PortId){
    case PORTA:    GPIO_PORTA_DATA_REG=Level;//Port_Ptr = &GPIO_PORTA_DATA_REG
    break;
    case PORTB:    GPIO_PORTB_DATA_REG=Level;
    break;
    case PORTC:    GPIO_PORTC_DATA_REG=Level;
    break;
    case PORTD:    GPIO_PORTD_DATA_REG=Level;
    break;
    case PORTE:    GPIO_PORTE_DATA_REG=Level;
    break;
    case PORTF:    GPIO_PORTF_DATA_REG=Level;
    break;
    }
    //*Port_Ptr=Level

}

/**************************************** FLIP_CHANNEL*******************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){
volatile Dio_PortType *NEW_BASE_ADDRESS_PTR=NULL_PTR;
Dio_LevelType  Port_Level ;
Dio_LevelType New_Port_Level;

if(ChannelId>TOTAL_PINS-1){
// DET ERROR
}
 if(ChannelId > 37){
    ChannelId+=2;//something to handle the 8 pins
  }




NEW_BASE_ADDRESS_PTR=(Dio_PortType *)(array_of_base_address[ChannelId/8]+((0X0004)<<(ChannelId%8)));// the pointer now points the needed pin
Port_Level=((*NEW_BASE_ADDRESS_PTR)>>(ChannelId%8));// get the value of the needed pin and store it in a variable then return it

if(Port_Level== STD_LOW){
(*NEW_BASE_ADDRESS_PTR)=STD_HIGH<<(ChannelId%8);// modify the bit
New_Port_Level=STD_HIGH;
}

else{
(*NEW_BASE_ADDRESS_PTR)=STD_LOW<<(ChannelId%8); // modify the bit
New_Port_Level=STD_LOW;
}

return New_Port_Level;
}
