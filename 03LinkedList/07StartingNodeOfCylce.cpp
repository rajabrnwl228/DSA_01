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
Node *StartingNodeLoop(Node *head)
{
    if (head == NULL)
        return head;
    Node *fast = floyd(head);
    if (fast == NULL)
        return NULL;
    Node *slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}