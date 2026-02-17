#define _CRT_SECURE_NO_WARNINGS 

	//相交链表，返回相交节点
//typedef struct ListNode ListNode;
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    ListNode* A = headA;
//    ListNode* B = headB;
//    int a = 0, b = 0;
//
//    while (A->next || B->next)
//    {
//        if (A->next)
//        {
//            A = A->next;
//            a++;
//        }
//        if (B->next)
//        {
//            B = B->next;
//            b++;
//        }
//    }
//
//    //假设法
//    int n = abs(a - b);
//    ListNode* longList = headA, * shortList = headB;
//    if (a < b)
//    {
//        longList = headB;
//        shortList = headA;
//    }
//
//    while (n--)
//    {
//        longList = longList->next;
//    }
//
//    while (longList != shortList)
//    {
//        longList = longList->next;
//        shortList = shortList->next;
//    }
//
//    return shortList;
//}
 
	//环形链表1，判断是否有环
//bool hasCycle(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}


	//环形链表2，返回入环节点
//struct ListNode* detectCycle(struct ListNode* head) {
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (fast == slow)
//        {
//            break;
//        }
//    }
//
//    if (fast != slow || fast == NULL || (fast == slow && fast->next == NULL))
//    {
//        return NULL;
//    }
//
//    struct ListNode* newcode = head;
//    while (newcode != fast)
//    {
//        fast = fast->next;
//        newcode = newcode->next;
//    }
//
//    return newcode;
//}