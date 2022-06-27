#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY 10

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InitializeBoard(char board[ROWS][COLS], int row, int col, char ch);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col, int count);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void GetMineCount(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col, int *pwin);
