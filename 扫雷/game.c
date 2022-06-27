#include "game.h"

void InitializeBoard(char board[ROWS][COLS], int row, int col, char ch)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ch;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----ɨ����Ϸ-----\n");
	for (i = 0; i <= col; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] == '0')
				printf("  ");
			else
				printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----ɨ����Ϸ-----\n");
}

void SetMine(char board[ROWS][COLS], int row, int col, int count)
{
	int i = 0;
	int j = 0;
	while (count)
	{
		i = rand() % row + 1;
		j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count--;
		}
	}
}

void GetMineCount(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col, int *pwin)
{
	if (show[x][y] == '*')
	{
		int i, j, count = 0;
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				if (mine[x + i][y + j] == '1')
					count++;
			}
		}
		show[x][y] = count + '0';
		(*pwin)++;
		if (show[x][y] == '0')
		{
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (x + i >= 1 && x + i <= row && y + j >= 1 && y + j <= col)
						GetMineCount(mine, show, x + i, y + j, row, col, pwin);
				}
			}
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while (win < row * col - EASY)
	{
		printf("�������Ų��׵����꣺");
		scanf("%d%d", &x, &y);
		system("cls");

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�����������Ϊ��%d��%d�������ź����㱻ը���ˣ�\n", x, y);
				int i, j;
				for (i = 1; i <= row; i++)
				{
					for (j = 1; j <= col; j++)
					{
						if (mine[i][j] == '1')
						{
							show[i][j] = '!';
						}
					}
				}
				DisplayBoard(show, row, col);
				break;
			}
			else
			{
				if (show[x][y] != '*')
				{
					printf("�������Ѿ����Ų����\n");
				}
				else
				{
					GetMineCount(mine, show, x, y, row, col, &win);
					DisplayBoard(show, row, col);
				}
			}
		}
		else
		{
			printf("�������벻�Ϸ���\n");
		}
		if (win == row * col - EASY)
		{
			printf("��ϲ�㣬���׳ɹ���\n");
			DisplayBoard(mine, row, col);
		}
	}
}