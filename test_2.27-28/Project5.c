#define _CRT_SECURE_NO_WARNINGS 

	//用两个队列实现栈（进阶：只用一个）
//typedef int QDateType;
//typedef struct QueueNode
//{
//	QDateType val;
//	struct QueueNode* next;
//}QNode;
////头和尾是相同类型的数据可新建结构体来储存 //想一想能不能用结构体指针数组储存
//typedef struct Queue
//{
//	QNode* phead;
//	QNode* ptail;
//	int size;
//}Queue;
//
////队列初始化
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//
//	pq->phead = NULL;
//	pq->ptail = NULL;
//	pq->size = 0;
//}
//
////销毁释放
//void QueueDestory(Queue* pq)
//{
//	//assert(pq);
//	//assert(pq->phead);
//
//	QNode* pcur = pq->phead;
//	while (pcur)
//	{
//		pq->phead = pq->phead->next;
//		free(pcur);
//		pcur = pq->phead;
//	}
//}
//
////队尾插入
//void QueuePush(Queue* pq, QDateType x)
//{
//	assert(pq);
//
//	QNode* new = (QNode*)malloc(sizeof(QNode));
//
//	if (new == NULL)
//	{
//		perror("malloc error");
//		return;
//	}
//	new->next = NULL;
//	new->val = x;
//
//	if (pq->phead == NULL)
//	{
//		pq->phead = pq->ptail = new;
//	}
//	else
//	{
//		pq->ptail->next = new;
//		pq->ptail = new;
//	}
//
//	pq->size++;
//}
//
////队头删除
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(pq->size != 0);
//	//assert(pq->phead);
//
//	if (pq->phead->next)
//	{
//		QNode* tmp = pq->phead;
//		pq->phead = pq->phead->next;
//		free(tmp);
//		tmp = NULL;
//	}
//	else
//	{
//		free(pq->phead);
//		pq->phead = pq->ptail = NULL;
//	}
//
//	pq->size--;
//}
//
////查找对头数据
//QDateType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(pq->phead);
//
//	return pq->phead->val;
//}
//
////查找队尾数据
//QDateType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(pq->ptail);
//
//	return pq->ptail->val;
//}
//
////队列长度
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//
//	return pq->size;
//}
//
////判空
//bool QueueEmpty(Queue* pq)
//{
//	return pq->phead == NULL;
//}
//
//typedef struct {
//	Queue pq;
//} MyStack;
//
////队列倒,尾变头
//void Reverse(MyStack* obj)
//{
//	if (QueueSize((&obj->pq)) <= 1)
//	{
//		return;
//	}
//	int x = QueueSize((&obj->pq)) - 1;
//	while (x--)
//	{
//		QDateType tmp = QueueFront(&(obj->pq));
//		//队尾插入
//		QueuePush(&(obj->pq), tmp);
//		//队头删除
//		QueuePop(&(obj->pq));
//	}
//}
//
//MyStack* myStackCreate() {
//	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//	QueueInit(&(obj->pq));
//	return obj;
//}
//
//void myStackPush(MyStack* obj, int x) {
//	assert(obj);
//	QueuePush(&(obj->pq), x);
//}
//
//int myStackPop(MyStack* obj) {
//	assert(obj);
//
//	int ret = QueueBack(&(obj->pq));
//	Reverse(obj);
//	QueuePop(&(obj->pq));
//	return ret;
//}
//
//int myStackTop(MyStack* obj) {
//	assert(obj);
//	return QueueBack(&(obj->pq));
//}
//
//bool myStackEmpty(MyStack* obj) {
//	assert(obj);
//	return QueueEmpty(&(obj->pq));
//}
//
//void myStackFree(MyStack* obj) {
//	assert(obj);
//	QueueDestory(&(obj->pq));
//
//	free(obj);
//}
//
///**
// * Your MyStack struct will be instantiated and called as such:
// * MyStack* obj = myStackCreate();
// * myStackPush(obj, x);
//
// * int param_2 = myStackPop(obj);
//
// * int param_3 = myStackTop(obj);
//
// * bool param_4 = myStackEmpty(obj);
//
// * myStackFree(obj);
//*/



	//用两个栈实现队列（进阶：实现每个操作均摊时间复杂度为 O(1)的队列）
