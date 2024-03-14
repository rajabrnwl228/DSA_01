int fractional_node(struct Node *head, int k)
{
    // your code here
    Node *temp = head;
    int len = 0, count = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    count = len / k;
    if (len % k != 0)
        count++;
    temp = head;
    while (count > 1)
    {
        temp = temp->next;
        count--;
    }
    return temp->data;
}