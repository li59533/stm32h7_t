/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/


/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */


#define SCL_Pin GPIO_PIN_8
#define SCL_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_7
#define SDA_GPIO_Port GPIOB
#define ARM_LED_Pin GPIO_PIN_10
#define ARM_LED_GPIO_Port GPIOA
#define LAN_RST_Pin GPIO_PIN_15
#define LAN_RST_GPIO_Port GPIOC

//ARM LED
#define LED_ON  HAL_GPIO_WritePin(ARM_LED_GPIO_Port, ARM_LED_Pin, GPIO_PIN_RESET)
#define LED_OFF HAL_GPIO_WritePin(ARM_LED_GPIO_Port, ARM_LED_Pin, GPIO_PIN_SET)

#define LED_TOGGLE HAL_GPIO_TogglePin(ARM_LED_GPIO_Port, ARM_LED_Pin);


#define LAN_RST_ON  HAL_GPIO_WritePin(LAN_RST_GPIO_Port, LAN_RST_Pin, GPIO_PIN_SET)
#define LAN_RST_OFF HAL_GPIO_WritePin(LAN_RST_GPIO_Port, LAN_RST_Pin, GPIO_PIN_RESET)
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

