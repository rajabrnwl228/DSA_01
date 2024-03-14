Node *sortList(Node *head)
{
    // Your Code Here
    Node *temp = head->next;
    Node *prev = head;
    while (temp != NULL)
    {
        if (temp->data < 0)
        {
            prev->next = temp->next;
            temp->next = head;
            head = temp;
            temp = prev;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}