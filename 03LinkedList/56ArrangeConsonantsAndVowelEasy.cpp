struct Node *arrange(Node *head)
{
    // Code here
    Node *first = new Node(-1);
    Node *firsthead = first;
    Node *second = new Node(-1);
    Node *secondhead = second;
    while (head != NULL)
    {
        if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u')
        {
            first->next = head;
            head = head->next;
            first = first->next;
        }
        else
        {
            second->next = head;
            head = head->next;
            second = second->next;
        }
    }
    second->next = NULL;
    first->next = secondhead->next;
    return firsthead->next;
}