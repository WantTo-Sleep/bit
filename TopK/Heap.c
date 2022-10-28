#include "Heap.h"

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->a = NULL;
	hp->size = hp->capacity = 0;
	for (int i = 0; i < n; ++i)
	{
		HeapPush(hp, a[i]);
	}
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

// 交换
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType temp = *a;
	*a = *b;
	*b = temp;
}

// 向上调整
void AdjustUp(Heap* hp)
{
	int child = hp->size - 1;
	int parent = (child - 1) / 2;

	while (child)
	{
		// 孩子 < 父亲，交换，是小堆
		if (hp->a[child] < hp->a[parent])
		{
			Swap(&hp->a[child], &hp->a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	// 扩容
	if (hp->capacity == hp->size)
	{
		hp->capacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* temp = (HPDataType*)realloc(hp->a, hp->capacity * sizeof(HPDataType));
		if (temp == NULL)
		{
			perror("Increase Capacity Failed");
			exit(-1);
		}
		hp->a = temp;
	}

	hp->a[hp->size++] = x;

	AdjustUp(hp);
}

// 向下调整
void AdjustDown(HPDataType* a, int n, int parent)
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		// 建小堆
		// 找出值较小的孩子的下标
		if (minChild + 1 < n && a[minChild] > a[minChild + 1])
		{
			minChild++;
		}
		// 向下调整
		if (a[minChild] < a[parent])
		{
			Swap(&a[parent], &a[minChild]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));

	// 首尾元素交换
	Swap(&hp->a[0], &hp->a[hp->size - 1]);

	AdjustDown(hp->a, --(hp->size), 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));

	return hp->a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));

	return hp->size;
}

// 堆的判空
int HeapEmpty(Heap* hp)
{
	return hp->size == 0;
}

void PrintTopK(char* fileName, int k)
{
	assert(fileName);
	FILE* a = fopen(fileName, "r");
	if (a == NULL)
	{
		perror("fopen-r fail");
		exit(-1);
	}
	HPDataType* heap = (HPDataType*)malloc(sizeof(HPDataType) * k);
	if (heap == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	// 先读入前 k 个数据
	for (int i = 0; i < k; ++i)
	{
		fscanf(a, "%d", heap + i);
	}

	// 建堆
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(heap, k, i);
	}

	// 继续读取剩下的数据
	HPDataType val = 0;
	while (fscanf(a, "%d", &val) != EOF)
	{
		if (val > heap[0])
		{
			heap[0] = val;
			AdjustDown(heap, k, 0);
		}
	}

	//打印数据
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", heap[i]);
	}

	free(heap);
	fclose(a);
}

void TestTopk()
{
	//int N = 10000;
	char arr[] = "data.txt";
	//FILE* a = fopen(arr, "w");
	//if (a == NULL)
	//{
	//	perror("fopen-w fail");
	//	exit(-1);
	//}
	////随机写入数据
	//for (int i = 0; i < N; ++i)
	//{
	//	fprintf(a, "%d\n", rand() % 10000);
	//}
	//fclose(a);

	PrintTopK(arr, 10);

}