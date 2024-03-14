void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *slow = head;
    Node *fast = head->next;
    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != head)
            fast = fast->next;
    }
    Node *temp = slow->next;
    slow->next = head;
    fast->next = temp;
    *head1_ref = head;
    *head2_ref = temp;
    return;
}