#include <stdio.h>
void init(int* p, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		*(p + i) = 0;
	}
}
void print(int* p, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d", *(p + i));
	}
	printf("\n");
}
void reverse(int* p, int len)
{
	int left = 0;
	int right = len - 1;
	int temp = 0;
	for (; left < right; left++, right--)
	{
		temp = *(p + left);
		*(p + left) = *(p + right);
		*(p + right) = temp;
	}
}
int main()
{
	int arr[10];
	int len = sizeof(arr) / sizeof(arr[0]);
	init(arr, len);
	print(arr, len);
	int b[10] = { 0,1,2,3,4,5,6,7,8,9 };
	len = sizeof(b) / sizeof(b[0]);
	reverse(b, len);
	print(b, len);
	return 0;
}