int modularNode(Node *head, int k)
{
    // Code here
    int count = 1;
    int ans = -1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (count % k == 0)
        {
            ans = temp->data;
        }
        count++;
        temp = temp->next;
    }
    return ans;
}