/**************************************************************************************************
 Name        : GPT.c
 Author      : Abdelkhalek magdy
 Created	 : 20/10/2022
 **************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
 
#include "INC/GPT.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
 
void (*callBacksArray[12])(void) = {NULL};

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
	u32 timerBase=0;
	timerBase=ConfigPtr->GPT_ChannelID;
	/*Disable timer*/
	Timer(timerBase)->GPTMCTL=0;
	
	
	
	/*Normal Mode - not concatenated*/
    Timer(timerBase)->GPTMCFG = 0x4;
    /* Up counting */
    Timer(timerBase)->GPTMTAMR = 1 << 4;
	
	/* Single Shot mode or Continuous*/
    if (ConfigPtr->GPT_Channel_Mode == GPT_CH_MODE_CONTINUOUS)
    {
		/*Continuous*/
        Timer(timerBase)->GPTMTAMR = 0x2;
    }
    else
    {
		/*one shoot */
        Timer(timerBase)->GPTMTAMR = 0x1; 
    }
	
	 
    Timer(timerBase)->GPTMTAPR = ConfigPtr->tickPrescaler-1; 
	
	/* set call back to global array*/
    switch (ConfigPtr->GPT_ChannelID)
    {
    case TIMER0:
        callBacksArray[0] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER1:
        callBacksArray[1] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER2:
        callBacksArray[2] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER3:
        callBacksArray[3] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER4:
        callBacksArray[4] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER5:
        callBacksArray[5] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER0W:
        callBacksArray[6] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER1W:
        callBacksArray[7] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER2W:
        callBacksArray[8] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER3W:
        callBacksArray[9] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER4W:
        callBacksArray[10] = ConfigPtr->Gpt_Notification;
        break;
    case TIMER5W:
        callBacksArray[11] = ConfigPtr->Gpt_Notification;
        break;
    }
	
 
}
void Gpt_DelayMs( Gpt_Channel_t channelId, Gpt_ValueType msValue ) {
	
	Timer(channelId)->GPTMTAILR=0;
	/*load timer with counts for 1 ms overflow*/
	Timer(channelId)->GPTMTAILR=1600-1;
	/*clear timer timeout flag*/
	Timer(channelId)->GPTMICR=0x01;
	/*enable timer for counting*/
	Timer(channelId)->GPTMCTL=0x01;
	for ( u32 i =0; i<msValue; i++){
		while((Timer(channelId)->GPTMRIS&0x1==0x00));
		/*wait for TimerA timeout flag */
		Timer(channelId)->GPTMICR=0x01;
 
	}
	
}


void Gpt_StartTimer(Gpt_Channel_t channelId, Gpt_ValueType loadValue)
{
    Timer(channelId)->GPTMTAILR = loadValue;
    
	/*enable timer*/
	Timer(channelId)->GPTMCTL = 1; 
}
void Gpt_StopTimer(Gpt_Channel_t channelId)
{
    /* disable timer*/
    Timer(channelId)->GPTMCTL = 0; 
    
}

Time_Elapsed Gpt_GetTimeElapsed(Gpt_Channel_t channelId)
{
    return ((Time_Elapsed)Timer(channelId)->GPTMTAV);
}

void Gpt_EnableNotification(Gpt_Channel_t channelId)
{

    
    /*enable time out interrupt*/
    Timer(channelId)->GPTMIMR |= 1;
		
}
void Gpt_DisableNotifications(Gpt_Channel_t channelId)
{
    /* disable interrupt timeout*/
    Timer(channelId)->GPTMIMR = 0; 
}


void IRQ_TIMER0(void)
{
    if (callBacksArray[0] != NULL){
		 /*clear interrupt status flag*/
         Timer0->GPTMICR |= 1 << 0;
		 
		 
        callBacksArray[0]();
	}
}