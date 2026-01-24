#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 4

//定义动态顺序表
typedef int SLDataType;
typedef struct SqList
{
	SLDataType* arr;
	int count;
	int capacity;
}SL;

//顺序表初始化
void SLInis(SL* pc);

//顺序表销毁
void SLDestory(SL* pc);

//顺序表扩容（申请空间）
//成倍数的扩容，一般2-3倍（频繁扩容运行效率会降低）
void SLAdd(SL* pc);

//插入之前先看空间够不够
//尾插
void SLPushBack(SL* pc, SLDataType x);

//头插
void SLPushFirst(SL* pc, SLDataType x);

//顺序表的打印
void SLPrint(SL c);

//尾删
void SLPopBack(SL* pc);

//头删
void SLPopFirst(SL* pc);