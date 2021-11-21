/**
 * @file sys.c
 * @author Bojan Gavrilovic (you@domain.com)
 * 
 * @brief This module is used to setup and initialize the system. It should be cointained
 * within the BSP layer for the given MCU
 * 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/****************************************************************************
 * P R I V A T E   I N C L U D E S
 * **************************************************************************/
#include "sys.h"
#include "main.h"

/****************************************************************************
 * P R I V A T E   D E F I N I T I O N S  
 * **************************************************************************/


/****************************************************************************
 * P R I V A T E   V A R I A B L E S  
 * **************************************************************************/


/****************************************************************************
 * P R I V A T E   F U N C T I O N  P R O T O T Y P E S
 * **************************************************************************/
static void    SYS_ClockConfig             ( void );
static void    SYS_GpioConfig              ( void );

/****************************************************************************
 * F U N C T I O N S
 * **************************************************************************/

/**
 * @brief This function will run the system initialization
 * 
 */
void SYS_Init ( void )
{
  ///< Reset of all peripherals, Initializes the Flash interface and the Systick
  HAL_Init();
  ///< Configure the system clocks
  SYS_ClockConfig();
  ///< Configure Gpio
  SYS_GpioConfig();
  return;
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
static void SYS_ClockConfig ( void )
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    SYS_ErrorHandler();
  }
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    SYS_ErrorHandler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    SYS_ErrorHandler();
  }
}

static void SYS_GpioConfig ( void )
{
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef ledConfig;
  ledConfig.Mode = GPIO_MODE_OUTPUT_PP;
  ledConfig.Pin = GPIO_PIN_13;

  HAL_GPIO_Init(GPIOB, &ledConfig);
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void SYS_ErrorHandler (void)
{
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */


void GPIO_TogglePin ( void )
{
  HAL_GPIO_TogglePin (GPIOB, GPIO_PIN_13);
}