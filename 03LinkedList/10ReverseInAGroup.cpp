#include "01Node.cpp"
Node *reverseK(Node *head, int k)
{
    // if (head == NULL || k == 0)
    // {
    //     return head;
    // }
    int count = 0;
    Node *prev = NULL;
    Node *curr = head, *ne = head;
    while (curr != NULL && count < k)
    {
        count++;
        ne = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ne;
    }
    if (ne != NULL)
        head->next = reverseK(ne, k);
    return prev;
}