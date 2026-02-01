#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//定义双向链表节点的结构
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//
//声明双向链表中提供的方法
//

//初始化
//void LTInit(LTNode** ps);
LTNode* LTInit();

//打印链表
void LTPrint(LTNode* ps);
//void LTPrint_head(LTNode* ps);

//查找
LTNode* LTFind(LTNode* ps, LTDataType x);

//插入数据，链表必须初始化到只有一个头节点的情况(至少要有一个哨兵位)
//因为不改变哨兵位的地址，所以传一级即可

//尾插
void LTPushBack(LTNode* ps, LTDataType x);

//头插
void LTPushFront(LTNode* ps, LTDataType x);

//尾删
void LTPopBack(LTNode* ps);

//头删
void LTPopFront(LTNode* ps);

//在pos位置之后插入数据
void LTInsertAfter(LTNode* pos, LTDataType x);

//在pos位置之前插入数据
void LTInsertbefore(LTNode* pos, LTDataType x);

//其实应该传二级指针**pos(为了把*pos = NULL)，为了保持接口一致性
//解决方法：手动置为空
//删除pos节点
void LTErase(LTNode* pos);

//销毁链表
void LTDestory(LTNode* ps);