#include <stdio.h>

int main()
{
	int line = 0;
	printf("请输入要打印杨辉三角的行数：line = ");
	scanf("%d", &line);
	int p[20][20] = { 0 };

	int i = 0, j = 0;
	//初始化
	for (i = 0; i < line; i++)
	{
		p[i][0] = 1;
		p[i][i] = 1;
	}
	//设置杨辉三角
	for (i = 2; i < line; i++)
	{
		for (j = 1; j < i; j++)
		{
			p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
		}
	}
	//打印
	for (i = 0; i < line; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	return 0;
}