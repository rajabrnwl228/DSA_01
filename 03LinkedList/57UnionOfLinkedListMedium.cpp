
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data == right->data)
        {
            left = left->next;
        }
        else if (left->data < right->data)
        {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = temp->next;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = temp->next;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node *ans = merge(left, right);
    return ans;
}
struct Node *makeUnion(struct Node *head1, struct Node *head2)
{
    // code here
    Node *head = head1;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = head2;
    Node *h1 = mergeSort(head1);

    return h1;
}