Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void rearrange(struct Node *odds)
{
    // add code here
    if (odds == NULL)
        return;
    Node *odd = odds;
    Node *rev = new Node(-1);
    Node *temp = rev;
    while (odd->next != NULL && odd->next->next != NULL)
    {
        rev->next = odd->next;
        rev = rev->next;
        odd->next = odd->next->next;
        odd = odd->next;
    }
    if (odd->next == NULL)
    {
        rev->next = NULL;
        temp = reverse(temp->next);
        odd->next = temp;
    }
    else if (odd->next->next == NULL)
    {
        rev->next = odd->next;
        rev = rev->next;
        temp = reverse(temp->next);
        odd->next = temp;
    }
}