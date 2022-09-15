bool hascycle(struct listnode* head)
{
    struct listnode* slow = head;
    struct listnode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
