#include "Sort.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ��������
// �ռ临�Ӷ�O(1)
// ʱ�临�Ӷ����O(N) �O(N^2)
void InsertSort(int* a, int n)
{
	// ��֤ǰ i ���������õ� i+1 ��λ�õ�������
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i + 1;
		// ������
		while (end > 0 && a[end] < a[end - 1])
		{
			Swap(&a[end], &a[end - 1]);
			end--;
		}
	}
}

// ϣ������
// �ռ临�Ӷ�O(1)
// ƽ��ʱ�临�Ӷ�O(N^1.3)
void ShellSort(int* a, int n)
{
	// ϣ������
	int gap = n;
	while (gap > 1)
	{
		// Ϊ�˷�ֹԤ�����������Ӱ���㷨Ч��
		gap = gap / 3 + 1;
		// �����Ƿ��ʵ��� n-gap-1 ��λ�õ�Ԫ��ʱ�������Ԫ����ʵ�Ѿ����ʹ���
		// ���� i ����ֹ������Ϊ n-gap��
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			// ������
			while (end >= 0 && a[end] > a[end + gap])
			{
				Swap(&a[end], &a[end + gap]);
				end -= gap;
			}
		}
	}


	//int gap = n / 2;
	//while (gap > 0)
	//{
	//	// ���鲢��
	//	for (int i = 0; i < n - 1; ++i)
	//	{
	//		int end = i + gap;
	//		// ������
	//		while (end - gap >= 0 && a[end] < a[end - gap])
	//		{
	//			Swap(&a[end], &a[end - gap]);
	//			end -= gap;
	//		}
	//	}

	//	// һ��һ������
	//	//for (int j = 0; j < gap; ++j)
	//	//{
	//	//	for (int i = j; i < n - gap; i += gap)
	//	//	{
	//	//		int end = i + gap;
	//	//		// ������
	//	//		while (end - gap >= 0 && a[end] < a[end - gap])
	//	//		{
	//	//			Swap(&a[end], &a[end - gap]);
	//	//			end -= gap;
	//	//		}
	//	//	}
	//	//}
	//	gap /= 2;
	//}
}

// ѡ������
// �ռ临�Ӷ�O(1)
// ʱ�临�Ӷ�O(N^2)
void SelectSort(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		// ������
		int mini = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[mini] > a[j])
			{
				mini = j;
			}
		}
		Swap(&a[mini], &a[i]);
	}
}

// ������
// �ռ临�Ӷ�O(1)
// ʱ�临�Ӷ�O(N^logN)
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	// �����
	while (child < n)
	{
		// ����Һ��Ӵ��ڣ������� < �Һ���
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			// �ø��׺ͽϴ�ĺ��ӽ���
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	// ������
	// ���µ������ѵ�ʱ�临�Ӷ�O(N)
	// �����
	// parent = (child - 1) / 2; ���һ�����ӵ��±��� n-1
	for (int parent = (n - 2) / 2; parent >= 0; --parent)
	{
		AdjustDown(a, n, parent);;
	}

	// N*logN
	// �Ѷ����ݷŵ�������µ������ֶѵ���̬
	for (int i = n - 1; i > 0; --i)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i - 1, 0);
	}
}

// ð������
// �ռ临�Ӷ�O(1)
// ʱ�临�Ӷ�O(N^2)
void BubbleSort(int* a, int n)
{
	assert(a);

	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = 0; j + 1 < n - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}


