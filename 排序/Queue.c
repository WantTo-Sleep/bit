#include "Sort.h"

// 队列初始化
void QueueIniti(Queue* q)
{
	assert(q);
	q->size = 0;
	q->front = NULL;
	q->rear = NULL;
}
// 队列销毁
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

// 新建节点
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

// 队尾插入数据
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

// 判断队列为空
int QueueEmpty(Queue* q)
{
	return q->size == 0;
}

// 打印
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

// 队头出数据
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

// 取队头数据
QDataType QueueFront(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		printf("队列为空\n");
		return 0;
	}

	return q->front->x;
}
// 取队尾数据
QDataType QueueBack(Queue* q)
{
	assert(q);
	if (QueueEmpty(q))
	{
		printf("队列为空\n");
		return 0;
	}

	return q->rear->x;
}
// 队列长度
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