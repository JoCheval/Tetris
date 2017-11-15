#include "shapes.h"
#include "LCD.h"

//TAILLE D'UN BLOC 10 pixels
#define BLOCK_SIZE 10

//Nombre de lignes de notre grille
#define TETRIS_V 18

//Nombre de colonnes de notre grille
#define TETRIS_H 12

//LIMITE selon l'axe de x max et minal
const int X_limit_max = (TFTWIDTH+TETRIS_H*BLOCK_SIZE)/2;
const int X_limit_min = (TFTWIDTH-TETRIS_H*BLOCK_SIZE)/2-BLOCK_SIZE;

//LIMITE selon l'axe de y max et minal
const int Y_limit_max = TFTHEIGHT - BLOCK_SIZE;
const int Y_limit_min = TFTHEIGHT-TETRIS_V*BLOCK_SIZE - BLOCK_SIZE;

//Position initiale d'une piece
const int ORIGN_X = TFTWIDTH/2-2*BLOCK_SIZE;
const int ORIGN_Y = TFTHEIGHT - TETRIS_V*BLOCK_SIZE-2*BLOCK_SIZE;

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
