#define _CRT_SECURE_NO_WARNINGS 

#include"List.h"

void ListTest1()
{
	/*LTNode* plist = NULL;
	LTInit(&plist);*/
	LTNode* plist = LTInit();
	//LTPrint_head(plist);

	LTPushBack(plist, 1);
	LTPrint(plist);
	LTPushBack(plist, 2);
	LTPrint(plist);
	LTPushBack(plist, 3);
	LTPrint(plist);
	LTPushBack(plist, 4);
	LTPrint(plist);

	LTPushFront(plist, 0);
	LTPrint(plist);
	LTPushFront(plist, -1);
	LTPrint(plist);

	//LTPopBack(plist);
	//LTPrint(plist);
	//LTPopBack(plist);
	//LTPrint(plist);

	LTPopFront(plist);
	LTPrint(plist);
	LTPopFront(plist);
	LTPrint(plist);

}

void ListTest2()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPrint(plist);

	LTNode* ret = LTFind(plist, 1);
	//LTInsertAfter(ret, 66);
	//LTPrint(plist);

	//LTInsertbefore(ret, 99);
	//LTPrint(plist);

	LTErase(ret);
	ret = NULL;
	//LTPrint(plist);

	//Ïú»ÙÁ´±í
	LTDestory(plist);
	plist = NULL;
}

int main()
{
	//ListTest1();
	ListTest2();

	return 0;
}