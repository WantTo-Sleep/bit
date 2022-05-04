#include <stdio.h>
#include <math.h>
int IsPrime(int i)
{
	int j = 0;
	for (j = 2; j <= sqrt(i); j++)
	{
		if (i % j == 0)
			return 0;
	}
	if (j > sqrt(i))
		return 1;
}

int main()
{
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		if (IsPrime(i))
			printf("%d ", i);
	}
	return 0;
}