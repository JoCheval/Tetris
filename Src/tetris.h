#ifndef __TETRIS_H
#define __TETRIS_H

//#include "shapes.h"
//#include "LCD.c"

//TAILLE D'UN BLOC 10 pixels
#define BLOCK_SIZE 10

//Nombre de lignes de notre grille
#define TETRIS_V 18

//Nombre de colonnes de notre grille
#define TETRIS_H 12

//LIMITE selon l'axe de x max et minal
extern const int X_limit_max;
extern const int X_limit_min;

//LIMITE selon l'axe de y max et minal
extern const int Y_limit_max;
extern const int Y_limit_min;

//Position initiale d'une piece
extern const int ORIGN_X;
extern const int ORIGN_Y;

//Matrice de notre notre jeux
extern int BOARD [TETRIS_H][TETRIS_V];

//Couleurs pour chaque piece
extern const int COLOR_PIECE[7];

//Type de piece
extern enum BLOCK{O,I,S,Z,L,J,T};

//Information pour chaque piece
extern struct BLOCK_Info {
	int X;
	int Y;
	enum BLOCK Type;
	int rotation;
	int color;
} d;


//***********************************************//
// 										Move											 //
//***********************************************//
//struct Next_Shape_Struct{
//	enum BLOCK Type;
//	int color;
//} Next_Shape;

void MV_Left(void);
void MV_Right(void);
void Rot_Right(void);
void Rot_Left(void);
void MV_Down(void);
void MV_Bottom(void);
void Get_Next_Shape(void);

//***********************************************//
// 										Display										 //
//***********************************************//

void Print_Mat(void);
void Print_Shape(void);
void Print_Score(void);
void Print_HighScore(void);
void Print_Line(void);
void Print_Next_Shape(void);
void Print_Level(void);

//***********************************************//
// 										 Grid 										 //
//***********************************************//

int Lines_Filled(void);
void Pop_Lines(int linesFilled);
void Add_Shape(void);
char Is_At_Top(void);

#endif //__TETRIS_H
