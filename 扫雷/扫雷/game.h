#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9 
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_GAME 10


void InitBoard(char board[ROWS][COLS], int row, int col, char fill); //³õÊ¼»¯

void DisPlayBoard(char board[ROWS][COLS], int row, int col); //´òÓ¡

void BuriedMine(char Mine[ROWS][COLS],int row,int col); //ÂñÀ×

void PlayGame(char Mine[ROWS][COLS],char Show[ROWS][COLS],int row,int col);

