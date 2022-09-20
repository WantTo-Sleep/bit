struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL)
        return NULL;
    struct Node* cur = head;
    struct Node* temp = NULL;
    // �������������ԭ����
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
    // random������
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
    // ��ԭ����ķ���
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
