/**************************************************************************************************
 Name        : STK_interface.c
 Author      : Abdelkhalek magdy
 Created	 : 30/10/2022
 Version     : V01
 **************************************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "../../Commen/STD_TYPES.h"
#include "../../Commen/BIT_MATH.h"

#include "STK_config.h"
#include "STK_private.h"


/*Clock source selection*/
#define STK_CLK_DIV_4 			 0U
#define STK_CLK   			 1U

/*Single timer OR Periodic*/
#define MODE_SINGLE              0U
#define MODE_PERIODIC            1U

void STK_voidInit(void);
void STK_voidBusyWait(u32 Copy_u32TicksNUM);
u32 STK_u32GetRemainingTime(void);
u32 STK_u32GetElapsedTime(void);
void STK_voidEnableINT(void);
void STK_voidDisableINT(void);
void STK_voidSetIntervalPeriodic(u32 Copy_u32TicksNUM , void (* ptr)(void));
void MSTK_vSetIntervalSingle(u32 Copy_u32TicksNUM , void (* ptr)(void));
void STK_voidStopInterval(void);

#endif