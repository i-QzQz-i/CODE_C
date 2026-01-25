#define _CRT_SECURE_NO_WARNINGS 

#include "test.h"

//顺序表初始化
void SLInis(SL* pc)
{
	pc->arr = (SL*)calloc(MAX,sizeof(SLDataType));
	pc->count = 0;
	pc->capacity = MAX;
}

//顺序表销毁
void SLDestory(SL* pc)
{
	assert(pc);
	if (pc->arr)
	{
		free(pc->arr);
	}
	pc->arr = NULL;
	pc->count = pc->capacity = 0;
}

//顺序表扩容（申请空间）
void SLAdd(SL* pc)
{
	assert(pc);
	if (pc->count == pc->capacity)
	{
		int newCapacity = pc->capacity * 2;
		SLDataType* str = (SLDataType*)realloc(pc->arr, sizeof(SLDataType) * newCapacity);
		if (str != NULL)
		{
			pc->arr = str;
			pc->capacity = newCapacity;
			printf("扩容成功\n");
			str = NULL;
		}
		else
		{
			perror("SLAdd");
			exit(-1);
		}
	}
}

//尾插
void SLPushBack(SL* pc, SLDataType x)
{
	assert(pc);
	SLAdd(pc);
	pc->arr[pc->count++] = x;
}

//头插
void SLPushFirst(SL* pc, SLDataType x)
{
	assert(pc);
	SLAdd(pc);
	int i = 0;
	for (i = pc->count - 1; i >= 0; i--)
	{
		pc->arr[i + 1] = pc->arr[i];
	}
	pc->arr[0] = x;
	pc->count++;
}

//顺序表的打印
void SLPrint(SL c)
{
	int i = 0;
	for (i = 0; i < c.count; i++)
	{
		printf("%d ", c.arr[i]);
	}
	printf("\n");
}

//尾删
void SLPopBack(SL* pc)
{
	assert(pc);
	pc->count--;
}

//头删
void SLPopFirst(SL* pc)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count - 1; i++)
	{
		pc->arr[i] = pc->arr[i + 1];
	}
	pc->count--;
}

//在指定位置插入数据
void SLInsert(SL* pc, int pos, SLDataType x)
{
	assert(pc);
	assert(pos >= 0 && pos <= pc->count + 1);
	SLAdd(pc);
	int i = 0;
	for (i = pc->count; i >= pos - 1; i--)
	{
		pc->arr[i] = pc->arr[i - 1];
	}
	pc->arr[pos - 1] = x;
	pc->count++;
}

//删除指定位置的数据
void SLErase(SL* pc, int pos)
{
	assert(pc);
	assert(pos >= 0 && pos <= pc->count);
	int i = 0;
	for (i = pos - 1; i < pc->count; i++)
	{
		pc->arr[i] = pc->arr[i + 1];
	}

	pc->count--;
}

//查找指定的数据
SLDataType SLFind(SL* pc, SLDataType x)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (pc->arr[i] == x)
		{
			return i;
		}
	}

	return -1;
}