//typedef int StackDateType; //栈遵循后进先出（先进后出）原则
//typedef struct Stack
//{
//    StackDateType* arr;
//    int top; //栈顶（自己定，可头可尾）
//    int capacity; //数据总量
//}ST;
//
////初始化栈
//void STInis(ST* pst)
//{
//    assert(pst);
//
//    pst->arr = NULL;
//    pst->capacity = 0;
//    //top为数组下标
//    //top指向栈顶元素的后一位
//    pst->top = 0;
//    //top指向栈顶元素
//    //pst->top = -1;
//}
//
////删除栈
//void STDestroy(ST* pst)
//{
//    assert(pst);
//
//    pst->capacity = pst->top = 0;
//
//    free(pst->arr);
//    pst->arr = NULL;
//}
//
////在栈顶放入数据  (入栈)
//void STPush(ST* pst, StackDateType x)
//{
//    assert(pst);
//
//    int newcapacity = pst->capacity != 0 ? pst->capacity * 2 : 4;
//    if (pst->top == pst->capacity)
//    {
//        StackDateType* tmp = (StackDateType*)realloc(pst->arr, newcapacity * sizeof(StackDateType));
//        if (tmp == NULL)
//        {
//            perror("realloc fail");
//            exit(-1);
//        }
//        else
//        {
//            pst->arr = tmp;
//            pst->capacity = newcapacity;
//        }
//    }
//
//    pst->arr[pst->top] = x;
//    pst->top++;
//}
//
////在栈顶删除(弹出)数据  (出栈)
//void STPop(ST* pst)
//{
//    assert(pst);
//    assert(pst->arr);
//    assert(pst->top > 0);
//
//    --pst->top;
//}
//
////取栈顶数据
//StackDateType STTop(ST* pst)
//{
//    assert(pst);
//    assert(pst->arr);
//    assert(pst->top > 0);
//
//    return pst->arr[pst->top - 1];
//}
//
////栈判空
//bool STEmpty(ST* pst)
//{
//    assert(pst);
//    return pst->top == 0;
//}
//
////获取数据个数
//int STSize(ST* pst)
//{
//    assert(pst);
//
//    return pst->top;
//}
//
//typedef struct {
//    ST s1;
//    ST s2;
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
//
//    STInis(&(obj->s1));
//    STInis(&(obj->s2));
//    return obj;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//    assert(obj);
//    if ((&obj->s1)->top != 0)
//    {
//        // while((&obj->s1)->top)
//        // {
//        //     STPush(&obj->s2, (&obj->s1)->arr[(&obj->s1)->top - 1]);
//        //     STPop(&obj->s1);
//        // }
//        STPush(&obj->s1, x);
//    }
//    else
//    {
//        // while((&obj->s2)->top)
//        // {
//        //     STPush(&obj->s1, (&obj->s2)->arr[(&obj->s2)->top - 1]);
//        //     STPop(&obj->s2);
//        // }
//        STPush(&obj->s2, x);
//    }
//}
//
//int myQueuePop(MyQueue* obj) {
//    assert(obj);
//    int ret = 0;
//    if ((&obj->s1)->top)
//    {
//        while ((&obj->s1)->top)
//        {
//            STPush(&obj->s2, (&obj->s1)->arr[(&obj->s1)->top - 1]);
//            STPop(&obj->s1);
//        }
//        ret = STTop(&obj->s2);
//        STPop(&obj->s2);
//        while ((&obj->s2)->top)
//        {
//            STPush(&obj->s1, (&obj->s2)->arr[(&obj->s2)->top - 1]);
//            STPop(&obj->s2);
//        }
//    }
//    else
//    {
//        while ((&obj->s2)->top)
//        {
//            STPush(&obj->s1, (&obj->s2)->arr[(&obj->s2)->top - 1]);
//            STPop(&obj->s2);
//        }
//        ret = STTop(&obj->s1);
//        STPop(&obj->s1);
//        while ((&obj->s1)->top)
//        {
//            STPush(&obj->s2, (&obj->s1)->arr[(&obj->s1)->top - 1]);
//            STPop(&obj->s1);
//        }
//    }
//
//    return ret;
//}
//
//int myQueuePeek(MyQueue* obj) {
//    assert(obj);
//    if ((&obj->s1)->top != 0)
//    {
//        return (&obj->s1)->arr[0];
//    }
//    else
//    {
//        return (&obj->s2)->arr[0];
//    }
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//    assert(obj);
//    if ((&obj->s1)->top || (&obj->s2)->top)
//        return false;
//    else
//        return true;
//}
//
//void myQueueFree(MyQueue* obj) {
//    assert(obj);
//
//    STDestroy(&obj->s1);
//    STDestroy(&obj->s2);
//    free(obj);
//}
//
///**
// * Your MyQueue struct will be instantiated and called as such:
// * MyQueue* obj = myQueueCreate();
// * myQueuePush(obj, x);
//
// * int param_2 = myQueuePop(obj);
//
// * int param_3 = myQueuePeek(obj);
//
// * bool param_4 = myQueueEmpty(obj);
//
// * myQueueFree(obj);
//*/