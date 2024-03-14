Node *deleteNode(Node *head, int x)
{
    // Your code here
    if (head == NULL)
        return head;
    if (x == 1)
        return head->next;
    Node *temp = head;
    int count = 0;
    Node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == x)
        {
            prev->next = temp->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}