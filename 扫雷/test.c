#include "game.h"

void menu()
{
	printf("---------------------------\n");
	printf("-----1.play     0.exit-----\n");
	printf("---------------------------\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	InitializeBoard(mine, ROWS, COLS, '0');
	InitializeBoard(show, ROWS, COLS, '*');

	SetMine(mine, ROW, COL, EASY);
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:game(); 
			break;
		case 0:printf("退出游戏！\n");
			break;
		default:printf("输入错误！\n");
			break;
		}
	} while (input);
	return 0;
}