#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3

//��ʼ������
void InitializeBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void Player(char board[ROW][COL], int row, int col);

//��������
void Computer(char board[ROW][COL], int row, int col);

//�ж���Ӯ * - ���Ӯ # - ����Ӯ D - ƽ�� C - ��������
char Winner(char board[ROW][COL], int row, int col);