/**************************************************************************************************
 Name        : NVIC_Cfg.c
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "INC/NVIC_Lcfg.h"
#include "../MCAL/INC/NVIC.h"

const NVIC_Cfg NVIC_PCfg[NVIC_NUM_OF_ENABLED_INTERRUPT]={
	{TIMER0A_IRQ,1,0}
};