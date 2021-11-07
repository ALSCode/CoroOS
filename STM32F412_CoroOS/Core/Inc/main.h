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
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#define LED3_Pin GPIO_PIN_2
#define LED3_GPIO_Port GPIOE
#define LED4_Pin GPIO_PIN_3
#define LED4_GPIO_Port GPIOE
#define DFSDM_DATIN3_Pin GPIO_PIN_4
#define DFSDM_DATIN3_GPIO_Port GPIOE
#define A0_Pin GPIO_PIN_0
#define A0_GPIO_Port GPIOF
#define LCD_BLCTRL_Pin GPIO_PIN_5
#define LCD_BLCTRL_GPIO_Port GPIOF
#define QSPI_BK1_IO3_Pin GPIO_PIN_6
#define QSPI_BK1_IO3_GPIO_Port GPIOF
#define QSPI_BK1_IO2_Pin GPIO_PIN_7
#define QSPI_BK1_IO2_GPIO_Port GPIOF
#define QSPI_BK1_IO0_Pin GPIO_PIN_8
#define QSPI_BK1_IO0_GPIO_Port GPIOF
#define QSPI_BK1_IO1_Pin GPIO_PIN_9
#define QSPI_BK1_IO1_GPIO_Port GPIOF
#define STLK_MCO_Pin GPIO_PIN_0
#define STLK_MCO_GPIO_Port GPIOH
#define DFSDM_CKOUT_Pin GPIO_PIN_2
#define DFSDM_CKOUT_GPIO_Port GPIOC
#define JOY_SEL_Pin GPIO_PIN_0
#define JOY_SEL_GPIO_Port GPIOA
#define STLINK_RX_Pin GPIO_PIN_2
#define STLINK_RX_GPIO_Port GPIOA
#define STLINK_TX_Pin GPIO_PIN_3
#define STLINK_TX_GPIO_Port GPIOA
#define CODEC_I2S3_WS_Pin GPIO_PIN_4
#define CODEC_I2S3_WS_GPIO_Port GPIOA
#define DFSDM_DATIN0_Pin GPIO_PIN_1
#define DFSDM_DATIN0_GPIO_Port GPIOB
#define QSPI_CLK_Pin GPIO_PIN_2
#define QSPI_CLK_GPIO_Port GPIOB
#define EXT_RESET_Pin GPIO_PIN_11
#define EXT_RESET_GPIO_Port GPIOF
#define CTP_RST_Pin GPIO_PIN_12
#define CTP_RST_GPIO_Port GPIOF
#define JOY_RIGHT_Pin GPIO_PIN_14
#define JOY_RIGHT_GPIO_Port GPIOF
#define JOY_LEFT_Pin GPIO_PIN_15
#define JOY_LEFT_GPIO_Port GPIOF
#define JOY_UP_Pin GPIO_PIN_0
#define JOY_UP_GPIO_Port GPIOG
#define JOY_DOWN_Pin GPIO_PIN_1
#define JOY_DOWN_GPIO_Port GPIOG
#define D4_Pin GPIO_PIN_7
#define D4_GPIO_Port GPIOE
#define D5_Pin GPIO_PIN_8
#define D5_GPIO_Port GPIOE
#define D6_Pin GPIO_PIN_9
#define D6_GPIO_Port GPIOE
#define D7_Pin GPIO_PIN_10
#define D7_GPIO_Port GPIOE
#define D8_Pin GPIO_PIN_11
#define D8_GPIO_Port GPIOE
#define D9_Pin GPIO_PIN_12
#define D9_GPIO_Port GPIOE
#define D10_Pin GPIO_PIN_13
#define D10_GPIO_Port GPIOE
#define D11_Pin GPIO_PIN_14
#define D11_GPIO_Port GPIOE
#define D12_Pin GPIO_PIN_15
#define D12_GPIO_Port GPIOE
#define I2C2_SCL_Pin GPIO_PIN_10
#define I2C2_SCL_GPIO_Port GPIOB
#define M2_CKIN_Pin GPIO_PIN_11
#define M2_CKIN_GPIO_Port GPIOB
#define CODEC_I2S3_SCK_Pin GPIO_PIN_12
#define CODEC_I2S3_SCK_GPIO_Port GPIOB
#define D13_Pin GPIO_PIN_8
#define D13_GPIO_Port GPIOD
#define D14_Pin GPIO_PIN_9
#define D14_GPIO_Port GPIOD
#define D15_Pin GPIO_PIN_10
#define D15_GPIO_Port GPIOD
#define LCD_RESET_Pin GPIO_PIN_11
#define LCD_RESET_GPIO_Port GPIOD
#define D0_Pin GPIO_PIN_14
#define D0_GPIO_Port GPIOD
#define D1_Pin GPIO_PIN_15
#define D1_GPIO_Port GPIOD
#define CODEC_INT_Pin GPIO_PIN_2
#define CODEC_INT_GPIO_Port GPIOG
#define LCD_TE_Pin GPIO_PIN_4
#define LCD_TE_GPIO_Port GPIOG
#define CTP_INT_Pin GPIO_PIN_5
#define CTP_INT_GPIO_Port GPIOG
#define QSPI_BK1_NCS_Pin GPIO_PIN_6
#define QSPI_BK1_NCS_GPIO_Port GPIOG
#define USB_OTGFS_OVRCR_Pin GPIO_PIN_7
#define USB_OTGFS_OVRCR_GPIO_Port GPIOG
#define USB_OTGFS_PPWR_EN_Pin GPIO_PIN_8
#define USB_OTGFS_PPWR_EN_GPIO_Port GPIOG
#define CODEC_I2S3_MCK_Pin GPIO_PIN_7
#define CODEC_I2S3_MCK_GPIO_Port GPIOC
#define uSD_D0_Pin GPIO_PIN_8
#define uSD_D0_GPIO_Port GPIOC
#define uSD_D1_Pin GPIO_PIN_9
#define uSD_D1_GPIO_Port GPIOC
#define M2_CKINA8_Pin GPIO_PIN_8
#define M2_CKINA8_GPIO_Port GPIOA
#define USB_OTGFS_VBUS_Pin GPIO_PIN_9
#define USB_OTGFS_VBUS_GPIO_Port GPIOA
#define USB_OTGFS_ID_Pin GPIO_PIN_10
#define USB_OTGFS_ID_GPIO_Port GPIOA
#define USB_OTGFS_DM_Pin GPIO_PIN_11
#define USB_OTGFS_DM_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define uSD_D2_Pin GPIO_PIN_10
#define uSD_D2_GPIO_Port GPIOC
#define uSD_D3_Pin GPIO_PIN_11
#define uSD_D3_GPIO_Port GPIOC
#define uSD_CLK_Pin GPIO_PIN_12
#define uSD_CLK_GPIO_Port GPIOC
#define D2_Pin GPIO_PIN_0
#define D2_GPIO_Port GPIOD
#define D3_Pin GPIO_PIN_1
#define D3_GPIO_Port GPIOD
#define uSD_CMD_Pin GPIO_PIN_2
#define uSD_CMD_GPIO_Port GPIOD
#define uSD_DETECT_Pin GPIO_PIN_3
#define uSD_DETECT_GPIO_Port GPIOD
#define FMC_NOE_Pin GPIO_PIN_4
#define FMC_NOE_GPIO_Port GPIOD
#define FMC_NWE_Pin GPIO_PIN_5
#define FMC_NWE_GPIO_Port GPIOD
#define FMC_NE1_Pin GPIO_PIN_7
#define FMC_NE1_GPIO_Port GPIOD
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define CODEC_I2S3ext_SD_Pin GPIO_PIN_4
#define CODEC_I2S3ext_SD_GPIO_Port GPIOB
#define CODEC_I2S3_SD_Pin GPIO_PIN_5
#define CODEC_I2S3_SD_GPIO_Port GPIOB
#define I2C1_SCL_Pin GPIO_PIN_6
#define I2C1_SCL_GPIO_Port GPIOB
#define I2C1_SDA_Pin GPIO_PIN_7
#define I2C1_SDA_GPIO_Port GPIOB
#define I2C2_SDA_Pin GPIO_PIN_9
#define I2C2_SDA_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_1
#define LED2_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
