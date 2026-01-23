#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS ROW+2

#define EASY_COUNT 80
#define MIDE_COUNT 20
#define HARD_COUNT 30

void InitBoard(char board[ROWS][COLS], int rows, int cols);//初始化数组

void DisplayBoard(char board[ROWS][COLS], int row, int col);//打印数组

void SetMine(char board[ROWS][COLS], int row, int col);//埋雷

char Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排查雷
