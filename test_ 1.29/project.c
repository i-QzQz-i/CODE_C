#define _CRT_SECURE_NO_WARNINGS 

//三指针（升序合并两个数组）
void merge(int* nums1, int m, int* nums2, int n)
{
    int I1 = m + n - 1;
    int I2 = m - 1;
    int I3 = n - 1;
    int i = 0;

    while (I3 >= 0 && I2 >= 0)
    {
        if (nums2[I3] > nums1[I2])
        {
            nums1[I1--] = nums2[I3--];
        }
        else if (nums2[I3] <= nums1[I2])
        {
            nums1[I1--] = nums1[I2--];
        }
    }

    while (I3 >= 0)
    {
        nums1[I1--] = nums2[I3--];
    }
}

//双指针（去除数组中的指定元素）
int removeElement(int* nums, int numsSize, int val)
{
    int* dst = nums;
    int* src = nums;
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (*dst != val)
        {
            *src = *dst;
            src++;
            dst++;
        }
        else
        {
            dst++;
        }
    }
    return (src - nums);
}

//反转链表
typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    ListNode* new1 = head;
    ListNode* new2 = head->next;
    ListNode* sbj = NULL;

    while (new1)
    {
        new1->next = sbj;
        sbj = new1;
        new1 = new2;
        if (new2 != NULL)
            new2 = new2->next;
    }

    //双指针法(快慢指针法) 2 * slow == fast
    ListNode* middleNode(ListNode * head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) //fast->next != NULL && fast != NULL 不能交换位置
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //升序合并两个链表
    typedef struct ListNode* ListNode;
    struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
        if (list2 == NULL || list1 == NULL)
        {
            if (list1)
            {
                return list1;
            }
            else
            {
                return list2;
            }
        }
        ListNode n1, n2, sbj, ret;
        n1 = list1;
        n2 = list2;
        sbj = NULL;
        if (list1->val < list2->val)
        {
            sbj = list1;
            n1 = n1->next;
        }
        else
        {
            sbj = list2;
            n2 = n2->next;
        }
        ret = sbj;
        while (n1 != NULL && n2 != NULL)
        {
            if (n1->val < n2->val)
            {
                sbj->next = n1;
                n1 = n1->next;
                sbj = sbj->next;
            }
            else
            {
                sbj->next = n2;
                n2 = n2->next;
                sbj = sbj->next;
            }
        }
        if (n1 == NULL)
        {
            sbj->next = n2;
        }
        else if (n2 == NULL)
        {
            sbj->next = n1;
        }
        return ret;
    }
