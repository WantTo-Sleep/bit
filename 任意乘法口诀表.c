#include <stdio.h>
void Table(int num)
{
	int i = 1;
	for (; i <= num; i++)
	{
		int j = 1;
		for (; j <= i; j++)
		{
			printf("%-3d*%-3d=%-3d ", i, j, i * j);
		}
		printf("\n");
	}
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	Table(i);
	return 0;
}