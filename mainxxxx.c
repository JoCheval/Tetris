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
#include "usart.h"
#include "gpio.h"
#include "LCD.h"
#include "shapes.h"


/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* some RGB colors                                                */
#define LIGHTGREY       0xC618      /* 192, 192, 192 */
#define GEEN           	0x07E0      /*   0, 255,   0 */
#define CYAN            0x07FF      /*   0, 255, 255 */
#define RED             0xF800      /* 255,   0,   0 */
#define MAGENTA         0xF81F      /* 255,   0, 255 */
#define YELLOW          0xFFE0      /* 255, 255,   0 */
#define WHITE	          0xFFFF      /* 255, 255, 255 */

/* button matrix */
int col = 0;
int button = 0;

/* systick */
int cpt = 0;
int treshold = 1000;
int moveAllowed = 0;

/* tetris board var */

//TAILLE D'UN BLOC 10 pixels
#define BLOCK_SIZE 10

//Nombre de lignes de notre grille
#define TETRIS_V 18

//Nombre de colonnes de notre grille
#define TETRIS_H 12

//Dimension du LCD
#define TFTWIDTH 240
#define TFTHEIGHT 320


//LIMITE selon l'axe de x max et min
const int X_limit_max = (TFTWIDTH+TETRIS_H*BLOCK_SIZE)/2;
const int X_limit_min = (TFTWIDTH-TETRIS_H*BLOCK_SIZE)/2-BLOCK_SIZE;

//LIMITE selon l'axe de y max et min
const int Y_limit_max = TFTHEIGHT - BLOCK_SIZE;
const int Y_limit_min = TFTHEIGHT-TETRIS_V*BLOCK_SIZE - BLOCK_SIZE;

//Position initiale d'une piece
const int ORIGIN_X = TFTWIDTH/2-2*BLOCK_SIZE;
const int ORIGIN_Y = TFTHEIGHT - TETRIS_V*BLOCK_SIZE-2*BLOCK_SIZE;

//Matrice de notre notre jeux
int BOARD [TETRIS_H][TETRIS_V]={0};

//Couleurs pour chaque piece
const int COLOR_PIECE[7]={RED,GREEN,CYAN,MAGENTA,YELLOW,WHITE,LIGHTGRAY};

//Type de piece
enum BLOCK{O,I,S,Z,L,J,T};

//Information pour chaque piece
struct BLOCK_Info {
	int X;
	int Y;
	enum BLOCK Type;
	int rotation;
	int color;
} d;



/* structure des shapes qui fall ou qui vont fall */
struct BLOCK_Info blocksArray[2];
struct BLOCK_Info *current_falling_block;
int *blockArray;
int landed = 0;
/*int fallingBlockRot=0;
int fallingBlockShape=0; //BLOCK{O,I,S,Z,L,J,T}; static int PIECES[NB_KINDS][NB_ROTATIONS][SIZE][SIZE]
int fallingBlockRow=0;
int fallingBlockCol=0;*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* button matrix functions */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void findRow(void);

/* time interrupt */
void HAL_SYSTICK_Callback(void);


/* lcd */
void LCD_Begin(void);
void LCD_DrawFastHLine(int16_t x, int16_t y, int16_t length, uint16_t color);
void LCD_DrawFastVLine(int16_t x, int16_t y, int16_t length, uint16_t color);
void LCD_FillRect(int16_t x, int16_t y1, int16_t w, int16_t h, uint16_t fillcolor);
void LCD_Printf(const char *fmt, ...);
void LCD_SetCursor(unsigned int x, unsigned int y);
void LCD_SetTextColor(uint16_t c, uint16_t b);
void LCD_FillScreen(uint16_t color);
void LCD_SetTextSize(uint8_t s);
void LCD_DrawPixel(int16_t x, int16_t y, uint16_t color);
void LCD_FillRect(int16_t x, int16_t y1, int16_t w, int16_t h, uint16_t fillcolor);
void Menus_init(void);


/* tetris funcs */
void NextBlock(void);
void drawNewBlockVersion(void);
void drawSquare(int x, int y, int color);
void drawShape(struct BLOCK_Info *block);
void eraseSquare(int x, int y,int color);
void eraseShape(struct BLOCK_Info *block);
void moveShapeDOWN(struct BLOCK_Info *block);
void moveShapeLEFT(struct BLOCK_Info *block);
void moveShapeRIGHT(struct BLOCK_Info *block);
void colisionTestDOWN(struct BLOCK_Info *block);

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
  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */
	
	/* LCD init */
	LCD_Begin();
	LCD_Reset();
	LCD_FillScreen(BLACK);
	HAL_Delay(500);
	LCD_FillScreen(WHITE);
	HAL_Delay(500);
	LCD_FillScreen(BLACK);
	Menus_init();

	blocksArray[0].X = ORIGIN_X;
	blocksArray[0].Y = ORIGIN_Y;
	blocksArray[0].Type = Z;
	blocksArray[0].color = RED;
	blocksArray[0].rotation = 3;
	
	//drawShape(blocksArray);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */
	
	if (moveAllowed ==1){
		moveShapeDOWN(blocksArray);
		moveAllowed=0;
}
		
		
  /* USER CODE BEGIN 3 */

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
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 168;
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

