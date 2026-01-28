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
	*pps = tmp;//*pps = (*pps)->next;
}

//查找
SL* SLFind(SL* ps, SLDate x)
{
	assert(ps);
	SL* tmp = ps;
	while (tmp)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return tmp;
}

//在指定位置之前插入数据
void SLTInsert(SL** pps, SL* pos, SLDate x)
{
	assert(pps && *pps && pos);
	SL* newcode = SLBuyNode(x);
	SL* tmp = *pps;
	if (tmp == pos)
	{
		//头插
		//SLPush(pps , x);
		newcode->next = *pps;
		*pps = newcode;
		return;
	}
	//找到指定位置的前一位
	while (tmp->next != pos)
	{
		tmp = tmp->next;
	}
	tmp->next = newcode;
	newcode->next = pos;
}

//在指定位置之后插入数据
void SLTInsertAfter(SL* pos, SLDate x)
{
	assert(pos);
	SL* newcode = SLBuyNode(x);
	newcode->next = pos->next;
	pos->next = newcode;
}

//删除pos节点
void SLTErase(SL** pps, SL* pos)
{
	assert(pps && *pps && pos);

	if (*pps == pos)
	{
		//头删
		//SLPopFront(pps);
		SL* tmp1 = (*pps)->next;
		free(*pps);
		*pps = tmp1;
		return;
	}
	//找到pos的前一位
	SL* tmp2 = *pps;
	while (tmp2->next != pos)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = pos->next;
	free(pos);
	pos = NULL;
}

//删除pos之后的节点
void SLTEraseAfter(SL* pos)
{
	assert(pos && pos->next);
	SL* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
	tmp = NULL;
}

//删除pos之后的所有节点
void SLTAllEraseAfter(SL* pos)
{
	assert(pos && pos->next);
	SL* tmp1 = pos;
	SL* tmp2 = pos;
	while (tmp2)
	{
		tmp2 = tmp2->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	
	pos->next = NULL;
}

//销毁链表
void SLTDestroy(SL** pps)
{
	assert(pps && *pps);
	SL* tmp1 = *pps;
	SL* tmp2 = *pps;
	while (tmp1)
	{
		tmp2 = tmp2->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	*pps = NULL;
}


