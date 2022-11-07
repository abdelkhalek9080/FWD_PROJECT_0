/**************************************************************************************************
 Name        : dio.c
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/
 
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "INC/dio.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
volatile static GPIOx_t *HandPtr1=NULL;
volatile static u8       PinNumber1;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 /*function to choose GPIO Port and Pin number*/
static void Set_Handelar1(DIO_ChannelType ChannelId){
	/*Channel A*/
	 if (ChannelId < 8)
    {
		PinNumber1=ChannelId;
		HandPtr1=GPIOA;
    }

    /*Channel B*/
    else if (ChannelId < 16)
    {
        PinNumber1 = ChannelId - 8;
		HandPtr1=GPIOB;
    }

    /*Channel C*/
    else if (ChannelId < 24)
    {
        PinNumber1 = ChannelId - 16;
		HandPtr1=GPIOC;
    }

    /*Channel D*/
    else if (ChannelId < 32)
    {
        PinNumber1 = ChannelId - 24;
		HandPtr1=GPIOD;
    }

    /*Channel D*/
    else if (ChannelId < 40)
    {
        PinNumber1 = ChannelId - 32;
		HandPtr1=GPIOE;
    }

    /*Channel F*/
    else if (ChannelId < 48)
    {
        PinNumber1 = ChannelId - 40;
	    HandPtr1=GPIOF;
    }
}



Port_PinLevelType DIO_ReadChannel(DIO_ChannelType ChannelId)
{
    
	Port_PinLevelType pinLevel;
    Set_Handelar1(ChannelId);
	pinLevel = GET_BIT( HandPtr1->DATA , PinNumber1);
    return pinLevel;
}

void DIO_WriteChannel(DIO_ChannelType ChannelId, Port_PinLevelType Level)
{
	Set_Handelar1(ChannelId);
	if(Level==HIGH_PIN){
		SET_BIT(HandPtr1->DATA, PinNumber1);
	}else{
		CLR_BIT(HandPtr1->DATA, PinNumber1);
	}
}

Port_PinLevelType GPIO_ReadPort(DIO_Port_t portID){
	DIO_PortLevelType portLevel;
   switch(portID){
	   case PORTA: portLevel=(u8)GPIOA->DATA;break;
	   case PORTB: portLevel=(u8)GPIOB->DATA;break;
	   case PORTC: portLevel=(u8)GPIOC->DATA;break;
	   case PORTD: portLevel=(u8)GPIOD->DATA;break;
	   case PORTE: portLevel=(u8)GPIOE->DATA;break;
	   case PORTF: portLevel=(u8)GPIOF->DATA;break;
   }
   return portLevel;
}

void DIO_WritePort(DIO_Port_t portID,Port_PinLevelType level){
   switch(portID){
	   case PORTA: GPIOA->DATA=level;break;
	   case PORTB: GPIOB->DATA=level;break;
	   case PORTC: GPIOC->DATA=level;break;
	   case PORTD: GPIOD->DATA=level;break;
	   case PORTE: GPIOE->DATA=level;break;
	   case PORTF: GPIOF->DATA=level;break;
   }
}
Port_PinLevelType DIO_FlipChannel(DIO_ChannelType ChannelId){
	
	Port_PinLevelType pinLevel;
	Set_Handelar1(ChannelId);
	TOG_BIT(HandPtr1->DATA, PinNumber1);
	pinLevel=GET_BIT(HandPtr1->DATA , PinNumber1);
    return pinLevel;
}