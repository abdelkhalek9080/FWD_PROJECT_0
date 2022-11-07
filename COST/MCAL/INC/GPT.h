/**************************************************************************************************
 Name        : GPT.h
 Author      : Abdelkhalek magdy
 Created	 : 20/10/2022
 **************************************************************************************************/
#ifndef GPT_H
#define GPT_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "../../Commen/Memory_map.h"
#include "../../Commen/STD_TYPES.h"
#include "../../Commen/BIT_MATH.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
typedef u32  Gpt_ValueType;
typedef u32  Time_Elapsed;
typedef u32  Gpt_Prescaler;

typedef enum{																						
    TIMER0		= 0x40030000u	,																			
    TIMER1		= 0x40031000u	,																							
    TIMER2		= 0x40032000u	,																			
    TIMER3		= 0x40033000u	,																			
    TIMER4		= 0x40034000u	,																			
    TIMER5		= 0x40035000u	,																			
																						
    TIMER0W		= 0x40036000u	,																			
    TIMER1W		= 0x40037000u	,																			
    TIMER2W		= 0x4004C000u	,																			
    TIMER3W		= 0x4004D000u	,																			
    TIMER4W		= 0x4004E000u	,																			
    TIMER5W		= 0x4004F000u	
}Gpt_Channel_t;

typedef enum{
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP

}Gpt_Mode_t;

typedef enum{
    GPT_CH_MODE_CONTINUOUS,
    GPT_CH_MODE_ONESHOT
}Gpt_ChannelMode_t;


typedef enum{
    GPT_PREDEF_TIMER_1US_16BIT   =4,
    GPT_PREDEF_TIMER_1US_24BIT   =4,
    GPT_PREDEF_TIMER_1US_32BIT   =0,
    GPT_PREDEF_TIMER_100US_32BIT =1
}Gpt_PredefTimer_t;

typedef enum{
    GPT_LENGTH_16BIT,
    GPT_LENGTH_32BIT,
    GPT_LENGTH_64BIT,
}Gpt_BusLength_t;


typedef struct
{
    Gpt_Channel_t 		 	    GPT_ChannelID;
	Gpt_Prescaler  				tickPrescaler;
    Gpt_ChannelMode_t           GPT_Channel_Mode;
	void (*Gpt_Notification)(void);

} Gpt_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
void Gpt_Init(const Gpt_ConfigType *ConfigPtr);
void Gpt_DelayMs( Gpt_Channel_t channelId, Gpt_ValueType msValue );
void Gpt_StartTimer(Gpt_Channel_t channelId, Gpt_ValueType loadValue);
void Gpt_StopTimer(Gpt_Channel_t Channel);
Time_Elapsed Gpt_GetTimeElapsed(Gpt_Channel_t Channel);
void Gpt_EnableNotification(Gpt_Channel_t channelId);
void Gpt_DisableNotifications(Gpt_Channel_t Channel);

#endif