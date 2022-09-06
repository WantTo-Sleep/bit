struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    struct ListNode* cur = head;
    struct ListNode* temp = head = cur->next;
    cur->next = NULL;

    while(temp)
    {
        temp = head->next;
        head->next = cur;
        cur = head;
        head = temp;
    }
    return cur;
}
