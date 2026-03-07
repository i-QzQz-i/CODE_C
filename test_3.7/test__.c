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

//Top-k 问题
void test3()
{
	printf("请输入k的值 >>> ");
	int k = 0;
	scanf("%d", &k);
	int* kxd = (int*)malloc(sizeof(int) * k);
	/*int arr[20];
	srand(time(0));
	for (size_t i = 0; i < 20; ++i)
	{
		arr[i] = rand() % 1000 + i;
	}*/

	//造值
	int arr[60];
	for (int i = 0; i < 60; i++)
	{
		arr[i] = i;
	}
	arr[5] = 1000000 + 1;
	arr[1] = 1000000 + 2;
	arr[31] = 1000000 + 3;
	arr[21] = 1000000 + 4;
	arr[15] = 1000000 + 5;
	arr[23] = 1000000 + 6;
	arr[59] = 1000000 + 7;
	arr[36] = 1000000 + 8;
	arr[55] = 1000000 + 9;
	arr[39] = 1000000 + 10;

	//建一个k个值的小堆
	for (int i = 0; i < k; i++)
	{
		kxd[i] = arr[i];
	}
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(kxd, k, i);
	}

	//读取剩下的N-k个数
	for (int i = k; i < 60; i++)
	{
		if (arr[i] > kxd[0])
		{
			kxd[0] = arr[i];
			AdjustDown(kxd, k, 0);
		}
	}

	//打印k小堆
	for(int i = 0; i < k; i++)
	{
		printf("%d ", kxd[i]);
	}
}

int main()
{
	test1();
	//test2();
	printf("\n");
	test3();

	return 0;
}