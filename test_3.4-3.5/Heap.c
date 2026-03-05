#define _CRT_SECURE_NO_WARNINGS 

#include "Heap.h"

void HPInit(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

void HPDestroy(HP* php)
{
	assert(php);
	free(php->arr);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

	//交换
void Swap(HPDateType* p1, HPDateType* p2)
{
	HPDateType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
	//向上调整
void AdjustUP(HPDateType* arr, int child)
{
		//循环三要素
	//初始条件
	//中间过程
	//结束条件
	while (child > 0)
	{
		int parent = (child - 1) / 2;
		if (arr[parent] > arr[child])
		{
			Swap(&arr[parent], &arr[child]);
		}
		else
		{
			break;
		}
		child = parent;
	}
}

void HPPush(HP* php, HPDateType x)
{
	assert(php);
	//判断空间是否足够
	int newcapacity = php->capacity != 0 ? php->capacity * 2 : 4;
	if (php->size == php->capacity)
	{
		HPDateType* tmp = (HPDateType*)realloc(php->arr, newcapacity * sizeof(HPDateType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		else
		{
			php->arr = tmp;
			php->capacity = newcapacity;
		}
	}
	//与Push新节点的祖宗节点相比
	AdjustUP(php->arr, x);

	php->arr[php->size] = x;
	php->size++;
}

	//向下调整
void AdjustDown(HPDateType* arr, int n, int parent)
{
	//假设法
	int child = parent * 2 + 1;
	while (n > child)
	{
		if (child + 1 <= n && arr[child] > arr[child + 1])
		{
			++child;
		}
		Swap(&arr[parent], &arr[child]);
		parent = child;
		child = parent * 2 + 1;
	}
	
}
void HPPop(HP* php)
{
	assert(php);
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	php->size--;

	AdjustDown(php->arr, php->size, 0);
}

HPDateType HPTop(HP* php)
{
	assert(php);

	return php->arr[0];
}

bool HPEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}




