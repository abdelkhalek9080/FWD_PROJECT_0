/**************************************************************************************************
 Name        : Memmory_map.h
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/

#ifndef MEMMORY_MAP_H
#define MEMMORY_MAP_H
 
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
 
#include "STD_TYPES.h"

/*********************************************************************************************/
/************************************** SYSCTL Register **************************************/
/*********************************************************************************************/

#define SYSCTL 					0x400FE000
#define RCGCTIMER               *(volatile u32 *)(SYSCTL+0x604)
#define RCGCGPIO                *(volatile u32 *)(SYSCTL+0x608)

/*******************************************************************************************/
/************************************** GPIO Register **************************************/
/*******************************************************************************************/

#define GPIO_PORT_A_BASE 		0x40004000UL
#define GPIO_PORT_B_BASE 		0x40005000UL
#define GPIO_PORT_C_BASE 		0x40006000UL
#define GPIO_PORT_D_BASE 		0x40007000UL
#define GPIO_PORT_E_BASE 		0x40024000UL
#define GPIO_PORT_F_BASE 		0x40025000UL

typedef struct {                                                                    
  volatile u32  RESERVED0[255];
  volatile u32  DATA;                                                               
  volatile u32  DIR;                                                                
  volatile u32  IS;                                                                 
  volatile u32  IBE;                                                                
  volatile u32  IEV;                                                                
  volatile u32  IM;                                                                 
  volatile u32  RIS;                                                                
  volatile u32  MIS;                                                                
  volatile u32  ICR;                                                                
  volatile u32  AFSEL;                                                              
  volatile u32  RESERVED1[55];
  volatile u32  DR2R;                                                               
  volatile u32  DR4R;                                                               
  volatile u32  DR8R;                                                               
  volatile u32  ODR;                                                                
  volatile u32  PUR;                                                                
  volatile u32  PDR;                                                                
  volatile u32  SLR;                                                                
  volatile u32  DEN;                                                                
  volatile u32  LOCK;                                                               
  volatile u32  CR;                                                                 
  volatile u32  AMSEL;                                                              
  volatile u32  PCTL;                                                               
  volatile u32  ADCCTL;                                                             
  volatile u32  DMACTL;                                                             
} GPIOx_t;

#define GPIOA        ((GPIOx_t *) (GPIO_PORT_A_BASE) )
#define GPIOB        ((GPIOx_t *) (GPIO_PORT_B_BASE) )
#define GPIOC        ((GPIOx_t *) (GPIO_PORT_C_BASE) )
#define GPIOD        ((GPIOx_t *) (GPIO_PORT_D_BASE) )
#define GPIOE        ((GPIOx_t *) (GPIO_PORT_E_BASE) )
#define GPIOF        ((GPIOx_t *) (GPIO_PORT_F_BASE) )

/******************************************************************************************/
/************************************** GPT Register **************************************/
/******************************************************************************************/
#define GPT_TIMER_BASE_ADDRESS 0x40030000

#define GPT_TIMER0_BASE       0x40030000
#define GPT_TIMER1_BASE       0x40031000
#define GPT_TIMER2_BASE       0x40032000
#define GPT_TIMER3_BASE       0x40033000
#define GPT_TIMER4_BASE       0x40034000
#define GPT_TIMER5_BASE       0x40035000

#define GPT_TIMER0_WIDE_BASE  0x40036000
#define GPT_TIMER1_WIDE_BASE  0x40037000
#define GPT_TIMER2_WIDE_BASE  0x4003C000
#define GPT_TIMER3_WIDE_BASE  0x4003D000
#define GPT_TIMER4_WIDE_BASE  0x4003E000
#define GPT_TIMER5_WIDE_BASE  0x4003F000


typedef struct
{
    u32 GPTMCFG;      
    u32 GPTMTAMR;     
    u32 GPTMTBMR;     
    u32 GPTMCTL;      
    u32 GPTMSYNC;     
    u32 _RESERVED;    
    u32 GPTMIMR;      
    u32 GPTMRIS;      
    u32 GPTMMIS;      
    u32 GPTMICR;      
    u32 GPTMTAILR;    
    u32 GPTMTBILR;    
    u32 GPTMTAMATCHR; 
    u32 GPTMTBMATCHR; 
    u32 GPTMTAPR;     
    u32 GPTMTBPR;     
    u32 GPTMTAPMR;    
    u32 GPTMTBPMR;    
    u32 GPTMTAR;      
    u32 GPTMTBR;      
    u32 GPTMTAV;      
    u32 GPTMTBV;      
    u32 GPTMRTCPD;    
    u32 GPTMTAPS;     
    u32 GPTMTBPS;     
    u32 GPTMTAPV;     
    u32 GPTMTBPV;     
    u32 GPTMPP;       
} GPTx_t;
#define Timer0 			   ((GPTx_t *)(GPT_TIMER0_BASE))
#define Timer(TIMER_BASE)  ((GPTx_t *)(TIMER_BASE))

/*******************************************************************************************/
/************************************** NVIC Register **************************************/
/*******************************************************************************************/

#define NVIC_BASE    0XE000E100

typedef struct{
	u32 EN[5];
	u32 RESERVED0[27];
	u32 DIS[5];
	u32 RESERVED1[27];
	u32 PEND[5];
	u32 RESERVED2[27];
	u32 UNPEND[5];
	u32 RESERVED3[27];
	u32 ACTIVE[5];
	u32 RESERVED5[59];
	u32 PRI[35];
	u32 RESERVED6[669];
	u32 SWTRIG;
}NVIC_t;

#define NVIC  		  ((NVIC_t *)(NVIC_BASE))

#define SCB_APINT     (*(volatile u32*)(0xE000E000 + 0xD0C))

#define NVIC_PRI      ((volatile u8*)0XE000E400)



#endif