#define _CRT_SECURE_NO_WARNINGS  

#include "SeqList.h"

//void SLTest1()
//{
//	//创建链表
//	SL* node1 = (SL*)malloc(sizeof(SL));
//	node1->data = 1;
//
//	SL* node2 = (SL*)malloc(sizeof(SL));
//	node2->data = 2;
//
//	SL* node3 = (SL*)malloc(sizeof(SL));
//	node3->data = 3;
//
//	SL* node4 = (SL*)malloc(sizeof(SL));
//	node4->data = 4;
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	SL* plist = node1;
//	SLPrint(plist);
//}

//void SLTest2()
//{
//
//	//SL* ret = SLBuyNode(1);
//	SL* ret = NULL;
//	SLPrint(ret);
//	SLPushBack(&ret, 1);
//	SLPrint(ret);
//	SLPushBack(&ret, 2);
//	SLPrint(ret);
//	SLPushBack(&ret, 3);
//	SLPrint(ret);
//
//	SLPush(&ret, 0);
//	SLPrint(ret);
//
//	//SLPopBack(&ret);
//	//SLPrint(ret);
//	//SLPopBack(&ret);
//	//SLPrint(ret);
//	//SLPopBack(&ret);
//	//SLPrint(ret);
//	//SLPopBack(&ret);
//	//SLPrint(ret);
//
//	SLPopFront(&ret);
//	SLPrint(ret);
//	SLPopFront(&ret);
//	SLPrint(ret);
//	SLPopFront(&ret);
//	SLPrint(ret);
//	SLPopFront(&ret);
//	SLPrint(ret);
//}

void SLTest3()
{
	SL* plist = NULL;
	SLPushBack(&plist, 1);
	SLPushBack(&plist, 2);
	SLPushBack(&plist, 3);
	SLPushBack(&plist, 4);
	SLPrint(plist);

	SL* ret = SLFind(plist, 1);
	if (ret)
	{
		printf("找到了\n");
	}
	else
	{
		printf("未找到\n");
	}

	//SLTInsert(&plist, ret, 0);
	// SLTInsertAfter(ret, 0);
	

	//SLTErase(&plist, ret);
	//SLTEraseAfter(ret);

	//SLTAllEraseAfter(ret);
	SLTDestroy(&plist);
	SLPrint(plist);
}

int main()
{
	//SLTest1();
	//SLTest2();
	SLTest3();

	return 0;
}