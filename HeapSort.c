#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int HPDataType;

void Swap(HPDataType* a, HPDataType* b);

void AdjustDown(HPDataType* a, int n, int parent);

void HeapSort(int* a, int n);

HPDataType* GenerateData(int n);


int main()
{
	srand((unsigned int)time(NULL));

	HPDataType* data = GenerateData(20);

	HeapSort(data, 20);

	for (int i = 0; i < 20; ++i)
	{
		printf("%d ", data[i]);
	}
	return 0;
}

void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType temp = *a;
	*a = *b;
	*b = temp;
}

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

void HeapSort(int* a, int n)
{
	// 向下调整建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		// 从最后一个非叶子结点开始调整
		// n-1 是最后一个节点的下标
		// child = parent * 2 + 1;
		// parent = (child - 1) / 2;
		AdjustDown(a, n, i);
	}

	// 排升序 -- 建大堆，再把最大的放到最后
	// 排降序 -- 建小堆，再把最小的放到最后

	// 上面建小堆，现在排降序
	for (int i = n - 1; i > 0; --i)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}

HPDataType* GenerateData(int n)
{
	char fileName[] = "test.txt";
	// 随机生成数据
	FILE* data = fopen(fileName, "w");
	if (data == NULL)
	{
		perror("fopen fail");
		exit(-1);
	}
	// 将数据写入文件
	for (int i = 0; i < n; ++i)
	{
		fprintf(data, "%d\n", (HPDataType)(rand()));
	}
	fclose(data);

	// 将数据写入数组
	data = fopen(fileName, "r");
	HPDataType* a = malloc(sizeof(HPDataType) * n);
	if (a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (int i = 0; i < n; ++i)
	{
		fscanf(data, "%d", &a[i]);
	}
	fclose(data);

	return a;
}