#include "Heap.h"

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->a = NULL;
	hp->size = hp->capacity = 0;
	for (int i = 0; i < n; ++i)
	{
		HeapPush(hp, a[i]);
	}
}

// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->a = NULL;
	hp->size = hp->capacity = 0;
}

// ����
void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType temp = *a;
	*a = *b;
	*b = temp;
}

// ���ϵ���
void AdjustUp(Heap* hp)
{
	int child = hp->size - 1;
	int parent = (child - 1) / 2;

	while (child)
	{
		// ���� < ���ף���������С��
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

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	// ����
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

// ���µ���
void AdjustDown(HPDataType* a, int n, int parent)
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		// ��С��
		// �ҳ�ֵ��С�ĺ��ӵ��±�
		if (minChild + 1 < n && a[minChild] > a[minChild + 1])
		{
			minChild++;
		}
		// ���µ���
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

// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));

	// ��βԪ�ؽ���
	Swap(&hp->a[0], &hp->a[hp->size - 1]);

	AdjustDown(hp->a, --(hp->size), 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));

	return hp->a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp && !HeapEmpty(hp));

	return hp->size;
}

// �ѵ��п�
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

	// �ȶ���ǰ k ������
	for (int i = 0; i < k; ++i)
	{
		fscanf(a, "%d", heap + i);
	}

	// ����
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(heap, k, i);
	}

	// ������ȡʣ�µ�����
	HPDataType val = 0;
	while (fscanf(a, "%d", &val) != EOF)
	{
		if (val > heap[0])
		{
			heap[0] = val;
			AdjustDown(heap, k, 0);
		}
	}

	//��ӡ����
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
	////���д������
	//for (int i = 0; i < N; ++i)
	//{
	//	fprintf(a, "%d\n", rand() % 10000);
	//}
	//fclose(a);

	PrintTopK(arr, 10);

}