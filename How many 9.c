#include <stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (9 == i % 10)
			count++;
		if (9 == i / 10)
			count++;
	}
	printf("%d", count);
	return 0;
}