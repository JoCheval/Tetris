/**
******************************************************************************
* @file    GRID.h
* @author  
* @version 
* @date    
* @brief   This file contains all the functions prototypes for the GRID.c module.
******************************************************************************
*/ 

#ifndef __GRID_H
#define __GRID_H

#include "tetris.h"

int Lines_Filled(void);
void Pop_Lines(int linesFilled);
void Add_Shape(void);
char Is_At_Top(void);
	
#endif //__GRID_H

