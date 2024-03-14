void deleteAlt(struct Node *head)
{
    // Code here
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        temp->next = temp->next->next;
        temp = temp->next;
    }
}