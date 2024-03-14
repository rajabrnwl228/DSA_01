int sumOfLastN_Nodes(struct Node *head, int n)
{
    // Code here
    Node *temp = head;
    int len = 0, count = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    int sum = 0;
    temp = head;
    while (temp != NULL)
    {
        if (count >= len - n)
        {
            sum += temp->data;
        }
        count++;
        temp = temp->next;
    }
    return sum;
