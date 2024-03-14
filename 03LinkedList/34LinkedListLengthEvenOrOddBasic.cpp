int isLengthEvenOrOdd(struct Node *head)
{

    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    if (len % 2 == 0)
        return 0;
    else
        return 1;
    // Code here
}