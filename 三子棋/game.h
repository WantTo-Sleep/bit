#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//初始化棋盘
void InitializeBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void Player(char board[ROW][COL], int row, int col);

//电脑下棋
void Computer(char board[ROW][COL], int row, int col);

//判断输赢 * - 玩家赢 # - 电脑赢 D - 平局 C - 继续下棋
char Winner(char board[ROW][COL], int row, int col);