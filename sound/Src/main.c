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

const int tquarter = 375;
const int kquarter = 350;
const int zquarter = 215;
#include "music.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

TIM_HandleTypeDef htim4;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

char sample = 0;
volatile int dvp;
volatile int songEnd = 1;
int duration;
int arsize;
char playMusic = 1;
const int *scale;
const char *notes;
const int *times;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM4_Init(void);                                    
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
void playTetrisMusic(void);
void playKirbyMusic(void);
void playZeldaMusic(void); // plays new zelda song, not old one
void playTunes(void); // plays all songs in a loop
void HAL_SYSTICK_Callback(void);

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
	
	playTunes();
  
	/*// zelda's lullaby
	int quarter = 545;
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
	
	NONOTE;HAL_Delay(1000);
*/

	
	
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
  htim4.Init.Prescaler = 0;
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

void HAL_SYSTICK_Callback(void){
	if(playMusic){
		if (sample>=arsize){
			sample = 0;
			songEnd = 1;
		}
		if (dvp>=duration){
			htim4.Instance->PSC=scale[notes[sample]];
			duration = times[sample];
			sample++;
			dvp=0;
		}
		dvp++;
	}
}

void playTetrisMusic(void){
	sample=0;dvp=0;songEnd=0;
	arsize = sizeof(tetrisTimes)/4;
	scale=tetrisScale;
	notes=tetrisNotes;
	times=tetrisTimes;
	playMusic = 1;
	/*
	CHPSC4[15];QUARN;
	CHPSC4[12];EIGHN;
	CHPSC4[13];EIGHN;
	CHPSC4[14];QUARN;
	CHPSC4[13];EIGHN;
	CHPSC4[12];EIGHN;
	CHPSC4[11];QUARNS;
	CHPSC4[11];EIGHN;
	CHPSC4[13];EIGHN;
	CHPSC4[15];QUARN;
	CHPSC4[14];EIGHN;
	CHPSC4[13];EIGHN;
	CHPSC4[12];QUARNS;
	CHPSC4[12];EIGHN;
	CHPSC4[13];EIGHN;
	CHPSC4[14];QUARN;
	CHPSC4[15];QUARN;
	CHPSC4[13];QUARN;
	CHPSC4[11];QUARNS;
	CHPSC4[11];QUARN;
	NONOTE;QUARN;
	
	CHPSC4[14];DOTQN;
	CHPSC4[16];EIGHN;
	CHPSC4[18];QUARN;
	CHPSC4[17];EIGHN;
	CHPSC4[16];EIGHN;
	CHPSC4[15];DOTQN;
	CHPSC4[13];EIGHN;
	CHPSC4[15];QUARN;
	CHPSC4[14];EIGHN;
	CHPSC4[13];EIGHN;
	CHPSC4[12];QUARNS;
	CHPSC4[12];EIGHN;
	CHPSC4[13];EIGHN;
	CHPSC4[14];QUARN;
	CHPSC4[15];QUARN;
	CHPSC4[13];QUARN;
	CHPSC4[11];QUARNS;
	CHPSC4[11];QUARN;
	NONOTE;QUARN;
	
	CHPSC4[8];HALFN;
	CHPSC4[6];HALFN;
	CHPSC4[7];HALFN;
	CHPSC4[5];HALFN;
	CHPSC4[6];HALFN;
	CHPSC4[4];HALFN;
	CHPSC4[3];HALFN;
	CHPSC4[5];HALFN;
	
	CHPSC4[8];HALFN;
	CHPSC4[6];HALFN;
	CHPSC4[7];HALFN;
	CHPSC4[5];HALFN;
	CHPSC4[6];QUARN;
	CHPSC4[8];QUARN;
	CHPSC4[11];QUARN;
	CHPSC4[11];QUARNS;
	CHPSC4[10];WHOLN;*/
};

