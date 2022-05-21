#include "game.h"

void Menu()
{
	printf("您希望：\n");
	printf("    1.play  0.exit\n");
	printf("请选择：");
}

void Game()
{
	char win = 0;
	char board[ROW][COL] = { 0 };

	InitializeBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);

	while (1)
	{
		Player(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		win = Winner(board, ROW, COL);
		if (win != 'C')
			break;

		Computer(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		win = Winner(board, ROW, COL);
		if (win != 'C')
			break;
	}

	if (win == '*')
		printf("恭喜你获得胜利！\n");
	else if (win == '#')
		printf("电脑获胜！\n");
	else
		printf("平局！\n");
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;

	do
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("再见！\n");
			break;
		default:
			printf("选择错误!\n");
			break;
		}
	} while (input);

	return 0;
}