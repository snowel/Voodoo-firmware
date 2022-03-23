/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define TR_UP_Pin GPIO_PIN_1
#define TR_UP_GPIO_Port GPIOA
#define RT_LR_Pin GPIO_PIN_2
#define RT_LR_GPIO_Port GPIOA
#define LT_LR_Pin GPIO_PIN_3
#define LT_LR_GPIO_Port GPIOA
#define LT_UD_Pin GPIO_PIN_4
#define LT_UD_GPIO_Port GPIOA
#define L_T_key_Pin GPIO_PIN_5
#define L_T_key_GPIO_Port GPIOA
#define R_T_key_Pin GPIO_PIN_6
#define R_T_key_GPIO_Port GPIOA
#define R_I_Pin GPIO_PIN_7
#define R_I_GPIO_Port GPIOA
#define R_M_Pin GPIO_PIN_0
#define R_M_GPIO_Port GPIOB
#define R_R_Pin GPIO_PIN_1
#define R_R_GPIO_Port GPIOB
#define R_P_Pin GPIO_PIN_2
#define R_P_GPIO_Port GPIOB
#define L_i_Pin GPIO_PIN_10
#define L_i_GPIO_Port GPIOB
#define L_p_Pin GPIO_PIN_15
#define L_p_GPIO_Port GPIOB
#define L_r_Pin GPIO_PIN_9
#define L_r_GPIO_Port GPIOA
#define L_m_Pin GPIO_PIN_10
#define L_m_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
