/**************************************************************************************************
 Name        : NVIC_Lcfg.c
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/

#ifndef NVIC_CFG_H
#define NVIC_CFG_H

/*
		
		 Options : 
		 
				#define MNVIC_GROUP_8_SUB_1		
				#define MNVIC_GROUP_4_SUB_2			
				#define MNVIC_GROUP_2_SUB_4			
				#define MNVIC_GROUP_1_SUB_8				
		*/
#define MNVIC_GROUP_8_SUB_1			0x05FA0400					  
#define MNVIC_GROUP_4_SUB_2			0x05FA0500					  
#define MNVIC_GROUP_2_SUB_4			0x05FA0600					  
#define MNVIC_GROUP_1_SUB_8			0x05FA0700

#define  MNVIC_GROUP_SUB_DISTRIBUTION		MNVIC_GROUP_4_SUB_2 


#define NVIC_NUM_OF_ENABLED_INTERRUPT                       1


#endif