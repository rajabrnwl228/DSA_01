#include "01Node.cpp"
int getMiddle(Node *head)
{
    // Your code here
    if (head == NULL)
        return NULL;
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}