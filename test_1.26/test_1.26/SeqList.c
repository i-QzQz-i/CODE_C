#define _CRT_SECURE_NO_WARNINGS 

#include "SeqList.h"

//申请新节点
SL* SLBuyNode(SLDate x)
{
	SL* ps = (SL*)malloc(sizeof(SL));
	if (ps != NULL)
	{
		ps->data = x;
		ps->next = NULL;
	}
	else
	{
		perror("malloc fail!");
		exit(-1);
	}
	
	return ps;
}

//打印链表
void SLPrint(SL* ps)
{
	//assert(ps);
	SL* pcur = ps;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//尾插
void SLPushBack(SL** pps, SLDate x)
{
	assert(pps);
	SL* newcode = SLBuyNode(x);
	
	//空链表
	if (*pps == NULL)
	{
		*pps = newcode;
		return;
	}
	//非空链表
	//找尾
	SL* tmp = *pps;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = newcode;
}

//头插
void SLPush(SL** pps, SLDate x)
{
	assert(pps);
	SL* newcode = SLBuyNode(x);
	//空链表
	if (*pps == NULL)
	{
		*pps = newcode;
		return;
	}
	//非空链表
	//SL* tmp = *pps;
	newcode->next = *pps;
	*pps = newcode;
}

//尾删
void SLPopBack(SL** pps)//（只有一个节点与有多个节点）
{
	assert(pps && *pps);
	//只有一个节点
	if ((*pps)->next == NULL)//-> 优先级高于 *
	{
		free(*pps);
		*pps = NULL;
		pps = NULL;
		return;
	}
	//有多个节点
	SL* tmp1 = *pps;
	SL* tmp2 = *pps;
	while (tmp1->next)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	free(tmp1);
	tmp1 = NULL;
	tmp2->next = NULL;
}

//头删
void SLPopFront(SL** pps)
{
	assert(pps && *pps);
	SL* tmp = (*pps)->next;
	
	//只有一个节点
	if (tmp == NULL)//-> 优先级高于 *
	{
		free(*pps);
		*pps = NULL;
		pps = NULL;
		return;
	}
	//有多个节点
	free(*pps);
	*pps = tmp;
}