#define _CRT_SECURE_NO_WARNINGS 

	//随机链表的复制（深拷贝）
//typedef struct Node Node;
//struct Node* copyRandomList(struct Node* head) {
//    {
//        if (head == NULL)
//            return NULL;
//    }
//    Node* pcur = head;
//    //把拷贝节点开辟在原链表之后
//    while (pcur)
//    {
//        Node* newcode = (Node*)malloc(sizeof(Node));
//        newcode->val = pcur->val;
//        newcode->next = pcur->next;
//
//        pcur->next = newcode;
//        pcur = newcode->next;
//    }
//
//    Node* newhead = head->next;
//    pcur = head;
//    //拷贝random
//    while (pcur)
//    {
//        if (pcur->random != NULL)
//        {
//            newhead->random = pcur->random->next;
//        }
//        else
//        {
//            newhead->random = NULL;
//        }
//
//        pcur = pcur->next->next;
//        if (pcur)
//            newhead = pcur->next;
//    }
//
//    newhead = head->next;
//    Node* new = (Node*)malloc(sizeof(Node));
//    new->next = NULL;
//    Node* plist = new;
//    pcur = head;
//    //取下拷贝节点尾插，并恢复原链表
//    while (pcur)
//    {
//        pcur->next = newhead->next;
//        pcur = pcur->next;
//
//        plist->next = newhead;
//        plist = plist->next;
//        if (pcur)
//            newhead = pcur->next;
//    }
//    Node* ret = new->next;
//    free(new);
//    new = NULL;
//    return ret;
//}
	//略微修改
//typedef struct Node Node;
//struct Node* copyRandomList(struct Node* head) {
//    {
//        if (head == NULL)
//            return NULL;
//    }
//    Node* pcur = head;
//    //把拷贝节点开辟在原链表之后
//    while (pcur)
//    {
//        Node* newcode = (Node*)malloc(sizeof(Node));
//        newcode->val = pcur->val;
//        newcode->next = pcur->next;
//
//        pcur->next = newcode;
//        pcur = newcode->next;
//    }
//
//    pcur = head;
//    //拷贝random
//    while (pcur)
//    {
//        Node* newhead = pcur->next;
//
//        if (pcur->random != NULL)
//        {
//            newhead->random = pcur->random->next;
//        }
//        else
//        {
//            newhead->random = NULL;
//        }
//
//        pcur = pcur->next->next;
//    }
//
//    Node* new = (Node*)malloc(sizeof(Node));
//    new->next = NULL;
//    Node* plist = new;
//    pcur = head;
//    //取下拷贝节点尾插，并恢复原链表
//    while (pcur)
//    {
//        Node* newhead = pcur->next;
//        pcur->next = newhead->next;
//        pcur = pcur->next;
//
//        plist->next = newhead;
//        plist = plist->next;
//    }
//
//    Node* ret = new->next;
//    free(new);
//    new = NULL;
//    return ret;
//}