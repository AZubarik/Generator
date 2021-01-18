/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
	
#define ON                  GPIO_PIN_SET
#define OFF					GPIO_PIN_RESET
/* SPI2 ---------------------------------------------------------------------*/	

#define CNV_ON				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, ON)
#define CNV_OFF				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, OFF)
	 
/* PWM ---------------------------------------------------------------------*/
	 
#define PWMN_Stop			HAL_TIMEx_PWMN_Stop
#define PWMN_Start			HAL_TIMEx_PWMN_Start
	 
/* TIM ---------------------------------------------------------------------*/
	 
#define	TIM_Stop_IT			HAL_TIM_Base_Stop_IT
#define TIM_Start_IT		HAL_TIM_Base_Start_IT

/* LED_VD, LED_VZ ----------------------------------------------------------*/
#define LED_VD				GPIO_PIN_7
#define LED_VZ				GPIO_PIN_12
	 
#define LED_VD1				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8)
/* -------------------------------------------------------------------------*/	
#define IZ30MIN				HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)	 
#define	IZ30MAX				HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)
#define ID30MIN				HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) 
#define	ID30MAX				HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2)
	 
#define ISTD_ON				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, ON)	
#define ISTD_OFF			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, OFF)
	 
#define	ISTZ_ON				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, ON) 
#define	ISTZ_OFF			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, OFF) 
	
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
