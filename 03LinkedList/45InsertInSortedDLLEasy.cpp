Node *sortedInsert(Node *head, int x)
{
    // Code here
    Node *pr = NULL, *temp = head;
    Node *newNode = getNode(x);
    while (temp != NULL)
    {
        if (temp->data > x)
        {
            newNode->next = temp;
            newNode->prev = pr;
            temp->prev = newNode;
            if (pr != NULL)
                pr->next = newNode;
            if (temp == head)
                head = newNode;
            break;
        }
        pr = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        pr->next = newNode;
        newNode->prev = pr;
    }
    return head;
}