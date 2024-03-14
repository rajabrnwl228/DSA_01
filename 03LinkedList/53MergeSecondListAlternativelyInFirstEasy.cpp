int len(Node *head)
{
    int l = 0;
    while (head != NULL)
    {
        l++;
        head = head->next;
    }
    return l;
}
void mergeList(struct Node **p, struct Node **q)
{
    // Code here
    Node *h1 = *p;
    Node *h2 = *q;
    Node *first = new Node(-1);
    Node *firsthead = first;
    int l1 = len(h1);
    int l2 = len(h2);
    while (h1 != NULL && h2 != NULL)
    {
        first->next = h1;
        first = first->next;
        h1 = h1->next;
        first->next = h2;
        first = first->next;
        h2 = h2->next;
        l1--;
        l2--;
    }
    while (l1 > l2)
    {
        first->next = h1;
        first = first->next;
        h1 = h1->next;
        l1--;
    }
    first->next = NULL;
    Node *second = new Node(-1);
    Node *secondhead = second;
    while (l2 > l1)
    {
        second->next = h2;
        second = second->next;
        h2 = h2->next;
        l2--;
    }
    *p = firsthead->next;
    *q = secondhead->next;
}