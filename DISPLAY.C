/**
  ******************************************************************************
  * @file    DISPLAY.c
  * @brief   Fonctions et paramètres d'affichages.
  ******************************************************************************
  */


#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "LCD.h"
#include "stm32f4xx_hal.h"
#include "glcdfont.h"
#include "DISPLAY.h"

/**
* @brief Imprime la grille de jeux contenue dans ...
*/
void Print_Mat(void){
	
}
/**
* @brief Efface l'ancienne position de la pièce et imprime la nouvelle.
*/
void Print_Shape(void){
	static BLOCK_info old;
	extern d;
	
	//Effacer old
	//Imprimer Falling_Shape (d)
	//Copier Falling_Shape dans old.
}
/**
* @brief Réimprime le score
*/
void Print_Score(void){
	
}
/**
* @brief Réimprime le highscore
*/
void Print_HighScore(void){
	
}
/**
* @brief Réimprime le nombre de ligne empillée
*/
void Print_Line(void){
	
}
/**
* @brief Imprime la prochaine pièce
*/
void Print_Next_Shape(void){
	
}
/**
* @brief Réimprime le niveau
*/
void Print_Level(void){
	
}
