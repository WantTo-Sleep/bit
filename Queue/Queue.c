#include "Queue.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	// 新建一个节点
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
	// 队列为空尾插要另外标注
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

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	
	QNode* del = q->front;
	q->front = q->front->next;
	free(del);

	q->size--;
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->front->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));

	return q->rear->data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->size == 0)
		return 1;
	return 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->size)
	{
		QueuePop(q);
	}
}