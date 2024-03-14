Node *insertInMiddle(Node *head, int x)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = slow->next;
    Node *newNode = new Node(x);
    slow->next = newNode;
    newNode->next = temp;

    return head;
}