/**************************************************************************************************
 Name        : NVIC.c
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "INC/NVIC.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void NVIC_Init(void){
	u8 count;
	SCB_APINT=MNVIC_GROUP_SUB_DISTRIBUTION;
	
	for(count=0;count<NVIC_NUM_OF_ENABLED_INTERRUPT;count++){
		
		#if (MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_8_SUB_1)
			
			NVIC_PRI[NVIC_PCfg[count].InterrNum]=((NVIC_PCfg[count].PriorityGP)<<5);
			
		#elif (MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_4_SUB_2)
			
			NVIC_PRI[NVIC_PCfg[count].InterrNum]=((NVIC_PCfg[count].PriorityGP)<<6)|((NVIC_PCfg[count].PrioritySubGP)<<5);
			
		#elif (MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_2_SUB_4)
			
			NVIC_PRI[NVIC_PCfg[count].InterrNum]=((NVIC_PCfg[count].PriorityGP)<<7)|((NVIC_PCfg[count].PrioritySubGP)<<5);
			
		#elif (MNVIC_GROUP_SUB_DISTRIBUTION == MNVIC_GROUP_1_SUB_8)
			
			NVIC_PRI[NVIC_PCfg[count].InterrNum]=((NVIC_PCfg[count].PrioritySubGP)<<5);
			
		#else
		#error "Wrong Configurations in IntCtr Grouping "
		#endif
		
		/*********** Enabel Interrupt ***********/
		NVIC->EN[NVIC_PCfg[count].InterrNum/32]=(1U<<NVIC_PCfg[count].InterrNum%32);
	}
	
	
}