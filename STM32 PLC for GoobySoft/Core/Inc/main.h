/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f3xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DI0_Pin GPIO_PIN_2
#define DI0_GPIO_Port GPIOE
#define DI1_Pin GPIO_PIN_3
#define DI1_GPIO_Port GPIOE
#define DI2_Pin GPIO_PIN_4
#define DI2_GPIO_Port GPIOE
#define DI3_Pin GPIO_PIN_5
#define DI3_GPIO_Port GPIOE
#define DI4_Pin GPIO_PIN_6
#define DI4_GPIO_Port GPIOE
#define DI5_Pin GPIO_PIN_13
#define DI5_GPIO_Port GPIOC
#define DI8_Pin GPIO_PIN_9
#define DI8_GPIO_Port GPIOF
#define DI9_Pin GPIO_PIN_10
#define DI9_GPIO_Port GPIOF
#define PWM0_Pin GPIO_PIN_0
#define PWM0_GPIO_Port GPIOC
#define PWM1_Pin GPIO_PIN_1
#define PWM1_GPIO_Port GPIOC
#define PWM2_Pin GPIO_PIN_2
#define PWM2_GPIO_Port GPIOC
#define PWM3_Pin GPIO_PIN_3
#define PWM3_GPIO_Port GPIOC
#define PWM4_Pin GPIO_PIN_0
#define PWM4_GPIO_Port GPIOA
#define PWM5_Pin GPIO_PIN_1
#define PWM5_GPIO_Port GPIOA
#define IC2_Pin GPIO_PIN_2
#define IC2_GPIO_Port GPIOA
#define IC3_Pin GPIO_PIN_3
#define IC3_GPIO_Port GPIOA
#define AO0_Pin GPIO_PIN_4
#define AO0_GPIO_Port GPIOA
#define AO1_Pin GPIO_PIN_5
#define AO1_GPIO_Port GPIOA
#define AO2_Pin GPIO_PIN_6
#define AO2_GPIO_Port GPIOA
#define LED_USB_Pin GPIO_PIN_7
#define LED_USB_GPIO_Port GPIOA
#define LED_CAN_Pin GPIO_PIN_4
#define LED_CAN_GPIO_Port GPIOC
#define LED_ERROR_Pin GPIO_PIN_5
#define LED_ERROR_GPIO_Port GPIOC
#define AI0_Pin GPIO_PIN_0
#define AI0_GPIO_Port GPIOB
#define AI1_Pin GPIO_PIN_1
#define AI1_GPIO_Port GPIOB
#define AI2_Pin GPIO_PIN_2
#define AI2_GPIO_Port GPIOB
#define AI3_Pin GPIO_PIN_7
#define AI3_GPIO_Port GPIOE
#define AI4_Pin GPIO_PIN_8
#define AI4_GPIO_Port GPIOE
#define AI5_Pin GPIO_PIN_9
#define AI5_GPIO_Port GPIOE
#define AI6_Pin GPIO_PIN_10
#define AI6_GPIO_Port GPIOE
#define AI7_Pin GPIO_PIN_11
#define AI7_GPIO_Port GPIOE
#define AI8_Pin GPIO_PIN_12
#define AI8_GPIO_Port GPIOE
#define AI9_Pin GPIO_PIN_13
#define AI9_GPIO_Port GPIOE
#define AI10_Pin GPIO_PIN_14
#define AI10_GPIO_Port GPIOE
#define AI11_Pin GPIO_PIN_15
#define AI11_GPIO_Port GPIOE
#define DAI0P_Pin GPIO_PIN_14
#define DAI0P_GPIO_Port GPIOB
#define DAI0M_Pin GPIO_PIN_15
#define DAI0M_GPIO_Port GPIOB
#define DAI1P_Pin GPIO_PIN_8
#define DAI1P_GPIO_Port GPIOD
#define DAI1M_Pin GPIO_PIN_9
#define DAI1M_GPIO_Port GPIOD
#define DAI2P_Pin GPIO_PIN_10
#define DAI2P_GPIO_Port GPIOD
#define DAI2M_Pin GPIO_PIN_11
#define DAI2M_GPIO_Port GPIOD
#define DAI3P_Pin GPIO_PIN_12
#define DAI3P_GPIO_Port GPIOD
#define DAI3M_Pin GPIO_PIN_13
#define DAI3M_GPIO_Port GPIOD
#define DAI4P_Pin GPIO_PIN_14
#define DAI4P_GPIO_Port GPIOD
#define DAI4M_Pin GPIO_PIN_15
#define DAI4M_GPIO_Port GPIOD
#define E2__Pin GPIO_PIN_6
#define E2__GPIO_Port GPIOC
#define E2_C7_Pin GPIO_PIN_7
#define E2_C7_GPIO_Port GPIOC
#define PWM6_Pin GPIO_PIN_9
#define PWM6_GPIO_Port GPIOA
#define PWM7_Pin GPIO_PIN_10
#define PWM7_GPIO_Port GPIOA
#define E1__Pin GPIO_PIN_10
#define E1__GPIO_Port GPIOC
#define E1_C11_Pin GPIO_PIN_11
#define E1_C11_GPIO_Port GPIOC
#define CS0_Pin GPIO_PIN_5
#define CS0_GPIO_Port GPIOD
#define CS1_Pin GPIO_PIN_6
#define CS1_GPIO_Port GPIOD
#define CS2_Pin GPIO_PIN_7
#define CS2_GPIO_Port GPIOD
#define DI7_Pin GPIO_PIN_4
#define DI7_GPIO_Port GPIOB
#define DI6_Pin GPIO_PIN_5
#define DI6_GPIO_Port GPIOB
#define E0__Pin GPIO_PIN_6
#define E0__GPIO_Port GPIOB
#define E0_B7_Pin GPIO_PIN_7
#define E0_B7_GPIO_Port GPIOB
#define IC1_Pin GPIO_PIN_8
#define IC1_GPIO_Port GPIOB
#define IC0_Pin GPIO_PIN_9
#define IC0_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
