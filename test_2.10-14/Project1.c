#define _CRT_SECURE_NO_WARNINGS 

	//测试运行时间
//int n1 = clock();
//int y = 0;
//int x = 100000;
//for (int i = 0; i < x; i++)
//{
//	for (int j = 0; j < x; j++)
//	{
//		++y;
//	}
//}
//int end1 = clock();
//printf("%d ms", end1 - n1);


	//查找缺少的数字（在O(n)时间内完成）
//方法一
//int missingNumber(int* nums, int numsSize) {
//    int i = 0;
//    int sum = 0;
//    for (i = 0; i < numsSize; i++)
//    {
//        sum = sum - nums[i] + i;
//    }
//    return sum + i;
//}
//方法二(可以防止数据溢出)
//int missingNumber(int* nums, int numsSize) {
//    int i = 0;
//    int x = 0;
//
//    for (i = 0; i < numsSize; i++)
//    {
//        x ^= nums[i];
//    }
//
//    for (i = 0; i < numsSize + 1; i++)
//    {
//        x ^= i;
//    }
//
//    return x;
//}

	//轮转数组
//方法1 
//void rotate(int* nums, int numsSize, int k) {
//    int i = 0;
//    int j = 0;
//    int x = k;
//    int tmp = 0;
//
//    x %= numsSize;
//
//    for (i = 0; i < x; i++)
//    {
//        tmp = nums[numsSize - 1];
//        for (j = numsSize - 2; j >= 0; j--)
//        {
//            nums[j + 1] = nums[j];
//        }
//        nums[0] = tmp;
//    }
//}
//方法2（每一段分别逆置，在把总数组逆置）
//void Reverse(int* arr, int x, int y)
//{
//    int i = x;
//    int j = y;
//    int tmp = 0;
//
//    while (i < j)
//    {
//        tmp = arr[i];
//        arr[i++] = arr[j];
//        arr[j--] = tmp;
//    }
//
//}
//
//void rotate(int* nums, int numsSize, int k) {
//    int sz = k;
//    sz %= numsSize;
//    Reverse(nums, 0, numsSize - sz - 1);
//    Reverse(nums, numsSize - sz, numsSize - 1);
//    Reverse(nums, 0, numsSize - 1);
//}

    //返回该链表中倒数第k个结点
//typedef struct ListNode ListNode;
//int kthToLast(struct ListNode* head, int k) {
//    if (head->next == NULL)
//        return head->val;
//
//    ListNode* prev = head;
//    ListNode* pf = head;
//    int i = 0;
//    while (1)
//    {
//        for (i = 0; i < k; i++)
//        {
//            pf = pf->next;
//        }
//
//        if (pf)
//        {
//            prev = prev->next;
//            pf = prev;
//        }
//        else
//        {
//            return prev->val;
//        }
//    }
//}
//优化
//typedef struct ListNode ListNode;
//int kthToLast(struct ListNode* head, int k) {
//    ListNode* fast = head;
//    ListNode* slow = head;
//    int i = 0;
//
//    for (i = 0; i < k; i++)
//    {
//        fast = fast->next;
//    }
//    while (fast)
//    {
//        fast = fast->next;
//        slow = slow->next;
//    }
//    return slow->val;
//}

