#include <stdio.h>
#include <math.h>

int Daffo(int num)
{
	int temp = num;
	int i = 0;
	while (temp > 0)
	{
		temp = temp / 10;
		i++;
	}
	int sum = 0;
	int j = 0;
	for (temp = num; j < i; j++)
	{
		sum += (int)pow(temp % 10, i);
		temp /= 10;
	}
	if (sum == num)
		return 1;
	else
		return 0;
}

int main()
{
	int i = 0;
	int count = 0;
	for (i = 0; i <= 100000; i++)
	{
		if (Daffo(i) == 1)
		{
			printf("%-6d", i);
			count++;
		}
		if (count == 5)
		{
			printf("\n");
			count = 0;
		}
	}
	return 0;
}