#define _CRT_SECURE_NO_WARNINGS 

#include"List.h"

//申请节点
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("LTBuyNode");
		exit(-1);
	}
	node->data = x;
	node->next = node->prev = node;

	return node;
}

//初始化
//void LTInit(LTNode** ps)
//{
//	//创建哨兵位
//	*ps = LTBuyNode(-1);
//}
LTNode* LTInit()
{
	LTNode* ps = LTBuyNode(-1);
	return ps;
}

//打印链表(打印哨兵位)（如果你想的话）
//void LTPrint_head(LTNode* ps)
//{
//	LTNode* code = ps;
//	do
//	{
//		printf("%d->", code->data);
//		code = code->next;
//	} while (code != ps);
//	printf("%d\n",code->data);
//}
//打印链表
void LTPrint(LTNode* ps)
{
	assert(ps);
	LTNode* code = ps->next;
	while (code != ps)
	{
		printf("%d->", code->data);
		code = code->next;
	} 
	printf("\n");
}

//查找
LTNode* LTFind(LTNode* ps, LTDataType x)
{
	assert(ps);
	LTNode* code = ps->next;
	while (code != ps)
	{
		if (code->data != x)
		{
			code = code->next;
			continue;
		}
		else
		{
			printf("找到了\n");
			return code;
		}
	}
	printf("未找到\n");
	return NULL;
}

//尾插
void LTPushBack(LTNode* ps, LTDataType x)
{
	assert(ps);
	LTNode* n1 = ps;
	//找尾
	//LTNode* ptail = n1->prev;
	LTNode* newcode = LTBuyNode(x);

	newcode->next = n1;
	newcode->prev = n1->prev;
	n1->prev->next = newcode;
	n1->prev = newcode;
}

//头插
void LTPushFront(LTNode* ps, LTDataType x)
{
	assert(ps);
	LTNode* n1 = ps;
	LTNode* newcode = LTBuyNode(x);
	
	newcode->next = n1->next;
	newcode->prev = n1;
	n1->next->prev = newcode;
	n1->next = newcode;
}

//尾删
void LTPopBack(LTNode* ps)
{
	assert(ps && ps->next != ps);
	LTNode* n1 = ps;
	LTNode* ptail = ps->prev;

	ptail->prev->next = n1;
	n1->prev = ptail->prev;

	free(ptail);
	ptail = NULL;
}

//头删
void LTPopFront(LTNode* ps)
{
	assert(ps && ps->next != ps);
	LTNode* n1 = ps;
	LTNode* phead = ps->next;

	phead->next->prev = n1;
	n1->next = phead->next;

	free(phead);
	phead = NULL;
}

//在pos位置之后插入数据
void LTInsertAfter(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newcode = LTBuyNode(x);

	newcode->next = pos->next;
	newcode->prev = pos;
	pos->next = newcode;
	newcode->next->prev = newcode;
}

//在pos位置之前插入数据
void LTInsertbefore(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newcode = LTBuyNode(x);

	newcode->next = pos;
	newcode->prev = pos->prev;
	pos->prev = newcode;
	newcode->prev->next = newcode;
}

//删除pos节点
void LTErase(LTNode* pos)
{
	//pos理论上不能为哨兵位
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(pos);
	pos = NULL;
}

//销毁链表
void LTDestory(LTNode* ps)
{
	assert(ps);
	LTNode* code = ps->next;
	while (code != ps)
	{
		LTNode* next = code->next;
		free(code);
		code = next;
	}
	free(ps);
	ps = NULL;
}