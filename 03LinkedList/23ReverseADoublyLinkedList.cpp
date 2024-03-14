Node *reverseDLL(Node *head)
{
    Node *temp = head;
    Node *Next = head;
    while (temp->next != NULL)
    {
        Next = temp->next;

        Node *p = temp->prev;
        temp->prev = temp->next;
        temp->next = p;
        temp = Next;
    }
    Node *p = temp->prev;
    temp->prev = temp->next;
    temp->next = p;

    return temp;
}