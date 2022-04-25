#include <stdio.h>
int IsLeap(int i)
{
	if (i % 400 == 0)
		return 1;
	if (i % 4 == 0 && i % 100 != 0)
		return 1;
	return 0;
}
int main()
{
	int i = 0;
	int count = 0;
	for (i = 1000; i <= 2000; i++)
	{
		if (IsLeap(i))
		{
			printf("%d ", i);
			count++;
		}
		if (count == 10)
		{
			printf("\n");
			count = 0;
		}
	}
	return 0;
}