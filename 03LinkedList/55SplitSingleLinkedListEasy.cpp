void alternatingSplitList(struct Node *head)
{
    // Your code here
    Node *x = new Node(-1);
    Node *p = x;
    Node *y = new Node(-1);
    Node *q = y;
    while (head != NULL)
    {
        x->next = head;
        x = x->next;
        head = head->next;
        if (head != NULL)
        {
            y->next = head;
            y = y->next;
            head = head->next;
        }
    }
    x->next = NULL;
    y->next = NULL;
    a = p->next;
    b = q->next;
}
