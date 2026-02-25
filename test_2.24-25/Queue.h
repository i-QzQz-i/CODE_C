#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDateType;
typedef struct QueueNode
{
	QDateType val;
	struct QueueNode* next;
}QNode;
//头和尾是相同类型的数据可新建结构体来储存 //想一想能不能用结构体指针数组储存
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
}Queue;

//队列初始化
void QueueInit(Queue* pq);
//销毁释放
void QueueDestory(Queue* pq);

////队尾插入
//void QueuePush(QU* phead, QU* ptail, QDateType x);
////队头删除
//void QueuePop(QU* phead, QU* ptail);

//队尾插入
void QueuePush(Queue* pq, QDateType x);
//队头删除
void QueuePop(Queue* pq);

//查找对头数据
QDateType QueueFront(Queue* pq);
//查找队尾数据
QDateType QueueBack(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);