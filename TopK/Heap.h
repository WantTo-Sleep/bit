#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);

// �ѵ�����
void HeapDestory(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
int HeapEmpty(Heap* hp);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(char* fileName, int k);
void TestTopk();