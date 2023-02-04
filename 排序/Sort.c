#include "Sort.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 插入排序
// 空间复杂度O(1)
// 时间复杂度最好O(N) 最坏O(N^2)
void InsertSort(int* a, int n)
{
	// 保证前 i 个数有序，让第 i+1 个位置的数插入
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i + 1;
		// 排升序
		while (end > 0 && a[end] < a[end - 1])
		{
			Swap(&a[end], &a[end - 1]);
			end--;
		}
	}
}

// 希尔排序
// 空间复杂度O(1)
// 平均时间复杂度O(N^1.3)
void ShellSort(int* a, int n)
{
	// 希尔排序
	int gap = n;
	while (gap > 1)
	{
		// 为了防止预排序次数过多影响算法效率
		gap = gap / 3 + 1;
		// 当我们访问到第 n-gap-1 的位置的元素时，后面的元素其实已经访问过了
		// 所以 i 的中止条件变为 n-gap；
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			// 排升序
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
	//	// 多组并排
	//	for (int i = 0; i < n - 1; ++i)
	//	{
	//		int end = i + gap;
	//		// 排升序
	//		while (end - gap >= 0 && a[end] < a[end - gap])
	//		{
	//			Swap(&a[end], &a[end - gap]);
	//			end -= gap;
	//		}
	//	}

	//	// 一组一组排序
	//	//for (int j = 0; j < gap; ++j)
	//	//{
	//	//	for (int i = j; i < n - gap; i += gap)
	//	//	{
	//	//		int end = i + gap;
	//	//		// 排升序
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

// 选择排序
// 空间复杂度O(1)
// 时间复杂度O(N^2)
void SelectSort(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		// 排升序
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

// 堆排序
// 空间复杂度O(1)
// 时间复杂度O(N^logN)
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	// 建大堆
	while (child < n)
	{
		// 如果右孩子存在，且左孩子 < 右孩子
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			// 让父亲和较大的孩子交换
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
	// 排升序
	// 向下调整建堆的时间复杂度O(N)
	// 建大堆
	// parent = (child - 1) / 2; 最后一个孩子的下标是 n-1
	for (int parent = (n - 2) / 2; parent >= 0; --parent)
	{
		AdjustDown(a, n, parent);;
	}

	// N*logN
	// 堆顶数据放到最后，向下调整保持堆的形态
	for (int i = n - 1; i > 0; --i)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i - 1, 0);
	}
}

// 冒泡排序
// 空间复杂度O(1)
// 时间复杂度O(N^2)
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


// 1、随机值
// 2、取最左边/最右边/中间 三个数的中间值做key。
// 三数取中
int Middle(int* a, int left, int right)
{
	int mid = (right - left) / 2 + left;
	// 左 > 中
	if (a[left] > a[mid])
	{
		// 中 > 右
		if (a[mid] > a[right])
		{
			// 左 > 中 > 右
			return mid;
		}
		// 右 > 中
		else if (a[left] > a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	// 中 > 左
	else if (a[left] > a[right])
	{
		return left;
	}
	// 右 > 左
	else if (a[mid] > a[right])
	{
		return right;
	}
	else
	{
		return mid;
	}
}

// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	// right 是下标，还是最后一个元素的下一个位置
	int keyi = Middle(a, left, right);
	Swap(&a[keyi], &a[left]);

	keyi = left;

	while (left < right)
	{
		// 右找小
		while (left<right && a[right]>=a[keyi])
		{
			--right;
		}
		// 左找大
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
	// 返回相遇点，也就是排好位置的数据
	return left;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = Middle(a, left, right);
	Swap(&a[left], &a[key]);

	key = a[left];
	int hole = left;

	while (left < right)
	{
		// 右找小
		while (left<right && a[right]>=key)
		{
			--right;
		}
		if (left < right)
		{
			a[hole] = a[right];
			hole = right;
		}
		// 左找大
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

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int keyi = Middle(a, left, right);
	Swap(&a[left], &a[keyi]);
	keyi = left;

	//cur找小
	// int prev = 0, cur = 1;
	int prev = left, cur = left + 1;
	while (cur <= right && a[cur] < a[keyi])
	{
		//一开始cur和prev先一起走 直到cur第一次遇到比它大的数
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

// 快速排序
// 空间复杂度：最好O(logN)   最坏O(N)
// 时间复杂度：最好O(N*logN) 最坏O(N^2)
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;
	// 小区间优化
	if (right - left <= 8)
	{
		InsertSort(a + left, right - left + 1);
		return;
	}
	// 先排好第一遍
	// [left, right]
	int mid = PartSort1(a, left, right);

	QuickSort(a, left, mid - 1);
	QuickSort(a, mid + 1, right);
}

// 快速排序 非递归实现
// 空间复杂度：栈O(logN) 队列O(N)
// 时间复杂度：最好O(N*logN) 最坏O(N^2)
void QuickSortNonR(int* a, int left, int right)
{
	assert(a);
	Queue q;
	QueueIniti(&q);
	// 队列中存放需要排序的区间
	QueuePush(&q, left);
	QueuePush(&q, right);
	
	while (!QueueEmpty(&q))
	{
		left = QueueFront(&q);
		QueuePop(&q);
		right = QueueFront(&q);
		QueuePop(&q);
		// 判断区间是否有效
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


// 单趟归并
void _MergeSort(int* a, int* temp, int begin, int end)
{
	if (begin >= end)
		return;
	// 记录起始位置
	int begin1 = begin;
	int end1 = begin + (end - begin) / 2;
	int begin2 = end1 + 1;
	int end2 = end;

	_MergeSort(a, temp, begin1, end1);
	_MergeSort(a, temp, begin2, end2);

	int i = begin1;
	// 当两个区间都没有遍历完，一直遍历
	while (begin1 <= end1 && begin2 <= end2)
	{
		// 排升序
		if (a[begin1] <= a[begin2])
		{
			temp[i++] = a[begin1++];
		}
		else
		{
			temp[i++] = a[begin2++];
		}
	}
	// 把后面的数据接上
	while (begin1 <= end1)
	{
		temp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		temp[i++] = a[begin2++];
	}
	// 将在temp中排好序的数据放回a中
	memcpy(a + begin, temp + begin, sizeof(int) * (end - begin + 1));
}

// 归并排序递归实现
// 固定空间复杂度O(N)
void MergeSort(int* a, int n)
{
	int* temp = (int*)malloc(sizeof(int) * n);

	_MergeSort(a, temp, 0, n - 1);

	free(temp);
}