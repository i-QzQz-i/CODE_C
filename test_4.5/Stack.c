#define _CRT_SECURE_NO_WARNINGS 

#include "Stack.h"

//初始化栈
void STInis(ST* pst)
{
	assert(pst);

	pst->arr = NULL;
	pst->capacity = 0;
	//top为数组下标
	//top指向栈顶元素的后一位
	pst->top = 0;
	//top指向栈顶元素
	//pst->top = -1;
}

//删除栈
void STDestroy(ST* pst)
{
	assert(pst);

	pst->capacity = pst->top = 0;
	
	free(pst->arr);
	pst->arr = NULL;
}

//在栈顶放入数据  (入栈)
void STPush(ST* pst, StackDateType x)
{
	assert(pst);

	int newcapacity = pst->capacity != 0 ? pst->capacity * 2 : 4;
	if (pst->top == pst->capacity)
	{
		StackDateType*tmp = (StackDateType*)realloc(pst->arr, newcapacity * sizeof(StackDateType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		else
		{
			pst->arr = tmp;
			pst->capacity = newcapacity;
		}
	}

	pst->arr[pst->top] = x;
	pst->top++;
}

//在栈顶删除(弹出)数据  (出栈)
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->arr);
	assert(pst->top > 0);

	--pst->top;
}

//取栈顶数据
StackDateType STTop(ST* pst)
{
	assert(pst);
	assert(pst->arr);
	assert(pst->top > 0);

	return pst->arr[pst->top - 1];
}

//栈判空
bool STEmpty(ST* pst)
{
	assert(pst);

	/*if (pst->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return pst->top == 0;
}

//获取数据个数
int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}