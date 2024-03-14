Node *findIntersection(Node *head1, Node *head2)
{
    // code goes here
    Node *ans = new Node(-1);
    Node *ans2 = ans;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            Node *newNode = new Node(head1->data);
            ans->next = newNode;
            ans = ans->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }

    return ans2->next;
}
