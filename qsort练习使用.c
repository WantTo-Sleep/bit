#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int CompareInt(const void* p1, const void* p2)
{
	assert(p1 && p2);
	//ÉıĞòÅÅĞò
	return *(int*)p1 - *(int*)p2;
	//½µĞòÅÅĞò
	//return *(int*)p2 - *(int*)p1;
}

struct Person
{
	char name[20];
	int age;
};

int ComparePerson_Name(const void* p1, const void* p2)
{
	assert(p1 && p2);
	//ÉıĞòÅÅĞò
	return strcmp(((struct Person*)p1)->name, ((struct Person*)p2)->name);
	//½µĞòÅÅĞò
	//return strcmp(((struct Person*)p2)->name, ((struct Person*)p1)->name);
}

int ComparePerson_Age(const void* p1, const void* p2)
{
	assert(p1 && p2);
	//ÉıĞòÅÅĞò
	return ((struct Person*)p1)->age - ((struct Person*)p2)->age;
	//½µĞòÅÅĞò
	//return ((struct Person*)p2)->age - ((struct Person*)p1)->age;

}

int main()
{
	//ÕûĞÎÊı¾İÅÅĞò
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("ÅÅĞòÇ°£º\n");
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\nÅÅĞòºó\n");
	qsort(arr, len, sizeof(arr[0]), CompareInt);
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	//½á¹¹ÌåÅÅĞò
	struct Person per[] = { {"zhangsan",18},{"lisi",25},{"wangwu",30} };
	len = sizeof(per) / sizeof(per[0]);
	printf("ÅÅĞòÇ°£º\n");
	for (i = 0; i < len; i++)
	{
		printf("%s %d\n", per[i].name, per[i].age);
	}

	printf("°´ĞÕÃûÅÅĞòºó£º\n");
	qsort(per, len, sizeof(per[0]), ComparePerson_Name);
	for (i = 0; i < len; i++)
	{
		printf("%s %d\n", per[i].name, per[i].age);
	}

	printf("°´ÄêÁäÅÅĞòºó£º\n");
	qsort(per, len, sizeof(per[0]), ComparePerson_Age);
	for (i = 0; i < len; i++)
	{
		printf("%s %d\n", per[i].name, per[i].age);
	}
	return 0;
}