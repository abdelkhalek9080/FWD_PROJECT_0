/**************************************************************************************************
 Name        : port.h
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/
 
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "../../Commen/Memory_map.h"
#include "../../Commen/STD_TYPES.h"
#include "../../Commen/BIT_MATH.h"
#include "dio_types.h"
 
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 

typedef struct
{
    DIO_ChannelType PortPinNumber;                       
    Port_PinModeType PortPinMode;                     
    Port_PinLevelType PortPinLevel;                   
    Port_DirectionType PortPinDirection;              
    Port_PinInternalAttachType PortPinInternalAttach; 
    Port_PinOutputCurrentType PortPinOutputCurrent;   

}Port_ConfigType;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 /*function to choose GPIO Port and Pin number*/
static void Set_Handelar2(DIO_ChannelType ChannelId);

 /*function to set the configration of pin*/
void Port_Init(Port_ConfigType *ConfigPtr );


#endif /*PORT_H*/