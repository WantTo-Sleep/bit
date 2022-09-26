#include "Queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d\n", QueueBack(&q));

	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}

int main()
{
	TestQueue();

	return 0;
}