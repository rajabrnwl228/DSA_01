#include "01Node.cpp"
Node *floyd(Node *head)
{
    if (head == NULL)
        return head;
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        if (slow == fast)
            return fast;
    }
    return NULL;
}
void removeLoop(Node *head)
{
    if (head == NULL)
        return;
    Node *fast = floyd(head);
    if (fast == NULL)
        return;
    Node *slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *startLoop = slow;
    Node *temp = startLoop;
    while (temp->next != startLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}