void MyStack ::push(int x)
{
    // Your Code
    StackNode *ne = new StackNode(x);
    if (top == NULL)
    {
        top = ne;
        return;
    }
    ne->next = top;
    top = ne;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    if (top == NULL)
        return -1;
    int v = top->data;
    top = top->next;
    return v;
}
