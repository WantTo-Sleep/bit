struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int slowLen = 0;
    int fastLen = 0;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        slowLen += 1;
        fastLen += 2;
        if (slow == fast)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return NULL;
    // 一个从相遇点走，一个从头走，会在入口相遇
    slow = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
