#include <stdio.h>
int Delete(int* p, int N, int del)
{
	int n = 0;
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (p[i] == del)
		{
			n++;
			int j = i;
			for (; j < N - n; j++)
			{
				p[j] = p[j + 1];
			}
			p[j] = 0;
			i--;
		}
	}
	return n;
}
int main()
{
	int arr[50] = { 0 };
	int N = 0;
	scanf("%d", &N);
	int i = 0;
	while (i < N)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	int del = 0;
	scanf("%d", &del);
	int n = Delete(arr, N, del);
	for (i = 0; i < N - n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}