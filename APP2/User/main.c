/**
  ******************************************************************************
  * @file   main.c 
  ******************************************************************************
  * @attention
	*

  ******************************************************************************
  */  

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "Initialize.h"
#include "includes.h"
#include "APP.h"




void SysTick_Configuration(void);
OS_STK  TASK_START_STK[START_STK_SIZE];

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	/* Add your application code here */
	
	SCB->VTOR = FLASH_BASE | 0x1F000; /* Vector Table Relocation in Internal FLASH. */
	
	MCU_Init();
	
	SysTick_Configuration();   //ϵͳʱ�ӳ�ʼ��
	

	OSInit();
	
	OSTaskCreate(TaskStart,	   //task pointer
					(void *)0,	       //parameter
					(OS_STK *)&TASK_START_STK[START_STK_SIZE-1],//task stack top pointer
					START_TASK_Prio ); //task priority
	
	OSStart();                 //��ʼ������ִ��	
	return 0;	   
}

//ϵͳʱ������
void SysTick_Configuration(void)
{
 	SysTick->CTRL&=~(1<<2); //SYSTICKʹ���ⲿʱ��Դ
	SysTick->CTRL|=1<<1;    //����SYSTICK�ж�
	SysTick->LOAD=10000000/OS_TICKS_PER_SEC;  //��������Ƶ����80MHz������8��Ƶ��Ϊ10MHz
	SysTick->CTRL|=1<<0;    //����SYSTICK
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/