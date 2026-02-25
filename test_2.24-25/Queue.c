#define _CRT_SECURE_NO_WARNINGS 

#include "Queue.h"

//队列初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead->next = NULL;
	pq->phead->val = 0;
	pq->ptail->next = NULL;
	pq->ptail->val = 0;
}

//销毁释放
void QueueDestory(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	QNode* pcur = pq->phead;
	while (pcur)
	{
		pq->phead = pq->phead->next;
		free(pcur);
		pcur = pq->phead;
	}
}

//队尾插入
void QueuePush(Queue* pq, QDateType x)
{
	assert(pq);

	QNode* new = (QNode*)malloc(sizeof(QNode));
	if (new)
	{
		perror("malloc error");
		return;
	}

	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = new;
		pq->phead->val = x;
	}
	else
	{
		pq->ptail->next = new;
		pq->ptail = new;
		pq->ptail->val = x;
		pq->ptail->next = NULL;
	}

}