#include <stdio.h>
void PrintArray(int* p, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", *(p + i));
	}
	printf("\n");
}
void BubbleSort(int* p, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		int j = 0;
		int temp = 0;
		for (j = 0; j + 1 < len - i; j++)
		{
			if (*(p + j) > *(p + j + 1))
			{
				temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
			}
		}
	}
}
int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, sz);
	BubbleSort(arr, sz);
	PrintArray(arr, sz);

	return 0;
}