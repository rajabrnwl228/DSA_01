Node *insertAtBegining(Node *head, int x)
{
    // Your code here
    if (head == NULL)
    {
        Node *newNode = new Node(x);
        head = newNode;
        return head;
    }
    else
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        return head;
    }
}

// Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)
{
    // Your code here
    if (head == NULL)
    {
        Node *newNode = new Node(x);
        head = newNode;
        return head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(x);
        temp->next = newNode;
        return head;
    }
}