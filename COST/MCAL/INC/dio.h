#ifndef DIO_H
#define DIO_H
/**************************************************************************************************
 Name        : dio.h
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/
 
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "../../Commen/Memory_map.h"
#include "../../Commen/BIT_MATH.h"
#include "../../Commen/STD_TYPES.h"
#include "dio_types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 /*function to choose GPIO Port and Pin number*/
static void Set_Handelar2(DIO_ChannelType ChannelId);

void GPIO_SptrSelect(DIO_ChannelType ChannelId);
Port_PinLevelType DIO_ReadChannel(DIO_ChannelType ChannelId);
void DIO_WriteChannel(DIO_ChannelType ChannelId, Port_PinLevelType Level);
Port_PinLevelType GPIO_ReadPort(DIO_Port_t portID);
void DIO_WritePort(DIO_Port_t portID,Port_PinLevelType level);
Port_PinLevelType DIO_FlipChannel(DIO_ChannelType ChannelId);

#endif