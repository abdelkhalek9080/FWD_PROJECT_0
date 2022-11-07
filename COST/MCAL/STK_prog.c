/**************************************************************************************************
 Name        : STK_prog.c
 Author      : Abdelkhalek magdy
 Created	 : 30/10/2022
 Version     : V01
 **************************************************************************************************/

#include "INC/STK_interface.h"

void (*STK_CallBack)(void)=NULL;
volatile u8 G_u8Set_Mode=0;

/*function to initialize CLK for STK timer*/
void STK_voidInit(void){
	/*Disable counter and interrupt*/
	CLR_BIT(STK->CTRL,0);
	CLR_BIT(STK->CTRL,1);
	
	#if   STK_CLK_SRC==STK_CLK_DIV_4
		/*Select CLK /4*/
		CLR_BIT(STK->CTRL,2);
	#elif STK_CLK_SRC==STK_CLK /*System CLK = 1 MHZ*/
		/*Select CLK */
		SET_BIT(STK->CTRL,2);
	#else
		/*Erorr*/
	#endif
}

void STK_voidBusyWait(u32 Copy_u32TicksNUM)
{
	/*  Load Value Of Ticks in Load REG  */
		STK->LOAD = 1000*Copy_u32TicksNUM; /* To count in miliseconds */
	/*  Strat Timer */
		SET_BIT(STK->CTRL ,0);
	/*  Wait Count Flag Raise */
		while( GET_BIT(STK->CTRL,16) == 0U );
	/*  Stop Timer */
		STK ->VAL = 0U;
		STK ->LOAD = 0U;
		CLR_BIT(STK->CTRL ,0);	
}

u32 STK_u32GetRemainingTime(void)
{
	u32 L_u32RemainingTime = 0U ;
	L_u32RemainingTime= STK ->VAL ;
	return L_u32RemainingTime;
}

u32 STK_u32GetElapsedTime(void)
{
	u32 L_u32ElapsedTime = 0U ;
	L_u32ElapsedTime= (  (STK ->LOAD)  -   (STK ->VAL)) ;
	return L_u32ElapsedTime;
}

void STK_voidEnableINT(void)
{
	SET_BIT(STK -> CTRL,1);
}

void STK_voidDisableINT(void)
{
	CLR_BIT(STK -> CTRL,1);
}


void STK_voidSetIntervalPeriodic(u32 Copy_u32TicksNUM , void (* ptr)(void))
{
	/*  Load Ticks in Load Reg */
	STK -> LOAD =15999* Copy_u32TicksNUM;/* To count in miliseconds */
	/*  Set CallBack  */
	STK_CallBack = ptr;
	/*  Set Mode Periodic */
	G_u8Set_Mode = MODE_PERIODIC;
	/*  Enable For Interrput */
	SET_BIT(STK->CTRL ,1 );
	/*  Start Time */
	SET_BIT(STK->CTRL , 0);
}
void MSTK_vSetIntervalSingle(u32 Copy_u32TicksNUM , void (* ptr)(void))
{
	/*  Load Ticks in Load Reg */
	STK -> LOAD = 15999*Copy_u32TicksNUM;/* To count in miliseconds */
	/*  Set CallBack  */
	STK_CallBack = ptr;
	/*  Set Mode Single */
	G_u8Set_Mode = MODE_SINGLE;
	/*  Enable For Interrput */
	SET_BIT(STK->CTRL ,1 );
	/*  Start Time */
	SET_BIT(STK->CTRL , 0);
}


void STK_voidStopInterval(void) 
{
	/* Disable Interrupt*/
	CLR_BIT(STK->CTRL,1);
	/* Stop Timer */
	STK ->VAL  = 0U;
	STK ->LOAD = 0U;
	CLR_BIT(STK->CTRL ,0);	
}

void SysTick_Handler(void)
{

	u8 L_u8Temp=0U;
	STK_CallBack();
	if (G_u8Set_Mode == MODE_SINGLE )
	{
		/* Disable Interrupt*/
		CLR_BIT(STK->CTRL,0);
	    /* Stop Timer */
	    STK ->VAL = 0U;
		STK ->LOAD = 0U;
		CLR_BIT(STK->CTRL ,0);
		

	}
	/* Clear By Reading it*/
		L_u8Temp =GET_BIT(STK->CTRL,16);

}





