#pragma once

// 队列结构定义
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

// 队列初始化
void QueueIniti(Queue* q);
// 队列销毁
void QueueDestroy(Queue* q);

// 新建节点
QNode* BuyQNode(QDataType x);
// 队尾插入数据
void QueuePush(Queue* q, QDataType x);
// 队头出数据
void QueuePop(Queue* q);

// 判断队列为空
int QueueEmpty(Queue* q);

// 取队头数据
QDataType QueueFront(Queue* q);
// 取队尾数据
QDataType QueueBack(Queue* q);
// 队列长度
int QueueSize(Queue* q);
// 打印
void QueuePrint(Queue* q);