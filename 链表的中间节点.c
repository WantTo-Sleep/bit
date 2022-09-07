struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int count = 1;
    while(fast->next)
    {
        if(count)
        {
            count = 0;
            slow = slow->next;
            fast = fast->next;
        }
        else
        {
            fast = fast->next;
            count = 1;
        }
    }
    return slow;
}
