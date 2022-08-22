#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*Functions Prototype*/
void MNVIC_voidInit();
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx, u8 Copy_u8Priority);
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidsetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidsetPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8getActiveFlag(u8 Copy_u8IntNumber);

#endif
