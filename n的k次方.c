#include <stdio.h>
int Pow(int n, int k)
{
	if (k == 1)
		return n;
	else
		return n * Pow(n, k - 1);
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	int a = Pow(n, k);
	printf("%d", a);
	return 0;
}