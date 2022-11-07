/*********************************/
/************INCLUDE**************/
/*********************************/
#include "INC/led.h"

void Init_Led(void){
	/*Enable CLK PORTA*/
	RCGCGPIO=1;
	/*
	*initialize STK timer
	* defualt CLK system 12MHZ
	* STK using CLK system Divided by 4 = 12/4 =3MHZ
	* to count 1 Sec by STK put 3 000 0000 in Load REG
	*/
	STK_voidInit();
	/*Configer PIN0 in Port A*/
	Port_ConfigType config={LED_NUMER,PORT_MODE_NORMAL,LOW_PIN,OUTPUT,DIGITAL,CURRENT_4mA};
	Port_Init(&config );
	
}


void Blink_LED(u32 onTime,u32 offTime){
	DIO_WriteChannel(LED_NUMER,HIGH_PIN);
	STK_voidBusyWait(onTime);
	DIO_WriteChannel(LED_NUMER,LOW_PIN);
	STK_voidBusyWait(offTime);
}

void Togle_LED(void){
	DIO_FlipChannel(LED_NUMER);
}