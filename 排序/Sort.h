#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Queue.h"

// ����ʵ�ֵĽӿ�

// ��������
void InsertSort(int* a, int n);
// ϣ������
void ShellSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);
// ������
void AdjustDown(int* a, int n, int parent);
void HeapSort(int* a, int n);

// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// ���˹鲢
void _MergeSort(int* a, int* temp, int begin, int end);
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// �ǱȽ�����
// ��������
void CountSort(int* a, int n);
// ��������