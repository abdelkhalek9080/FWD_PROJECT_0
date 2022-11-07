/**************************************************************************************************
 Name        : NVIC.h
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/
#ifndef NVIC_H
#define NVIC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "NVIC_Types.h"
#include "../../Config/INC/NVIC_Lcfg.h"
#include "../../Commen/STD_TYPES.h"
#include "../../Commen/BIT_MATH.h"
#include "../../Commen/Memory_map.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 

typedef struct
{
    IntCtrl_InterruptChannel_t  InterrNum;
    u8 							PriorityGP;
    u8 							PrioritySubGP;
}NVIC_Cfg;

extern const NVIC_Cfg NVIC_PCfg[NVIC_NUM_OF_ENABLED_INTERRUPT];

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void NVIC_Init(void);

#endif