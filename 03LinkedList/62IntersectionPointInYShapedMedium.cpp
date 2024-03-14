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
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    int l1 = len(head1);
    int l2 = len(head2);
    if (l2 > l1)
    {
        Node *t = head2;
        head2 = head1;
        head1 = t;
        int l = l1;
        l1 = l2;
        l2 = l;
    }
    while (l1 > l2)
    {
        l1--;
        head1 = head1->next;
    }
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
            return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}