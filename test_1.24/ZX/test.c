#define _CRT_SECURE_NO_WARNINGS 

#include "test.h"


void SLtest1(SL* pc)
{
	SLInis(pc);

	//增 删 查 改 操作
	//
	//测试
	//尾插
	SLPushBack(pc, 1);
	SLPushBack(pc, 1);
	SLPushBack(pc, 3);
	SLPushBack(pc, 3);
	SLPrint(*pc);
	 
	//头插
	SLPushFirst(pc, 5);
	SLPushFirst(pc, 0);
	SLPushFirst(pc, 4);
	SLPrint(*pc);
	//尾删
	SLPopBack(pc);
	SLPopBack(pc);
	SLPrint(*pc);
	//头删
	SLPopFirst(pc);
	SLPopFirst(pc);
	SLPrint(*pc);

	SLDestory(pc);
}

int main()
{
	SL list;
	SLtest1(&list);





	return 0;
}