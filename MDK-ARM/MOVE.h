/**
  ******************************************************************************
  * @file    MOVE.h
  * @author  
  * @version 
  * @date    
  * @brief   This file contains all the functions prototypes for the MOVE.c module.
  ******************************************************************************
  */ 


enum BLOCK{O,I,S,Z,L,J,T};

struct Next_Shape_Struct{
	enum BLOCK Type;
	int color;
} Next_Shape;

//struct Falling_Shape_Struct{
//	int X;
//	int Y;
//	enum BLOCK Type;
//	int rotation;
//	int color;
//} Falling_Shape;

void MV_Left(void);
void MV_Right(void);
void Rot_Right(void);
void Rot_Left(void);
void MV_Down(void);
void MV_Bottom(void);
void Next_Shape(void);