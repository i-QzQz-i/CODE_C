#pragma once
//排序先实现单趟的逻辑，后在拓展到整体

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


//打印
void Print(int* a, int n);

                                                       //排序//

//冒泡排序
//时间复杂度：O(N^2)
void BubbleSort(int* a, int n);

                                                        //选择排序//

//直接选择排序
void SelectSort(int* a, int n);

//堆排序（直接建堆）（大 or 小）
//时间复杂度:O(N*logN)
void HeapSort(int* a, int n);

                                                        //插入排序//

//直接插入排序（比小向左，比大向右）
//时间复杂度：O(N^2)
void InsertSort(int* a, int n);

//希尔排序（1.预排序(让数组接近有序) 2.插入排序）
//时间复杂度：O(N^1.3)
//gap越大，大的数可以越快跳到后面，小的数可以越快跳到前面，但越不接近有序
//gap越小，跳得越慢，越不近有序，当gap == 1就相当于插入排序
//所以gap是变化的  gap = n; gap = gap / 3 + 1
void ShellSort(int* a, int n);