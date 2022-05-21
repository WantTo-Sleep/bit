#include "game.h"

void Menu()
{
	printf("��ϣ����\n");
	printf("    1.play  0.exit\n");
	printf("��ѡ��");
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
		printf("��ϲ����ʤ����\n");
	else if (win == '#')
		printf("���Ի�ʤ��\n");
	else
		printf("ƽ�֣�\n");
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
			printf("�ټ���\n");
			break;
		default:
			printf("ѡ�����!\n");
			break;
		}
	} while (input);

	return 0;
}