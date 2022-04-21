#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void menu(void)
{
	printf("欢迎来到猜数字游戏！\n");
	printf("     1.paly\n");
	printf("     0.exit\n");
	printf("--------------------\n");
}
void game(void)
{
	int num = 0;
	int i = 0;
	num = rand() % 100 + 1;
	printf("请输入一个1-100之间的数字：");
	while (1)
	{
		scanf("%d", &i);
		if (i > num)
		{
			printf("猜大了，请重新输入：");
		}
		else if (i < num)
		{
			printf("猜小了，请重新输入：");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
	}
}
int main()
{
	menu();
	srand((unsigned int)time(NULL));
	int i = 0;
	do
	{
		printf("请选择：");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束，欢迎下次再来！\n");
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (i);
	return 0;
}