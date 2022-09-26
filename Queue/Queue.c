#include "Queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	// �½�һ���ڵ�
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	if (temp == NULL)
	{
		perror("Push Fail");
		exit(-1);
	}
	else
	{
		temp->data = data;
		temp->next = NULL;
	}
	// ����Ϊ��β��Ҫ�����ע
	if (QueueEmpty(q))
	{
		q->front = temp;
		q->rear = temp;
	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;
	}
	q->size++;
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	
	QNode* del = q->front;
	q->front = q->front->next;
	free(del);

	q->size--;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->front->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->rear->data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->size == 0)
		return 1;
	return 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->size)
	{
		QueuePop(q);
	}
}