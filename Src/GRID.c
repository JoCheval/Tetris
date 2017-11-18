/**
******************************************************************************
* @file    GRID.c
* @brief   Gère la grille de jeux.
******************************************************************************
*/
	
#include "tetris.h"
	
int Score;
int Lines;
int HighScore;
int Level;


/**
* @brief Retourne les numéro de lignes qui sont pleines.
*/
int Lines_Filled(void){
	return 0;
}
/**
* @brief Retire les lignes qui sont pleine et fait descendre celles au dessus.
*/
void Pop_Lines(int linesFilled){
	
}
/**
* @brief Ajoute la pièce à la grille. (Doit être appelé quand elle est au fond).
*/
void Add_Shape(){
	
}
/**
* @brief Vérifie si la pièce dépasse le haut de la grille et déclanche la fin
				 de la partie le cas échéant.
*/
char Is_At_Top(void){
	return 0;
}
