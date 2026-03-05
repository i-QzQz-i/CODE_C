#pragma once
//分有大堆和小堆（数据结构中的堆 != 程序中的堆）
//大堆：父节点 >= 子节点
//小堆：父节点 <= 子节点
//孩找父：(i-1)/2
//父找孩：i*2+1 or i*2+2

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//小堆实现（改几个< >符号就变为大堆实现）
//逻辑上是二叉树，但物理上是顺序表（逻辑与物理分离）
typedef int HPDateType;
typedef struct Heap
{
	HPDateType* arr;
	int size;
	int capacity;
}HP;

//创建
void HPInit(HP* php);

//销毁
void HPDestroy(HP* php);

//添加节点（运用循环）（虽然还可以使用递归，但能使用循环就不要使用递归）（递归有栈溢出的风险）
void HPPush(HP* php, HPDateType x);

//删除节点（删除堆顶的数据）(向下调整算法)
void HPPop(HP* php);

//返回堆顶元素
HPDateType HPTop(HP* php);

//判空
bool HPEmpty(HP* php);













