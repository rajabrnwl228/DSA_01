Node *swapkthnode(Node *head, int num, int K)
{
    // Your Code here
    if (head == NULL || head->next == NULL)
        return head;
    if (K > num)
        return head;
    if (K > num / 2)
        K = num % K + 1;
    int k = K;
    Node *first = head, *second = head;
    Node *prev2 = NULL, *prev1 = NULL;
    while (--K)
    {
        prev1 = first;
        first = first->next;
    }
    K = num - k;
    while (K--)
    {
        prev2 = second;
        second = second->next;
    }
    if (k == 1)
    {
        prev2->next = first;
        second->next = first->next;
        first->next = prev1;
        return second;
    }
    Node *ne = first->next;
    prev1->next = second;
    prev2->next = first;
    first->next = second->next;
    if (second == ne)
        second->next = first;
    else
        second->next = ne;
    return head;
}