/* USER CODE BEGIN 4 */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	col = 0;
	switch(GPIO_Pin){
		case GPIO_PIN_8: // col 4
			col = 4;
			break;
			
		case GPIO_PIN_9: // col 3
			col = 3;
			break;
		case GPIO_PIN_10: // col 2
			col = 2;
			break;
		case GPIO_PIN_11: // col 1
			col = 1;
			break;
		
	}
	HAL_Delay(10);
}

void findRow(void){
	
	switch (col){
		case 4: // col 4
			// set rows to 0
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
			// 
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)==1){button = 4;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)==1){button = 8;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)==1){button = 12;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_8)==1){button = 16;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
			break;
			
		case 3: // col 3
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
				
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)==1){button = 3;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)==1){button = 7;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)==1){button = 11;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_9)==1){button = 15;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
			break;
		case 2: // col 2
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
					
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)==1){button = 2;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)==1){button = 6;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)==1){button = 10;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10)==1){button = 14;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
			break;
		case 1: // col 1
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
		
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_11)==1){button = 1;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_11)==1){button = 5;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_11)==1){button = 9;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_Delay(7);
			if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_11)==1){button = 13;}
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
			
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_Delay(7);
			break;
	}
	col = 0; // doesn't reenter loop until interrupt occurs again
}

void HAL_SYSTICK_Callback(void){
	cpt++;
	if (cpt >= treshold){
	moveAllowed=1;
	cpt = 0;
	}
}


/*void NextBlock(void){
	fallingBlockShape = rand()%7;//0-6
	fallingBlockRot = rand()%4;//0-3
	//fallingBlockCol = ORIGN_X;
	//fallingBlockRow = ORIGN_Y;
}*/





void drawSquare(int x, int y, int color){
		LCD_FillRect(x,y,BLOCK_SIZE,BLOCK_SIZE,color);
		LCD_DrawFastHLine(x,y,BLOCK_SIZE,WHITE);
		LCD_DrawFastHLine(x,y+BLOCK_SIZE-1,BLOCK_SIZE,WHITE);
		LCD_DrawFastVLine(x,y,BLOCK_SIZE,WHITE);
		LCD_DrawFastVLine(x+BLOCK_SIZE-1,y,BLOCK_SIZE,WHITE);
}

void eraseSquare(int x, int y,int color){
		LCD_FillRect(x,y,BLOCK_SIZE,BLOCK_SIZE,color);
}

void drawShape(struct BLOCK_Info *block){
	int i,j;
	for (i=0;i<4;i++){
		for(j=0;j<4;j++){
			if (PIECES[block->Type][block->rotation][j][i]){
				drawSquare(block->X+i*BLOCK_SIZE,block->Y+j*BLOCK_SIZE,block->color);
			}
		}
	}
}

void eraseShape(struct BLOCK_Info *block){
	int i,j;
		for (i=0;i<4;i++){
		for(j=0;j<4;j++){
			if (PIECES[block->Type][block->rotation][j][i]){
				eraseSquare(block->X+i*BLOCK_SIZE,block->Y+j*BLOCK_SIZE,BLACK);
			}
		}
	}	
}


void Menus_init(void){
	LCD_DrawFastVLine(69,0,320,WHITE);
	LCD_DrawFastVLine(201,0,320,WHITE);
	LCD_DrawFastHLine(0,320/3,69,WHITE);
	LCD_DrawFastHLine(0,2*320/3,69,WHITE);
}


void moveShapeDOWN(struct BLOCK_Info *block){
//	colisionTestDOWN(block);
//	if (landed == 0){
	eraseShape(block);
	for(int i=0;i<1000;i++);
	block->Y=block->Y+BLOCK_SIZE;
	drawShape(block);
//	}
}

void moveShapeLEFT(struct BLOCK_Info *block){
	eraseShape(block);
	for(int i=0;i<1000;i++);
	block->X=block->X-BLOCK_SIZE;
	drawShape(block);
}

void moveShapeRIGHT(struct BLOCK_Info *block){
	eraseShape(block);
	for(int i=0;i<1000;i++);
	block->X=block->X+BLOCK_SIZE;
	drawShape(block);
}


/*struct BLOCK_Info {
	int X;
	int Y;
	enum BLOCK Type;
	int rotation;
	int color;
} d;*/
void colisionTestDOWN(struct BLOCK_Info *block){
	int i,j,NewRow;
	for (i=4;i>0;i--){
		for (j=0;j<4;j++){
			if (PIECES[block->Type][block->rotation][j][i]){
				NewRow = block->Y+i*BLOCK_SIZE;
					if (NewRow > TETRIS_V*BLOCK_SIZE){
					landed = 1;
					}
				
			}
		
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
