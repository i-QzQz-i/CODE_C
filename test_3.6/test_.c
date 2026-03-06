#define _CRT_SECURE_NO_WARNINGS 

#include "Heap.h"

void test1()
{
	HP h;
	HPInit(&h);

	int arr[] = { 1,3,9,66,4,2,5,44,55,33 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		HPPush(&h, arr[i]);
	}
	
	while (h.size)
	{
		int a = HPTop(&h);
		printf("%d ", a);
		HPPop(&h);
	}
	

	HPDestroy(&h);
}

void test2()
{
	int arr[] = { 1,2,5,7,9,6,0,5,9 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
}

int main()
{
	test1();
	test2();

	return 0;
}