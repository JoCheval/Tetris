/**
  ******************************************************************************
  * @file    COMMANDS.c
  * @brief   Implémente Les interrupts pour les commandes par bouttons et ultrasons.
  ******************************************************************************
  */

#include "tetris.h"


//***********************************************//
// 										Bouttons 									 //
//***********************************************//

/**
* @brief Algorithme pour détecter la touche
*/

int Get_Key(void){
	return 0;
}
/**
* @brief Performe les actions associées à la touche
*/
void Handle_Key(int key){
	//Appel les fonctions de MOVE.c
}


//***********************************************//
// 										Ultra Sons								 //
//***********************************************//

int old_value1 = 0; //Valeur de TIM3->CCR1 au dernier front
float d1 = 0;  //distance 1 (cm)
// Les fonctions pour uttiliser les ultrasons..
