#include <stdio.h>

void sort(int* p, int j)
{
	int i = 0;
	j--;
	for (i = 0; i < j; i++, j--)
	{
		for (; i < j; i++)
		{
			if (p[i] % 2 == 0)
				break;
		}
		for (; j > i; j--)
		{
			if (p[j] % 2 == 1)
				break;
		}
		if (i < j)
		{
			int temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
	}
}

int main()
{
	int arr[10] = { 0 };
	int i = 0;
	while (i < 10)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	sort(arr, sizeof(arr) / sizeof(arr[0]));
	int j = 0;
	for (j = 0; j < i; j++)
	{
		printf("%d ", arr[j]);
	}
	return 0;
}