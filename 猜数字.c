#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void menu(void)
{
	printf("��ӭ������������Ϸ��\n");
	printf("     1.paly\n");
	printf("     0.exit\n");
	printf("--------------------\n");
}
void game(void)
{
	int num = 0;
	int i = 0;
	num = rand() % 100 + 1;
	printf("������һ��1-100֮������֣�");
	while (1)
	{
		scanf("%d", &i);
		if (i > num)
		{
			printf("�´��ˣ����������룺");
		}
		else if (i < num)
		{
			printf("��С�ˣ����������룺");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
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
		printf("��ѡ��");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ��������ӭ�´�������\n");
			break;
		default:
			printf("����������������룺\n");
			break;
		}
	} while (i);
	return 0;
}