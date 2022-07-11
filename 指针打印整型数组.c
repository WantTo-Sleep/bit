#include <stdio.h>

void PrintArray(int* p, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", *(p + i));
	}
}

int main()
{
	int arr[10] = { 0 };

	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}
