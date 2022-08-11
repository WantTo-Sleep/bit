#include <stdio.h>
#include <assert.h>
void* MyMemcpy(void* destination, const void* source, size_t num)
{
	assert(destination && source);
	//以最小内存单元字节为单位进行内存拷贝
	char* dest = (char*)destination;
	const char* sour = (char*)source;
	int i = 0;
	for (i = 0; i < num; i++)
	{
		*(dest + i) = *(sour + i);
	}
	return destination;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7 };
	int arr2[10] = { 0 };
	int* p = MyMemcpy(arr2, arr1, sizeof(arr1));
	int i = 0;
	for (i = 0; i < 7; i++)
		printf("%d ", arr2[i]);
	printf("\n");

	for (i = 0; i < 7; i++)
		printf("%d ", p[i]);
	printf("\n");

	char str1[] = "abcdef";
	char str2[10];
	char* str = MyMemcpy(str2, str1, sizeof(str1));
	printf("%s\n%s\n", str2, str);

	return 0;
}