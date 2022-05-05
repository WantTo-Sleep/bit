#include <stdio.h>
void PrintNum(int i)
{
	if (i / 10 != 0)
		PrintNum(i / 10);
	printf("%d ", i % 10);
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	PrintNum(i);
	return 0;
}