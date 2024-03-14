Node *reverse(Node *head)
{
    Node *prev = NULL, *ne = NULL;
    while (head != NULL)
    {
        ne = head->next;
        head->next = prev;
        prev = head;
        head = ne;
    }
    return prev;
}
struct Node *mergeResult(Node *node1, Node *node2)
{
    // your code goes here
    Node *ans = newNode(-1);
    Node *t = ans;
    Node *temp1 = node1;
    Node *temp2 = node2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            ans->next = temp1;
            temp1 = temp1->next;
            ans = ans->next;
        }
        else
        {
            ans->next = temp2;
            temp2 = temp2->next;
            ans = ans->next;
        }
    }
    while (temp1 != NULL)
    {
        ans->next = temp1;
        temp1 = temp1->next;
        ans = ans->next;
    }
    while (temp2 != NULL)
    {
        ans->next = temp2;
        temp2 = temp2->next;
        ans = ans->next;
    }
    ans = reverse(t->next);
    return ans;
}