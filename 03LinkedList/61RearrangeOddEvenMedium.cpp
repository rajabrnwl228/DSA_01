void rearrangeEvenOdd(Node *head)
{
    // Your Code here
    Node *odd = new Node(-1);
    Node *newhead = odd;
    Node *even = new Node(-1);
    Node *e = even;
    Node *temp = head;
    while (temp != NULL)
    {
        odd->next = temp;
        odd = odd->next;
        temp = temp->next;
        if (temp != NULL)
        {
            even->next = temp;
            even = even->next;
            temp = temp->next;
        }
    }
    even->next = NULL;
    odd->next = e->next;
    head = newhead->next;
}