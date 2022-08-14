#include <stdio.h>
#include <assert.h>

void* MyMemmove(void* destination, const void* source, size_t num)
{
	assert(destination && source);
	char* dest = (char*)destination;
	const char* sour = (char*)source;
	//如果sour < dest, 就从后面的元素开始移动
	if (sour < dest)
	{
		for (int i = (int)(num - 1); i >= 0; i--)
			*(dest + i) = *(sour + i);
	}
	//否则, 就从前面面的元素开始移动
	else
	{
		for (size_t i = 0; i < num; i++)
			*(dest + i) = *(sour + i);
	}
	return destination;
}

int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	//将 1 2 3 4 5 这五个数移到 3 的位置上
	//变为 0 1 2 1 2 3 4 5 8 9
	MyMemmove(&arr[3], &arr[1], 5 * sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//0 1 2 1 2 3 4 5 8 9
	//将 3 4 5 8 这四个数移到第一个 1 的位置上
	//变为 0 3 4 5 8 3 4 5 8 9
	MyMemmove(&arr[1], &arr[5], 4 * sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}