struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL)
        return NULL;
    struct Node* cur = head;
    struct Node* temp = NULL;
    // 建立好链表插在原链中
    while (cur)
    {
        struct Node* p = (struct Node*)malloc(sizeof(struct Node));
        if (p == NULL)
            return NULL;
        p->val = cur->val;
        temp = cur->next;
        cur->next = p;
        p->next = temp;
        cur = temp;
    }
    // random的链接
    cur = head;
    while (cur)
    {
        temp = cur->next;
        if (cur->random)
        {
            temp->random = cur->random->next;
        }
        else
        {
            temp->random = NULL;
        }
        cur = temp->next;
    }
    // 与原链表的分离
    struct Node* newHead = head->next;
    cur = head;
    temp = newHead;
    while (temp->next)
    {
        cur->next = temp->next;
        cur = cur->next;
        temp->next = cur->next;
        temp = temp->next;
    }
    cur->next = temp->next;
    cur = cur->next;
    return newHead;
}
