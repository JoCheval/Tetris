/**
  ******************************************************************************
  * @file    GRID.h
  * @author  
  * @version 
  * @date    
  * @brief   This file contains all the functions prototypes for the GRID.c module.
  ******************************************************************************
  */ 
	
	#include "tetris.h"
	
	int Lines_Filled(void);
	void Pop_Lines(int linesFilled);
	void Add_Shape(BLOCK_Info falling_shape);
	bool Is_At_Top(void);