#define _CRT_SECURE_NO_WARNINGS 
	//设计循环队列
////基于数组实现（方法一）
//		////基于单链表实现////
//
//typedef struct {
//    int* arr;
//    //int val;
//    int head;//指向头
//    int tail;//指向尾的下一个
//    int k;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k) {
//    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    obj->tail = obj->head = 0;
//    obj->k = k;
//    //多开一个空间解决假溢出问题
//	  //也可以多定义一个obj->size来解决
//    obj->arr = (int*)malloc(sizeof(int) * (k + 1));
//    return obj;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
//    assert(obj);
//
//    if ((obj->tail + 1) % (obj->k + 1) != obj->head)
//    {
//        obj->arr[obj->tail] = value;
//        obj->tail = (obj->tail + 1) % (obj->k + 1);;
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj) {
//    if (obj->head != obj->tail)
//    {
//        obj->head = (obj->head + 1) % (obj->k + 1);
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//int myCircularQueueFront(MyCircularQueue* obj) {
//    if (obj->head != obj->tail)
//    {
//        return obj->arr[obj->head];
//    }
//    else
//    {
//        return -1;
//    }
//}
//
//int myCircularQueueRear(MyCircularQueue* obj) {
//    if (obj->head != obj->tail)
//    {
//        //return obj->tail == 0 ? (obj->arr[0]) : (obj->arr[obj->tail])
//        return obj->arr[(obj->tail + obj->k) % (obj->k + 1)];
//    }
//    else
//    {
//        return -1;
//    }
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
//    if (obj->head == obj->tail)
//        return true;
//    else
//        return false;
//    //return obj->head == obj->tail;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj) {
//    if ((obj->tail + 1) % (obj->k + 1) == obj->head)
//        return true;
//    else
//        return false;
//    //return (obj->tail + 1) % (obj->k + 1) == obj->head;
//}
//
//void myCircularQueueFree(MyCircularQueue* obj) {
//    assert(obj);
//    free(obj->arr);
//    obj->arr = NULL;
//    free(obj);
//    obj = NULL;
//}
//
///**
// * Your MyCircularQueue struct will be instantiated and called as such:
// * MyCircularQueue* obj = myCircularQueueCreate(k);
// * bool param_1 = myCircularQueueEnQueue(obj, value);
//
// * bool param_2 = myCircularQueueDeQueue(obj);
//
// * int param_3 = myCircularQueueFront(obj);
//
// * int param_4 = myCircularQueueRear(obj);
//
// * bool param_5 = myCircularQueueIsEmpty(obj);
//
// * bool param_6 = myCircularQueueIsFull(obj);
//
// * myCircularQueueFree(obj);
//*/