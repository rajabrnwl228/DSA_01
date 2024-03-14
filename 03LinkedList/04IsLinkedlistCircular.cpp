#include "01Node.cpp"
bool CircularOrNot(Node *head)
{
    if (head == NULL)
        return false;
    Node *temp = head;
    while (temp != NULL && temp->next != head)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        return false;
    return true;
}