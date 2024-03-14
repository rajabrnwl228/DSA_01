Node *insertionSort(struct Node *head_ref)
{
    // code here
    if (head_ref == NULL)
        return head_ref;
    Node *second = head_ref;
    Node *dummy = new Node(-1);
    while (second != NULL)
    {
        Node *first = dummy;
        while (first->next != NULL && first->next->data < second->data)
        {
            first = first->next;
        }
        Node *t2 = second->next;
        second->next = first->next;
        first->next = second;
        second = t2;
    }
    return dummy->next;
}
