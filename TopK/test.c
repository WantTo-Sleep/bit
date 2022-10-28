#include "Heap.h"

void testHeap()
{
	Heap hp;
	HPDataType a[] = { 24986,9766,19048,14178,5346,14856,20693,31779,25544,1570 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapCreate(&hp, a, n);

	for (int i = 0; i < HeapSize(&hp); ++i)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");

	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);

	for (int i = 0; i < HeapSize(&hp); ++i)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");
	printf("%d ", HeapTop(&hp));

	HeapDestory(&hp);
}

int main()
{
	srand((unsigned int)(time(NULL)));
	//testHeap();
	TestTopk();
	return 0;
}