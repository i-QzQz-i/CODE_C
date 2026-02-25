#define _CRT_SECURE_NO_WARNINGS 

#include "Queue.h"

void test1(Queue* pq)
{
	QueueInit(pq);

	QueuePush(pq, 1);
	printf("%d ", QueueBack(pq));

	QueuePush(pq, 2);
	printf("%d ", QueueBack(pq));

	QueuePush(pq, 3);
	printf("%d ", QueueBack(pq));

	QueuePush(pq, 4);
	printf("%d \n", QueueBack(pq));

	while (!QueueEmpty(pq))
	{
		printf("%d ", QueueFront(pq));
		QueuePop(pq);
	}

	QueueDestory(pq);
}

int main()
{
	Queue Q;
	test1(&Q);

	return 0;
}