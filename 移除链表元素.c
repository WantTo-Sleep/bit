struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* cur = head;
    if (cur == NULL)
        return cur;
    while (cur->next)
    {
        if (cur->next->val == val)
        {
            struct ListNode* temp = cur->next->next;
            free(cur->next);
            cur->next = temp;
        }
        else
            cur = cur->next;
    }
    if (head->val == val)
    {
        cur = head->next;
        free(head);
        head = cur;
    }
    return head;
}
