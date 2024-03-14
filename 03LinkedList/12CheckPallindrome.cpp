#include "01Node.cpp"
Node *reverseLinkedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *fwd = NULL;
    while (curr != NULL)
    {

        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    return prev;
}
Node *middle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    Node *temp = middle(head);
    Node *head2 = temp->next;
    temp->next = NULL;
    head2 = reverseLinkedList(head2);
    Node *firstList = head;
    Node *secondList = head2;
    bool ans = true;
    while (secondList != NULL)
    {
        if (firstList->data != secondList->data)
        {
            ans = false;
            break;
        }
        firstList = firstList->next;
        secondList = secondList->next;
    }
    firstList = head;
    head2 = reverseLinkedList(head2);
    while (firstList->next != NULL)
    {
        firstList = firstList->next;
    }
    firstList->next = head2;
    return ans;
}