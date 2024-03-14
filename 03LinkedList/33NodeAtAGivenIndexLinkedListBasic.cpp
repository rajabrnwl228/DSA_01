int GetNth(struct node *head, int index)
{
    int count = 1;
    node *temp = head;
    while (temp != NULL)
    {
        if (count == index)
            return temp->data;
        temp = temp->next;
        count++;
    }
    return -1;
}