/**************************************************************************************************
 Name        : port.c
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "INC/port.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
volatile static GPIOx_t *HandPtr2=NULL;
volatile static u8       PinNumber2;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
 /*function to choose GPIO Port and Pinnumber*/
static void Set_Handelar2(DIO_ChannelType ChannelId){
	/* Channel A*/
	 if (ChannelId < 8)
    {
		PinNumber2=ChannelId;
		HandPtr2=GPIOA;
    }

    /* Channel B*/
    else if (ChannelId < 16)
    {
        PinNumber2 = ChannelId - 8;
		HandPtr2=GPIOB;
    }

    /* Channel c*/
    else if (ChannelId < 24)
    {
        PinNumber2 = ChannelId - 16;
		HandPtr2=GPIOC;
    }

    /* Channel D*/
    else if (ChannelId < 32)
    {
        PinNumber2 = ChannelId - 24;
		HandPtr2=GPIOD;
    }

    /* Channel E*/
    else if (ChannelId < 40)
    {
        PinNumber2 = ChannelId - 32;
		HandPtr2=GPIOE;
    }

    /* Channel F*/
    else if (ChannelId < 48)
    {
        PinNumber2 = ChannelId - 40;
	    HandPtr2=GPIOF;
    }
}


 /*function to set the configration of pin*/
void Port_Init( Port_ConfigType *ConfigPtr){
	
	Set_Handelar2(ConfigPtr->PortPinNumber);
	
	/*************** Pin Mode ***************/
	if(ConfigPtr->PortPinMode==PORT_MODE_ALTERNATE){
		   SET_BIT(HandPtr2->AFSEL, PinNumber2);
	   }else{
		   CLR_BIT(HandPtr2->AFSEL, PinNumber2);
	   }
	   
	   /*************** Pin Level ***************/
	   if(ConfigPtr->PortPinLevel==HIGH_PIN){
		   SET_BIT(HandPtr2->DATA, PinNumber2);
	   }else{
		   CLR_BIT(HandPtr2->DATA, PinNumber2);
	   }
	   /*************** Pin Direction ***************/
	   if(ConfigPtr->PortPinDirection==INPUT){
		   CLR_BIT(HandPtr2->DIR, PinNumber2);
	   }else{
		   SET_BIT(HandPtr2->DIR, PinNumber2);
	   }
	   
	   /*************** Internal Attach ***************/
	    if(ConfigPtr->PortPinInternalAttach == PULLUP)
            SET_BIT(HandPtr2->PUR, PinNumber2);
        else if (ConfigPtr->PortPinInternalAttach == PULLDOWN)
            SET_BIT(HandPtr2->PDR, PinNumber2);
        else if (ConfigPtr->PortPinInternalAttach == OPENDRAIN)
            SET_BIT(HandPtr2->ODR, PinNumber2);
		
		/*************** utput Current ***************/
		if (ConfigPtr->PortPinOutputCurrent == CURRENT_2mA)
            SET_BIT(HandPtr2->DR2R, PinNumber2);
        else if (ConfigPtr->PortPinOutputCurrent == CURRENT_4mA)
            SET_BIT(HandPtr2->DR4R, PinNumber2);
        else if (ConfigPtr->PortPinOutputCurrent == CURRENT_8mA)
            SET_BIT(HandPtr2->DR8R, PinNumber2);
	
	
}