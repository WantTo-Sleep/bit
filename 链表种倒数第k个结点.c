struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    struct ListNode* slow = pListHead;
    struct ListNode* fast = pListHead;
    while (k && fast)
    {
        fast = fast->next;
        --k;
    }
    if (k) return NULL;
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
