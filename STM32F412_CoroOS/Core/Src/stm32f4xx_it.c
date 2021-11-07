/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
void send_event();
void timer_service();
void Dispatch();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim14;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM8 trigger and commutation interrupts and TIM14 global interrupt.
  */
void TIM8_TRG_COM_TIM14_IRQHandler(void)
{
  /* USER CODE BEGIN TIM8_TRG_COM_TIM14_IRQn 0 */

  /* USER CODE END TIM8_TRG_COM_TIM14_IRQn 0 */
  HAL_TIM_IRQHandler(&htim14);
  /* USER CODE BEGIN TIM8_TRG_COM_TIM14_IRQn 1 */

  /* USER CODE END TIM8_TRG_COM_TIM14_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global interrupt.
  */
void TIM6_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_IRQn 0 */

  /* USER CODE END TIM6_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_IRQn 1 */

  /* USER CODE END TIM6_IRQn 1 */
}

/* USER CODE BEGIN 1 */
__attribute__((naked)) void NMI_Handler(void)
{
	/* USER CODE BEGIN NonMaskableInt_IRQn 0 */
	__asm volatile(
			"ADD     sp,sp,#(8*4)     \n"

#if (__ARM_ARCH == 6)
			"CPSIE   i                \n"
			"BX      lr               \n"
#else
			"MOV     r0,#0            \n"
			"MSR     BASEPRI,r0       \n"
#if (__FPU_USED == 1)
			"POP     {r0,pc}          \n"
			"DSB					  \n"
#endif
			"BX      lr               \n"
			".align 4			  	  \n"
#endif
	);
	/* USER CODE END NonMaskableInt_IRQn 0 */
}


__attribute__((naked)) void PendSV_Handler (void){
	__asm volatile(

			"LDR     r3,=0xE000ED04	\n"
			"MOV	 r1,#1			\n"
			"LSL     r1,r1,#27		\n"

#if (__ARM_ARCH == 6)
			"CPSID   i				\n"
#else
#if (__ARM_FP != 0)
			"PUSH	 {r0,lr}		\n"
#endif
			"MOV	 r0, #0x50  	\n"
			"CPSID	 i				\n"
			"MSR	 BASEPRI,r0		\n"
			"DSB					\n"
			"ISB					\n"
			"CPSIE	 i				\n"
#endif

			"STR     r1,[r3]		\n"
			"LDR     r3,=1<<24		\n"
			"LDR     r2,=Dispatch	\n"
			"SUB     r2,r2,#1       \n"
			"LDR     r1,=DispatchReturn	\n"
			"SUB     sp,sp,#8*4			\n"
			"ADD     r0,sp,#5*4 		\n"
			"STM     r0!,{r1-r3}		\n"
			"LDR     r0,=0xFFFFFFF9		\n"
#if (__ARM_ARCH != 6)
			"DSB                    \n"
#endif
			"BX      r0				\n"
			".align 4			  	\n"
	);
}


__attribute__((naked)) void DispatchReturn (void){

	__asm volatile(
#if (__ARM_FP != 0)
			"MRS     r0,CONTROL       \n"
			"BICS    r0,r0,#4         \n"
			"MSR     CONTROL,r0       \n"
			"ISB                      \n"
#endif

			"LDR     r0,=0xE000ED04   \n"
#if (__ARM_ARCH != 6)
			"DSB                      \n"
#endif
			"MOV     r1,#1            \n"
			"LSL     r1,r1,#31        \n"
			"STR     r1,[r0]          \n"
			"B       .                \n"
			".align 4			  	  \n"
	);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){

	if (htim->Instance == TIM6){

		timer_service();

		SET_BIT(SCB->ICSR, SCB_ICSR_PENDSVSET_Msk);

	} else if (htim->Instance == TIM14){

		send_event();

		HAL_TIM_Base_Stop_IT(&htim14);
	}
}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
