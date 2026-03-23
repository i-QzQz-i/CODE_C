#pragma once
//基于数组实现（还可以基于单链表实现）

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int StackDateType; //栈遵循后进先出（先进后出）原则
typedef struct Stack
{
	StackDateType* arr;
	int top; //栈顶（自己定，可头可尾）
	int capacity; //数据总量
}ST;

//初始化栈
void STInis(ST* pst);

//删除栈
void STDestroy(ST* pst);

//在栈顶放入数据
void STPush(ST* pst, StackDateType x);

//在栈顶删除(弹出)数据
void STPop(ST* pst);

//取栈顶数据
StackDateType STTop(ST* pst);

//栈判空
bool STEmpty(ST* pst);

//获取数据个数
int STSize(ST* pst);


