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

const int n1quarter = 600;
const int n2quarter = 300;
const int n3quarter = 300;
const int tquarter = 375;
const int kquarter = 350;
const int zquarter = 215;
#include "music.h"

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

TIM_HandleTypeDef htim4;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

volatile char sample = 0;
volatile char prevSample;
volatile int dvp;
volatile int songEnd = 1;
int song;
int duration;
int arsize;
char playMusic = 0;
const int *scale;
const char *notes;
const int *times;
const int *prevScale;
const char *prevNotes;
const int *prevTimes;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM4_Init(void);                                    
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
void playNoise1(void);
void playNoise2(void);
void playNoise3(void);
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

void playNoise1(void){
	prevSample = sample;
	sample=0;dvp=duration-20;songEnd=0;
	arsize = sizeof(noise1Times)/4;
	
	scale=noiseScale;
	notes=noise1Notes;
	times=noise1Times;
	playMusic = 1;
}
void playNoise2(void){
	prevSample = sample;
	sample=0;dvp=duration-20;songEnd=0;
	arsize = sizeof(noise2Times)/4;
	
	scale=noiseScale;
	notes=noise2Notes;
	times=noise2Times;
	playMusic = 1;
}
void playNoise3(void){
	prevSample = sample;
	sample=0;dvp=duration-20;songEnd=0;
	arsize = sizeof(noise3Times)/4;
	
	scale=noiseScale;
	notes=noise3Notes;
	times=noise3Times;
	playMusic = 1;
}

void playTetrisMusic(void){
	sample=0;dvp=0;songEnd=0;song=1;
	arsize = sizeof(tetrisTimes)/4;
	scale=tetrisScale;
	notes=tetrisNotes;
	times=tetrisTimes;
	playMusic = 1;
};

void playKirbyMusic(void){
	sample=0;dvp=0;songEnd=0;song=2;
	arsize = sizeof(kirbyTimes)/4;
	scale=kirbyScale;
	notes=kirbyNotes;
	times=kirbyTimes;
	playMusic = 1;
}

void playZeldaMusic(void){
	sample=0;dvp=0;songEnd=0;song=3;
	arsize = sizeof(zeldaTimes)/4;
	scale=zeldaScale;
	notes=zeldaNotes;
	times=zeldaTimes;
	playMusic = 1;
}

void playTunes(void){
	static int ctr = 0;
	int repNumber = 2;
	if (songEnd){
		if (scale!=noiseScale){
			ctr++;
			if (ctr<=repNumber)	playTetrisMusic();
			else if (ctr<=repNumber*2) playKirbyMusic();
			else if (ctr<=repNumber*3) playZeldaMusic();
			else ctr = 0;
		}
		if (scale == noiseScale){
			sample=prevSample;/*dvp=0;*/songEnd=0;
			switch (song){
			case 1:
				arsize = sizeof(tetrisTimes)/4;
				scale=tetrisScale;
				notes=tetrisNotes;
				times=tetrisTimes;
				break;
			case 2:
				arsize = sizeof(kirbyTimes)/4;
				scale=kirbyScale;
				notes=kirbyNotes;
				times=kirbyTimes;
				break;
			case 3:
				arsize = sizeof(zeldaTimes)/4;
				scale=zeldaScale;
				notes=zeldaNotes;
				times=zeldaTimes;
				break;
			}
			playMusic = 1;
		}
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
