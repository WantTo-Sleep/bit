struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    int longLen = 0, shortLen = 0;
    struct ListNode* longList = headA;
    struct ListNode* shortList = headB;
    // 求出链表长度
    while (longList)
    {
        ++longLen;
        longList = longList->next;
    }
    while (shortList)
    {
        ++shortLen;
        shortList = shortList->next;
    }
    if (longLen < shortLen)
    {
        int temp = longLen;
        longLen = shortLen;
        shortLen = temp;
        longList = headB;
        shortList = headA;
    }
    else
    {
        longList = headA;
        shortList = headB;
    }
    // 长链表先走K步
    int k = longLen - shortLen;
    while (k--)
    {
        longList = longList->next;
    }
    while (shortLen--)
    {
        if (longList == shortList)
            return longList;
        longList = longList->next;
        shortList = shortList->next;
    }
    return NULL;
}
