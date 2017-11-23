/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */
#define DOTEN HAL_Delay(quarter*3/4);
#define EIGHN HAL_Delay(quarter/2);
#define DOTQN HAL_Delay(quarter*3/2);
#define QUARN HAL_Delay(quarter);
#define DOTHN HAL_Delay(quarter*3);
#define HALFN HAL_Delay(quarter*2);
#define WHOLN HAL_Delay(quarter*4);
#define CHPSC htim4.Instance->PSC=note
#define NONOTE htim4.Instance->PSC=0
#define ADSR htim4.Instance->CCR1
#define ARRVAL htim4.Instance->ARR
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim4;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
const char tablesize=14;
const char sintable[tablesize] = {4,6,7,8,8,7,6,4,2,1,0,0,1,2};
//char notectr = 0;
const int quarter = 545;
int attack = quarter/7;
int decay = quarter/5;
int sustain = quarter/3;
int release = quarter*3/2;

/*const int note[15] = {
2309.200525, // Bb4
2057.142526, // C5
1832.591128, // D5
1729.691968, // Eb5
1540.853616, // F5
1372.643895, // G5
1222.776224, // A5
1154.087873, // Bb5
1028.071263, // C6
915.7955638, // D6
864.3390306, // Eb6
769.932327, // F6
685.8219473, // G6
610.8881119, // A6
576.5439367 // Bb6
};*/
const int note[15] = {
2746.252747, // G4
2446.552448, // A4
2179.535913, // B4
2057.142526, // C5
1832.591128, // D5
1632.557948, // E5
1454.321122, // F#5
1372.643895, // G5
1222.776224, // A5
1089.256919, // B5
1028.071263, // C6
915.7955638, // D6
815.7727791, // E6
726.6605609, // F#6
685.8219473, // G6
};
char sample = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM4_Init(void);                                    
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);

/**
  * @brief  PWM Pulse finished callback in non blocking mode 
  * @param  htim: pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
/**
  * @brief  Output Compare callback in non blocking mode 
  * @param  htim: pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM4_Init();

  /* USER CODE BEGIN 2 */
HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
/*for(int i=2;i<8;i++)	
{
	//tone
	//CHPSC[i];ADSR=39;
	//HAL_Delay(641);
	CHPSC[i];
	//attack
	for(int i=1;i<ARRVAL-1;i++){
		ADSR=i;
		HAL_Delay(attack/ARRVAL);
	}
	//decay
	for(int i=ARRVAL;i>ARRVAL/6;i--){
		ADSR--;
		HAL_Delay(decay/(ARRVAL/4));
	}
	//sustain
	HAL_Delay(sustain);
	//release
	for(int i=ARRVAL;i>0;i--){
		ADSR--;
		HAL_Delay(release/(ARRVAL*5/6));
	}
}*/
//arr 78 ccr1 39
	// A
	CHPSC[2];HALFN;
	CHPSC[4];QUARN;
	CHPSC[1];HALFN;
	CHPSC[0];EIGHN;
	CHPSC[1];EIGHN;
	CHPSC[2];HALFN;
	CHPSC[4];QUARN;
	CHPSC[1];HALFN;EIGHN;
	NONOTE;EIGHN;
	
	CHPSC[2];HALFN;
	CHPSC[4];QUARN;
	CHPSC[8];HALFN;
	CHPSC[7];QUARN;
	CHPSC[4];HALFN;
	CHPSC[3];EIGHN;
	CHPSC[2];EIGHN;
	CHPSC[1];HALFN;EIGHN;
	NONOTE;EIGHN;
	
	// B
	CHPSC[2];HALFN;
	CHPSC[4];QUARN;
	CHPSC[1];HALFN;
	CHPSC[0];EIGHN;
	CHPSC[1];EIGHN;
	CHPSC[2];HALFN;
	CHPSC[4];QUARN;
	CHPSC[1];HALFN;EIGHN;
	NONOTE;EIGHN;
	
	CHPSC[2];HALFN;
	CHPSC[4];QUARN;
	CHPSC[8];HALFN;
	CHPSC[7];QUARN;
	CHPSC[11];WHOLN;
	NONOTE;HALFN;
	
	// C
	CHPSC[11];HALFN;
	CHPSC[10];EIGHN;
	CHPSC[9];EIGHN;
	CHPSC[10];EIGHN;
	CHPSC[9];EIGHN;
	CHPSC[7];HALFN;
	
	CHPSC[10];HALFN;
	CHPSC[9];EIGHN;
	CHPSC[8];EIGHN;
	CHPSC[9];EIGHN;
	CHPSC[8];EIGHN;
	CHPSC[5];HALFN;
	
	CHPSC[11];HALFN;
	CHPSC[10];EIGHN;
	CHPSC[9];EIGHN;
	CHPSC[10];EIGHN;
	CHPSC[9];EIGHN;
	CHPSC[7];QUARN;
	CHPSC[10];QUARN;
	CHPSC[14];WHOLN;QUARN;
	NONOTE;QUARN;
	
	}
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* TIM4 init function */
static void MX_TIM4_Init(void)
{

  TIM_MasterConfigTypeDef sMasterConfig;
  TIM_OC_InitTypeDef sConfigOC;

  htim4.Instance = TIM4;
  htim4.Init.Prescaler = /*1704*//*23862*/0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 78;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 39;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  HAL_TIM_MspPostInit(&htim4);

}

/** Pinout Configuration
*/
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
/**
  * @brief  PWM Pulse finished callback in non blocking mode 
  * @param  htim: pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim){
	/*sample+=1;
	if (sample>tablesize) sample=0;
	htim4.Instance->CCR1 = sintable[sample];*/
}
/**
  * @brief  Output Compare callback in non blocking mode 
  * @param  htim: pointer to a TIM_HandleTypeDef structure that contains
  *                the configuration information for TIM module.
  * @retval None
  */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim){
	
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
