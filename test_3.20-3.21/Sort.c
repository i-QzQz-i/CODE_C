#define _CRT_SECURE_NO_WARNINGS 

#include "Sort.h"

// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand() + i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin7 = clock();
	//BubbleSort(a7, N);
	int end7 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	//MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("BubbleSort:%d\n", end7 - begin7);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

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
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}
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

//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int j = 0; j < gap; j++)
		{
			for (int i = j; i < n - gap; i += gap)
			{
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0)
				{
					if (tmp < a[end])
					{
						a[end + gap] = a[end];
					}
					else
					{
						break;
					}
					end -= gap;	
				}
				a[end + gap] = tmp;
			}
		}
		
		//Print(a, n);
	}	
}
//void ShellSort(int* a, int n) (无效率上的提升)
//{
//	int gap = n;
//
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//				}
//				else
//				{
//					break;
//				}
//				end -= gap;
//			}
//			a[end + gap] = tmp;
//		}
//		Print(a, n);
//	}
//}



//直接选择排序
void SelectSort(int* a, int n)
{
	int max = n - 1;
	int min = 0;
	int end = 0;

	while (min < max)
	{
		int maxi = max, mini = min;
		for (end = min + 1; end <= max; end++)
			{
				if (a[maxi] < a[mini])
				{
					Swap(&a[maxi], &a[mini]);
				}
				if (a[maxi] < a[end])
				{
					maxi = end;
				}
				if (a[mini] > a[end])
				{
					mini = end;
				}
			}

		Swap(&a[maxi], &a[max]);
		Swap(&a[mini], &a[min]);
		min++;
		max--;
	}
	

}

//向下调整
void AdjustDown(int* a, int n, int parent)
{
	//假设法
	int child = parent * 2 + 1;
	while (n > child)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			++child;
		}
		if (a[parent] < a[child])
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
//堆排序
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



//冒泡排序
void BubbleSort(int* a, int n)
{
	int i = 0;
	int j = 0;

	for (i = n; i > 0; i--)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

int GetMidi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[mid] > a[left] && a[mid] > a[right])
	{
		if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[left] > a[mid] && a[left] > a[right])
		{
			if (a[mid] > a[right])
				return mid;
			else
				return right;
		}
		if (a[right] > a[mid] && a[right] > a[left])
		{
			if (a[mid] > a[left])
				return mid;
			else
				return left;
		}
	}
	//else //a[right] < a[mid]
	//{
	//	if (a[mid] < a[left])
	//		return mid;
	//	else if (a[right] < a[left])
	//		return left;
	//	else
	//		return right;
	//}
}
//快排(霍尔方法 hoare)
int PartQSort1(int* a, int left, int right)
{
	//三数取中
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	
	int keyi = left;
	int begin = left, end = right;

	//左边取大，右边取小
	//key取左，end先走
	while (begin < end)
	{
		while (begin < end && a[keyi] <= a[end])
		{
			end--;
		}
		while (begin < end && a[keyi] >= a[begin])
		{
			begin++;
		}
	
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyi]);
	keyi = begin;
	return keyi;
}

//快排 (挖坑法)(无效率上的提升)
int PartQSort2(int* a, int left, int right);

//快排 (前后指针)(无效率上的提升)
int PartQSort3(int* a, int left, int right);

//快速排序
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	//小区间优化
	if (right - left + 1 <= 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int keyi = PartQSort1(a, left, right);
		//int keyi = PartQSort2(a, left, right);
	
		// [left, keyi-1] keyi [key+1, right]
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}
}