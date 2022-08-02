#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//冒泡排序实现qsort功能
void BubbleQsort(void* base, size_t num, size_t width,int (*compar)(const void*, const void*));

void TestInt();
int CompareInt(const void* e1, const void* e2);

typedef struct Person
{
	char name[20];
	int age;
}Person;

void TestPerson_Name();
int ComparePerson_Name(const void* e1, const void* e2);

void TestPerson_Age();
int ComparePerson_Age(const void* e1, const void* e2);

int main()
{
	TestInt();
	TestPerson_Name();
	TestPerson_Age();
	return 0;
}

void BubbleQsort(void* base, size_t num, size_t width, int (*compare)(const void*, const void*))
{
	assert(base && compare);
	unsigned int i = 0, j = 0;
	for (i = 0; i < num - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < num - 1 - i; j++)
		{
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				unsigned int k = 0;
				char temp = 0;
				char* start = (char*)base + j * width;
				char* end = (char*)base + (j + 1) * width;
				for (k = 0; k < width; k++)
				{
					temp = *(start + k);
					*(start + k) = *(end + k);
					*(end + k) = temp;
				}
				flag = 0;
			}
		}
		if (flag) break;
	}
}

void TestInt()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("排序前：\n");
	int i = 0;
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	printf("排序后：\n");
	BubbleQsort(arr, len, sizeof(arr[0]), CompareInt);
	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int CompareInt(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void TestPerson_Name()
{
	Person per[] = { {"zhangsan",18},{"lisi",22},{"wangwu",29} };
	int len = sizeof(per) / sizeof(per[0]);
	printf("排序前：\n");
	int i = 0;
	for (i = 0; i < len; i++)
		printf("%s %d\n", per[i].name, per[i].age);
	printf("\n");

	printf("排序后：\n");
	BubbleQsort(per, len, sizeof(per[0]), ComparePerson_Name);
	for (i = 0; i < len; i++)
		printf("%s %d\n", per[i].name, per[i].age);
	printf("\n");
}
int ComparePerson_Name(const void* e1, const void* e2)
{
	return strcmp(((Person*)e1)->name, ((Person*)e2)->name);
}

void TestPerson_Age()
{
	Person per[] = { {"zhangsan",22},{"lisi",29},{"wangwu",18} };
	int len = sizeof(per) / sizeof(per[0]);
	printf("排序前：\n");
	int i = 0;
	for (i = 0; i < len; i++)
		printf("%s %d\n", per[i].name, per[i].age);
	printf("\n");

	printf("排序后：\n");
	BubbleQsort(per, len, sizeof(per[0]), ComparePerson_Age);
	for (i = 0; i < len; i++)
		printf("%s %d\n", per[i].name, per[i].age);
	printf("\n");
}
int ComparePerson_Age(const void* e1, const void* e2)
{
	return ((Person*)e1)->age - ((Person*)e2)->age;
}