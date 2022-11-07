/**************************************************************************************************
 Name        : NVIC_Types.c
 Author      : Abdelkhalek magdy
 Created	 : 14/10/2022
 **************************************************************************************************/
#ifndef NVIC_TYPES_H
#define NVIC_TYPES_H


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
typedef enum
{
     GPIOA_IRQ        =0U ,           
     GPIOB_IRQ            ,       
     GPIOC_IRQ            ,       
     GPIOD_IRQ            ,       
     GPIOE_IRQ            ,       
     UART0_IRQ            ,       
     UART1_IRQ            ,       
     SSI0_IRQ             ,       
     I2C0_IRQ             ,       
     PWM0_FAULT_IRQ       ,       
     PWM0_0_IRQ           ,       
     PWM0_1_IRQ           ,       
     PWM0_2_IRQ           ,       
     QEI0_IRQ             ,       
     ADC0SS0_IRQ          ,       
     ADC0SS1_IRQ          ,       
     ADC0SS2_IRQ          ,       
     ADC0SS3_IRQ          ,       
     WATCHDOG0_IRQ        ,       
     TIMER0A_IRQ          ,       
     TIMER0B_IRQ          ,       
     TIMER1A_IRQ          ,       
     TIMER1B_IRQ          ,       
     TIMER2A_IRQ          ,       
     TIMER2B_IRQ          ,       
     COMP0_IRQ            ,       
     COMP1_IRQ            ,       
     SYSCTL_IRQ           ,       
     FLASH_CTRL_IRQ       ,       
     GPIOF_IRQ            ,       
     UART2_IRQ            ,       
     SSI1_IRQ             ,       
     TIMER3A_IRQ          ,       
     TIMER3B_IRQ          ,       
     I2C1_IRQ             ,       
     QEI1_IRQ             ,       
     CAN0_IRQ             ,       
     CAN1_IRQ             ,       
     HIB_IRQ              ,       
     USB0_IRQ             ,       
     PWM0_3_IRQ           ,       
     UDMA_IRQ             ,       
     UDMAERR_IRQ          ,       
     ADC1SS0_IRQ          ,       
     ADC1SS1_IRQ          ,       
     ADC1SS2_IRQ          ,       
     ADC1SS3_IRQ          ,       
     SSI2_IRQ             ,       
     SSI3_IRQ             ,       
     UART3_IRQ            ,       
     UART4_IRQ            ,       
     UART5_IRQ            ,       
     UART6_IRQ            ,       
     UART7_IRQ            ,       
     I2C2_IRQ             ,       
     I2C3_IRQ             ,       
     TIMER4A_IRQ          ,       
     TIMER4B_IRQ          ,       
     TIMER5A_IRQ          ,       
     TIMER5B_IRQ          ,       
     WTIMER0A_IRQ         ,       
     WTIMER0B_IRQ         ,       
     WTIMER1A_IRQ         ,       
     WTIMER1B_IRQ         ,       
     WTIMER2A_IRQ         ,       
     WTIMER2B_IRQ         ,       
     WTIMER3A_IRQ         ,       
     WTIMER3B_IRQ         ,       
     WTIMER4A_IRQ         ,       
     WTIMER4B_IRQ         ,       
     WTIMER5A_IRQ         ,       
     WTIMER5B_IRQ         ,       
     SYSEXC_IRQ           ,       
     PWM1_0_IRQ           ,       
     PWM1_1_IRQ           ,       
     PWM1_2_IRQ           ,       
     PWM1_3_IRQ           ,       
     PWM1_FAULT_IRQ              

}IntCtrl_InterruptChannel_t;





#endif