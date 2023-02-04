#pragma once

// ���нṹ����
typedef int QDataType;

typedef struct Queue
{
	int size;
	struct QNode* front;
	struct QNode* rear;
}Queue;

typedef struct QNode
{
	QDataType x;
	struct QNode* next;
}QNode;

// ���г�ʼ��
void QueueIniti(Queue* q);
// ��������
void QueueDestroy(Queue* q);

// �½��ڵ�
QNode* BuyQNode(QDataType x);
// ��β��������
void QueuePush(Queue* q, QDataType x);
// ��ͷ������
void QueuePop(Queue* q);

// �ж϶���Ϊ��
int QueueEmpty(Queue* q);

// ȡ��ͷ����
QDataType QueueFront(Queue* q);
// ȡ��β����
QDataType QueueBack(Queue* q);
// ���г���
int QueueSize(Queue* q);
// ��ӡ
void QueuePrint(Queue* q);