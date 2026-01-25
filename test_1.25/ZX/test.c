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

	//在指定位置之前插入数据
	SLInsert(pc, 4, 6);
	SLInsert(pc, 3, 0);
	SLInsert(pc, 1, 9);
	SLPrint(*pc);

	//删除指定位置的数据
	SLErase(pc, 2);
	SLPrint(*pc);


	//查找指定的数据
	SLDataType ret = SLFind(pc, 0);
	if (ret >= 0)
	{
		printf("找到了下标为：%d\n", ret);
	}
	else
	{
		printf("数据不存在\n");
	}
	

	SLDestory(pc);
}

int main()
{
	SL list;
	SLtest1(&list);





	return 0;
}