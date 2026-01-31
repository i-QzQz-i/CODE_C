#define _CRT_SECURE_NO_WARNINGS 

//分割链表
//方法1
typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL)
    {
        return NULL;
    }
    ListNode* new_Small = (ListNode*)malloc(sizeof(ListNode));
    ListNode* new_Big = (ListNode*)malloc(sizeof(ListNode));
    ListNode* pcur = head;
    ListNode* n1 = new_Small;
    ListNode* n2 = new_Big;
    while (pcur)
    {
        if (pcur->val < x)
        {
            n1->next = pcur;
            n1 = n1->next;
        }
        else
        {
            n2->next = pcur;
            n2 = n2->next;
        }
        pcur = pcur->next;
    }
    n2->next = NULL;
    n1->next = new_Big->next;
    return new_Small->next;
}
//方法2
typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
    if (head == NULL)
    {
        return NULL;
    }
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    new->next = head;
    ListNode* pcur = head;
    ListNode* prev = new;
    ListNode* ptail = head;
    //
    while (ptail->next != NULL)
    {
        ptail = ptail->next;
    }
    ListNode* n1 = ptail;

    while (pcur != ptail)
    {
        if (pcur->val < x)
        {
            prev = pcur;
            pcur = pcur->next;
        }
        else
        {
            n1->next = pcur;
            n1 = n1->next;
            prev->next = pcur->next;
            pcur = pcur->next;
        }
    }
    n1->next = NULL;
    return new->next;
}

//环形链表的约瑟夫问题
typedef struct ListNode ListNode;
ListNode* BuyCode(int x)
{
    ListNode* ps, * pcur;
    ps = pcur = (ListNode*)malloc(sizeof(ListNode));;
    int i = 0;
    for (i = 1; i <= x; i++)
    {
        pcur->next = (ListNode*)malloc(sizeof(ListNode));
        pcur = pcur->next;
        pcur->val = i;
    }
    pcur->next = ps->next;
    return pcur;
}
void Destroy(ListNode* prev)
{
    prev->next = prev->next->next;
}
int ysf(int n, int m) {
    // write code here
    ListNode* newcode = BuyCode(n);
    ListNode* pcur = newcode->next;
    ListNode* prev = newcode;
    int i = 1;
    while (pcur != pcur->next)
    {

        if (i == m)
        {
            Destroy(prev);
            i = 1;
            pcur = pcur->next;
            continue;
        }
        pcur = pcur->next;
        prev = prev->next;
        i++;
    }
    return pcur->val;
}
