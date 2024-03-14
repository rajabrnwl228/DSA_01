Node *reverse(struct Node *head)
{
    Node *h = head;
    Node *prev = NULL, *ne = NULL;
    while (h != NULL)
    {
        ne = h->next;
        h->next = prev;
        prev = h;
        h = ne;
    }
    return prev;
}

void moveZeroes(struct Node **head)
{
    // Your code here
    Node *temp = *head;
    Node *newHead = *head;
    Node *prev = NULL, *nx = NULL;
    while (temp != NULL)
    {
        if (temp->data != 0 && (prev != NULL))
        {
            nx = temp->next;
            prev->next = nx;
            temp->next = newHead;
            newHead = temp;
            temp = nx;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    *head = reverse(newHead);
