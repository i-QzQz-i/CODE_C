#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//定义链表节点结构
typedef int SLDate;
typedef struct SListNode //单链表
{
	SLDate data;//数据

	struct SListNode* next;//指向下一个节点的指针
}SL;

//申请新节点
SL* SLBuyNode(SLDate x);

//打印链表
void SLPrint(SL* ps);

//尾插
void SLPushBack(SL** pps, SLDate x);

//头插
void SLPush(SL** pps, SLDate x);

//尾删
void SLPopBack(SL** pps);//（只有一个节点与有多个节点）

//头删
void SLPopFront(SL** pps);
