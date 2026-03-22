#define _CRT_SECURE_NO_WARNINGS 

#include "Sort.h"

void InsertSort_Test()
{
	//int arr[] = { 1,2,0,6,8,3,9,0,5,7,4,9 };
	int arr[] = { 9,1,2,5,7,4,6,2 };
	InsertSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}
void ShellSort_Test()
{
	//int arr[] = { 1,2,0,6,8,3,9,0,5,7,4,9 };
	int arr[] = { 9,1,2,5,7,4,6,2 };
	//int arr[] = { 9,9,9,8,8,8,7,7,7,6,6,6,5,5,5,4,4,4,3,3,3,2,2,21,1,1 };
	ShellSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}


void SelectSort_Test()
{
	int arr[] = { 1,2,0,6,8,3,9,0,5,7,4,9 };
	//int arr[] = { 9,1,2,5,7,4,6,2 };
	SelectSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}
void HeapSort_Test()
{
	//int arr[] = { 1,2,0,6,8,3,9,0,5,7,4,9 };
	//int arr[] = { 9,1,2,5,7,4,6,2 };
	int arr[] = { 9,9,9,8,8,8,7,7,7,6,6,6,5,5,5,4,4,4,3,3,3,2,2,21,1,1 };
	HeapSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void BubbleSort_Test()
{
	int arr[] = { 1,2,0,6,8,3,9,0,5,7,4,9 };
	//int arr[] = { 9,1,2,5,7,4,6,2 };
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}
void QuickSort_Test()
{
	int arr[] = { 1,2,0,6,8,3,9,0,5,7,4,9 };
	//int arr[] = { 9,1,2,5,7,4,6,2 };
	//int arr[] = { 9,9,9,8,8,8,7,7,7,6,6,6,5,5,5,4,4,4,3,3,3,2,2,21,1,1 };
	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
	Print(arr, sizeof(arr) / sizeof(int));
}
void QuickSortNonR_Test()
{
	int arr[] = { 1,2,0,6,8,3,9,0,5,7,4,9 };
	//int arr[] = { 9,1,2,5,7,4,6,2 };
	//int arr[] = { 9,9,9,8,8,8,7,7,7,6,6,6,5,5,5,4,4,4,3,3,3,2,2,21,1,1 };
	QuickSortNonR(arr, 0, sizeof(arr) / sizeof(int) - 1);
	Print(arr, sizeof(arr) / sizeof(int));
}

int main()
{
	//InsertSort_Test();
	//ShellSort_Test();

	//SelectSort_Test();
	//HeapSort_Test();

	//BubbleSort_Test();
	//QuickSort_Test();
	QuickSortNonR_Test();
	

	//TestOP();

	return 0;
}