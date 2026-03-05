#define _CRT_SECURE_NO_WARNINGS 

#include "Heap.h"

void test1()
{
	HP h;
	HPInit(&h);

	int arr[] = { 1,3,9,4,20,33,46,10,6 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		HPPush(&h, arr[i]);
	}
	






	HPDestroy(&h);
}

int main()
{
	test1();

	return 0;
}