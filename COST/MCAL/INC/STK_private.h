/**************************************************************************************************
 Name        : STK_private.c
 Author      : Abdelkhalek magdy
 Created	 : 30/10/2022
 Version     : V01
 **************************************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


#include "../../Commen/STD_TYPES.h"

#define STK_BASE_ADDRESS 0xE000E010

typedef struct
{
	volatile u32 CTRL   ;
	volatile u32 LOAD   ;
	volatile u32 VAL    ;
	volatile u32 CALIB  ;  

}STK_t;

#define STK             (( STK_t     *)(STK_BASE_ADDRESS))
 
 
#endif