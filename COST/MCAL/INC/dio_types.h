#ifndef DIO_TYPES_H
#define DIO_TYPES_H
/**************************************************************************************************
 Name        : dio_types.c
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/
 
 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "../../Commen/STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
 
typedef u8 DIO_PortLevelType;

typedef enum {
	DIO_PIN_A0  =0U,
	DIO_PIN_A1     ,
	DIO_PIN_A2     ,
	DIO_PIN_A3     ,
	DIO_PIN_A4     ,
	DIO_PIN_A5     ,
	DIO_PIN_A6     ,
	DIO_PIN_A7     ,
				  
	DIO_PIN_B0     ,
	DIO_PIN_B1     ,
	DIO_PIN_B2     ,
	DIO_PIN_B3     ,
	DIO_PIN_B4     ,
	DIO_PIN_B5     ,
	DIO_PIN_B6     ,
	DIO_PIN_B7     ,
				   
	DIO_PIN_C0     ,
	DIO_PIN_C1     ,
	DIO_PIN_C2     ,
	DIO_PIN_C3     ,
	DIO_PIN_C4     ,
	DIO_PIN_C5     ,
	DIO_PIN_C6     ,
	DIO_PIN_C7     ,
				   
	DIO_PIN_D0     ,
	DIO_PIN_D1     ,
	DIO_PIN_D2     ,
	DIO_PIN_D3     ,
    DIO_PIN_D4     ,
    DIO_PIN_D5     ,
    DIO_PIN_D6     ,
    DIO_PIN_D7     ,
				   
    DIO_PIN_E0     ,
    DIO_PIN_E1     ,
    DIO_PIN_E2     ,
    DIO_PIN_E3     ,
    DIO_PIN_E4     ,
    DIO_PIN_E5     ,
    DIO_PIN_E6     ,
    DIO_PIN_E7     ,
				   
    DIO_PIN_F0     ,
    DIO_PIN_F1     ,
    DIO_PIN_F2     ,
    DIO_PIN_F3     ,
    DIO_PIN_F4     ,
    DIO_PIN_F5     ,
    DIO_PIN_F6     ,
    DIO_PIN_F7
  

}DIO_ChannelType;
typedef enum {
    PORT_MODE_NORMAL,
    PORT_MODE_ALTERNATE
}Port_PinModeType;

typedef enum {
    LOW_PIN,
    HIGH_PIN
}Port_PinLevelType;

typedef enum {

    INPUT ,
    OUTPUT

}Port_DirectionType;

typedef enum {
    DIGITAL,
    ANALOG,
    PULLUP,
    PULLDOWN,
    OPENDRAIN

}Port_PinInternalAttachType;


typedef enum {

    CURRENT_2mA,
    CURRENT_4mA,
    CURRENT_8mA

}Port_PinOutputCurrentType;

typedef enum {
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
}DIO_Port_t;


#endif