void playKirbyMusic(void){
	sample=0;dvp=0;songEnd=0;
	arsize = sizeof(kirbyTimes)/4;
	scale=kirbyScale;
	notes=kirbyNotes;
	times=kirbyTimes;
	playMusic = 1;
	/*
	// A
	CHPSC2[5];TRIPA;
	CHPSC2[5];TRIPB;
	CHPSC2[8];SIXN;
	CHPSC2[8];TRIPA;
	CHPSC2[10];TRIPB;
	CHPSC2[12];EIGHN;
	CHPSC2[15];EIGHN;
	CHPSC2[14];EIGHN;
	CHPSC2[13];EIGHN;
	CHPSC2[12];QUARN;
	CHPSC2[10];TRIPA;
	CHPSC2[12];TRIPB;
	CHPSC2[11];QUARN;
	CHPSC2[9];TRIPA;
	CHPSC2[10];TRIPB;
	CHPSC2[9];QUARN;
	CHPSC2[10];TRIPA;
	CHPSC2[9];TRIPB;
	CHPSC2[8];SIXN;
	
	// A
	CHPSC2[5];TRIPA;
	CHPSC2[5];TRIPB;
	CHPSC2[8];SIXN;
	CHPSC2[8];TRIPA;
	CHPSC2[10];TRIPB;
	CHPSC2[12];EIGHN;
	CHPSC2[15];EIGHN;
	CHPSC2[14];EIGHN;
	CHPSC2[13];EIGHN;
	CHPSC2[12];QUARN;
	CHPSC2[10];TRIPA;
	CHPSC2[12];TRIPB;
	CHPSC2[11];QUARN;
	CHPSC2[9];TRIPA;
	CHPSC2[10];TRIPB;
	CHPSC2[9];QUARN;
	CHPSC2[10];TRIPA;
	CHPSC2[9];TRIPB;
	CHPSC2[8];SIXN;QUARNS;
	
	// B
	CHPSC2[8];QUARN;
	CHPSC2[9];EIGHN;
	CHPSC2[10];QUARN;
	CHPSC2[8];EIGHN;
	CHPSC2[9];EIGHN;
	CHPSC2[8];EIGHN;
	// bass line
	CHPSC3[1];EIGHN;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[1];EIGHN;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	CHPSC3[5];EIGHNS;
	
	// C
	CHPSC2[0];QUARN;
	CHPSC2[2];TRIPA;
	CHPSC2[0];TRIPB;
	CHPSC2[4];QUARN;
	CHPSC2[0];TRIPA;
	CHPSC2[4];TRIPB;
	CHPSC2[5];QUARN;
	CHPSC2[4];TRIPA;
	CHPSC2[5];TRIPB;
	CHPSC2[1];QUARNS;
	CHPSC2[1];TRIPA;
	CHPSC2[2];TRIPB;
	CHPSC2[0];QUARN;
	CHPSC2[2];TRIPA;
	CHPSC2[0];TRIPB;
	CHPSC2[4];QUARN;
	CHPSC2[0];TRIPA;
	CHPSC2[4];TRIPB;
	CHPSC2[5];HALFN;
	CHPSC2[8];QUARNS;
	
	// D
	CHPSC2[8];TRIPA;
	CHPSC2[9];TRIPB;
	CHPSC2[16];QUARN;
	CHPSC2[9];TRIPA;
	CHPSC2[16];TRIPB;
	CHPSC2[11];QUARN;
	CHPSC2[16];TRIPA;
	CHPSC2[11];TRIPB;
	CHPSC2[12];QUARN;
	CHPSC2[11];TRIPA;
	CHPSC2[12];TRIPB;
	CHPSC2[8];QUARNS;
	CHPSC2[8];TRIPA;
	CHPSC2[9];TRIPB;
	CHPSC2[16];QUARN;
	CHPSC2[9];TRIPA;
	CHPSC2[16];TRIPB;
	CHPSC2[11];QUARN;
	CHPSC2[16];TRIPA;
	CHPSC2[11];TRIPB;
	CHPSC2[9];HALFN;
	CHPSC2[12];QUARN;
	
	NONOTE;HAL_Delay(1000);
	*/
}

void playZeldaMusic(void){
	sample=0;dvp=0;songEnd=0;
	arsize = sizeof(zeldaTimes)/4;
	scale=zeldaScale;
	notes=zeldaNotes;
	times=zeldaTimes;
	playMusic = 1;
}

void playTunes(void){
	if (songEnd){
		static int ctr = 0;
		int repNumber = 1;
		ctr++;
		if (ctr<=repNumber)	playTetrisMusic();
		else if (ctr<=repNumber*2) playZeldaMusic();
		else if (ctr<=repNumber*3) playKirbyMusic();
		else ctr = 0;
	}
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
