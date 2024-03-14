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
int countNodesinLoop(struct Node *head)
{
    if (head == NULL)
        return 0;
        //check loop
    Node *fast = floyd(head);
    if (fast == NULL)
        return 0;
    //find starting node of loop
    Node *slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *temp =slow;
    int count=1;
    while (temp->next != slow)
    {
        temp = temp->next;
        count++;
    }
    return count;
}