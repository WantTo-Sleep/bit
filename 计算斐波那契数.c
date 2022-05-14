#include <stdio.h>
int FibRec(int i)
{
	if (i > 2)
		return FibRec(i - 1) + FibRec(i - 2);
	else
		return 1;
}
int FibNonRec(int i)
{
	int arr[3] = { 0,1,1 };
	if (i < 3)
		return arr[i];
	else
	{
		int j = 0;
		for (j = 3; j <= i; j++)
		{
			arr[0] = arr[1];
			arr[1] = arr[2];
			arr[2] = arr[0] + arr[1];
		}
	}
	return arr[2];
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	int a = FibRec(i);
	int b = FibNonRec(i);
	printf("%d %d", a, b);
	return 0;
}