void deleteNode(struct Node **head, int key)
{

    // Your code goes here
    Node *h = *head;
    if (h->data == key)
    {
        Node *t = h;
        while (t->next != h)
        {
            t = t->next;
        }
        h = h->next;
        t->next = h;
        *head = h;
        return;
    }
    Node *pr = h;
    Node *temp = h->next;
    ;
    while (temp != h)
    {
        if (temp->data == key)
        {
            pr->next = temp->next;
            return;
            break;
        }
        pr = temp;
        temp = temp->next;
    }
}

/* Function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    Node *h = *head_ref;
    Node *he = *head_ref;
    Node *prev = NULL, *ne = NULL;
    while (h->next != he)
    {
        ne = h->next;
        h->next = prev;
        prev = h;
        h = ne;
    }
    h->next = prev;
    he->next = h;

    *head_ref = h;
}