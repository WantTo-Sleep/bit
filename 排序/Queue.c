#include "Sort.h"

// ���г�ʼ��
void QueueIniti(Queue* q)
{
	assert(q);
	q->size = 0;
	q->front = NULL;
	q->rear = NULL;
}
// ��������
void QueueDestroy(Queue* q)
{
	assert(q);

	while (!QueueEmpty(q))
	{
		QueuePop(q);
	}

	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

// �½��ڵ�
QNode* BuyQNode(QDataType x)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		perror("BuyNode Fail");
		exit(-1);
	}

	newNode->next = NULL;
	newNode->x = x;

	return newNode;
}

// ��β��������
void QueuePush(Queue* q, QDataType x)
{
	assert(q);

	QNode* newNode = BuyQNode(x);

	if (QueueEmpty(q))
	{
		q->front = q->rear = newNode;
	}

	q->rear->next = newNode;
	q->rear = newNode;
	q->size++;
}

// �ж϶���Ϊ��
int QueueEmpty(Queue* q)
{
	return q->size == 0;
}

// ��ӡ
void QueuePrint(Queue* q)
{
	assert(q);

	if (QueueEmpty(q))
	{
		printf("NULL\n");
		return;
	}

	QNode* cur = q->front;

	while (cur)
	{
		printf("%d->", cur->x);
		cur = cur->next;
	}
	printf("NULL\n");
}

// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);

	if (QueueEmpty(q))
	{
		return;
	}

	QNode* del = q->front;
	q->front = q->front->next;
	free(del);
	if (q->front == NULL)
	{
		q->rear = NULL;
	}
	q->size--;
}

// ȡ��ͷ����
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		printf("����Ϊ��\n");
		return 0;
	}

	return q->front->x;
}
// ȡ��β����
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		printf("����Ϊ��\n");
		return 0;
	}

	return q->rear->x;
}
// ���г���
int QueueSize(Queue* q)
{
	assert(q);

	//if (QueueEmpty(q))
	//	return 0;

	//QNode* cur = q->front;
	//int count = 1;
	//while (cur != q->rear)
	//{
	//	++count;
	//	cur = cur->next;
	//}
	return q->size;
}