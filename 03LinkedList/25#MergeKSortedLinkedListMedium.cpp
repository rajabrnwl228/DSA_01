Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    Node *head = new Node(-1);
    Node *tail = head;
    int f = 1;
    while (f)
    {
        f = 0;
        int mini = INT_MAX;
        int mI = -1;
        for (int i = 0; i < K; i++)
        {
            if (arr[i] != NULL)
            {
                Node *m = arr[i];
                if (m->data < mini)
                {
                    mI = i;
                    mini = m->data;
                }
                f = 1;
            }
        }
        if (mI != -1)
        {
            Node *mov = arr[mI];
            arr[mI] = mov->next;
            tail->next = mov;
            tail = tail->next;
        }
    }
    return head->next;
}