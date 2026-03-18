#define _CRT_SECURE_NO_WARNINGS 

#include "Sort.h"

//打印
void Print(int* a, int n)
{
	for (int x = 0; x < n; x++)
	{
		printf("%d ", a[x]);
	}

	printf("\n");
}

//交换
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//直接插入排序

//void InsertSort(int* a, int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < n; i++)
//	{
//		int tmp = a[i];
//		
//		for (j = i; ; j--)
//		{
//			if (tmp < a[j - 1])
//			{
//				a[j] = a[j - 1];
//			}
//			else
//			{
//				a[j] = tmp;
//				break;
//			}
//		}
//	}
//}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
			}
			else
			{
				a[end + 1] = tmp;
				break;
			}

			end--;
		}
	}
}

//向下调整
void AdjustDown(int* a, int n, int parent)
{
	//假设法
	int child = parent * 2 + 1;
	while (n > child)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			++child;
		}
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//排降序，建小堆
	//排升序，建大堆

	//向下调整建堆  O(N)
	//节点数量多的层*调整次数少
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//  O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end--, 0);
	}
}