// 1�����ֵ
// 2��ȡ�����/���ұ�/�м� ���������м�ֵ��key��
// ����ȡ��
int Middle(int* a, int left, int right)
{
	int mid = (right - left) / 2 + left;
	// �� > ��
	if (a[left] > a[mid])
	{
		// �� > ��
		if (a[mid] > a[right])
		{
			// �� > �� > ��
			return mid;
		}
		// �� > ��
		else if (a[left] > a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	// �� > ��
	else if (a[left] > a[right])
	{
		return left;
	}
	// �� > ��
	else if (a[mid] > a[right])
	{
		return right;
	}
	else
	{
		return mid;
	}
}

// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	// right ���±꣬�������һ��Ԫ�ص���һ��λ��
	int keyi = Middle(a, left, right);
	Swap(&a[keyi], &a[left]);

	keyi = left;

	while (left < right)
	{
		// ����С
		while (left<right && a[right]>=a[keyi])
		{
			--right;
		}
		// ���Ҵ�
		while (left<right && a[left]<=a[keyi])
		{
			left++;
		}

		if (left != right)
		{
			Swap(&a[left], &a[right]);
		}
		else
		{
			Swap(&a[keyi], &a[left]);
		}
	}
	// ���������㣬Ҳ�����ź�λ�õ�����
	return left;
}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int key = Middle(a, left, right);
	Swap(&a[left], &a[key]);

	key = a[left];
	int hole = left;

	while (left < right)
	{
		// ����С
		while (left<right && a[right]>=key)
		{
			--right;
		}
		if (left < right)
		{
			a[hole] = a[right];
			hole = right;
		}
		// ���Ҵ�
		while (left<right && a[left] <= key)
		{
			++left;
		}
		if (left < right)
		{
			a[hole] = a[left];
			hole = left;
		}
	}
	a[hole] = key;
	return hole;
}

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int keyi = Middle(a, left, right);
	Swap(&a[left], &a[keyi]);
	keyi = left;

	//cur��С
	// int prev = 0, cur = 1;
	int prev = left, cur = left + 1;
	while (cur <= right && a[cur] < a[keyi])
	{
		//һ��ʼcur��prev��һ���� ֱ��cur��һ���������������
		cur++; 
		prev++;
	}
	while (cur <= right)
	{
		if (a[cur] >= a[keyi])
		{
			cur++;
		}
		else
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}

// ��������
// �ռ临�Ӷȣ����O(logN)   �O(N)
// ʱ�临�Ӷȣ����O(N*logN) �O(N^2)
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;
	// С�����Ż�
	if (right - left <= 8)
	{
		InsertSort(a + left, right - left + 1);
		return;
	}
	// ���źõ�һ��
	// [left, right]
	int mid = PartSort1(a, left, right);

	QuickSort(a, left, mid - 1);
	QuickSort(a, mid + 1, right);
}

// �������� �ǵݹ�ʵ��
// �ռ临�Ӷȣ�ջO(logN) ����O(N)
// ʱ�临�Ӷȣ����O(N*logN) �O(N^2)
void QuickSortNonR(int* a, int left, int right)
{
	assert(a);
	Queue q;
	QueueIniti(&q);
	// �����д����Ҫ���������
	QueuePush(&q, left);
	QueuePush(&q, right);
	
	while (!QueueEmpty(&q))
	{
		left = QueueFront(&q);
		QueuePop(&q);
		right = QueueFront(&q);
		QueuePop(&q);
		// �ж������Ƿ���Ч
		if (left >= right)
		{
			continue;
		}
		else if (right - left <= 8)
		{
			InsertSort(a + left, right - left + 1);
		}
		else
		{
			int mid = PartSort1(a, left, right);
			QueuePush(&q, left);
			QueuePush(&q, mid - 1);
			QueuePush(&q, mid + 1);
			QueuePush(&q, right);
		}
	}
	QueueDestroy(&q);
}


// ���˹鲢
void _MergeSort(int* a, int* temp, int begin, int end)
{
	if (begin >= end)
		return;
	// ��¼��ʼλ��
	int begin1 = begin;
	int end1 = begin + (end - begin) / 2;
	int begin2 = end1 + 1;
	int end2 = end;

	_MergeSort(a, temp, begin1, end1);
	_MergeSort(a, temp, begin2, end2);

	int i = begin1;
	// ���������䶼û�б����꣬һֱ����
	while (begin1 <= end1 && begin2 <= end2)
	{
		// ������
		if (a[begin1] <= a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}
	// �Ѻ�������ݽ���
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}
	// ����temp���ź�������ݷŻ�a��
	memcpy(a + begin, temp + begin, sizeof(int) * (end - begin + 1));
}

// �鲢����ݹ�ʵ��
// �̶��ռ临�Ӷ�O(N)
void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);

	_MergeSort(a, temp, 0, n - 1);

	free(temp);
}