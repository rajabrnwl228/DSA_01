Node *deleteNode(Node *head_ref, int x)
{
    // Your code here
    if (x == 1)
    {
        Node *del = head_ref;
        head_ref = head_ref->next;
        head_ref->prev = NULL;
        del->next = NULL;
        return head_ref;
    }
    int count = 1;
    Node *temp = head_ref;
    while (count < x && temp->next != NULL)
    {
        if (count == x - 1)
        {
            Node *f = temp->next;
            temp->next = f->next;
            Node *b = temp;
            temp = temp->next;
            if (temp != NULL)
                temp->prev = b;
            break;
        }
        temp = temp->next;
        count++;
    }
    return head_ref;
}