void deleteAllOccurOfX(struct Node **head_ref, int x)
{
    // Write your code here
    Node *prev = NULL;
    Node *temp = *head_ref;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            Node *del = temp;
            if (prev != NULL)
            {
                prev->next = temp->next;
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
                *head_ref = temp;
            }
            del->next = NULL;
            delete del;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return;
}