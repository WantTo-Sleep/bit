struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* guard = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = guard;
    while (list1 && list2)
    {
        if(list1->val < list2->val)
        {
            cur->next = list1;
            list1 = list1->next;
        }
        else
        {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    if (list1)
        cur->next = list1;
    else
        cur->next = list2;
    cur = guard->next;
    free(guard);
    return cur;
}
