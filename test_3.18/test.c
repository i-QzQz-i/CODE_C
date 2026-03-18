#define _CRT_SECURE_NO_WARNINGS 

#include "Sort.h"

void InsertSort_Test()
{
	int arr[] = { 1,2,0,6,8,3,9,0,5,7,4,9 };
	InsertSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

void HeapSort_Test()
{
	int arr[] = { 1,2,0,6,8,3,9,0,5,7,4,9 };
	HeapSort(arr, sizeof(arr) / sizeof(int));
	Print(arr, sizeof(arr) / sizeof(int));
}

int main()
{
	//InsertSort_Test();
	HeapSort_Test();

	return 0;
}