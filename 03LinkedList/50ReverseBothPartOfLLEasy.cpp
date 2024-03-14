Node *reverse(Node *head, int k)
{
    // code here
    Node *c = head;
    Node *p = NULL, *n = NULL;
    while (k--)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    Node *np = NULL;
    while (c != NULL)
    {
        n = c->next;
        c->next = np;
        np = c;
        c = n;
    }
    head->next = np;
    head = p;
    return head;
}