#include "01Node.cpp"
bool floydCycleDetection(Node *head)
{
    if (head == NULL)
        return false;
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        if (slow == fast)
            return true;
    }
    return false;
}