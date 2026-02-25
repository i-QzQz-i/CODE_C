#define _CRT_SECURE_NO_WARNINGS 

#include "Queue.h"

//队列初始化
void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = NULL;
	//pq->phead->val = 0;
	pq->ptail = NULL;
	//pq->ptail->val = 0;
	pq->size = 0;
}

//销毁释放
void QueueDestory(Queue* pq)
{
	//assert(pq);
	//assert(pq->phead);

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
	
	if (new == NULL)
	{
		perror("malloc error");
		return;
	}
	new->next = NULL;
	new->val = x;

	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = new;
	}
	else
	{
		pq->ptail->next = new;
		pq->ptail = new;
	}

	pq->size++;
}

//队头删除
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);
	//assert(pq->phead);

	if (pq->phead->next)
	{
		QNode* tmp = pq->phead;
		pq->phead = pq->phead->next;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	
	pq->size--;
}

//查找对头数据
QDateType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->phead->val;
}

//查找队尾数据
QDateType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->val;
}

//队列长度
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

//判空
bool QueueEmpty(Queue* pq)
{
	return pq->phead == NULL;
}