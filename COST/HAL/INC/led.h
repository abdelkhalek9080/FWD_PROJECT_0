#ifndef LED_H
#define LED_H

/*********************************/
/************INCLUDE**************/
/*********************************/
#include "../../MCAL/INC/dio.h"
#include "../../MCAL/INC/port.h"
#include "../../MCAL/INC/STK_interface.h"

/*set led number */
#define LED_NUMER DIO_PIN_A0



void Init_Led(void);
void Blink_LED(u32 onTime,u32 offTime);
void Togle_LED(void);


#endif