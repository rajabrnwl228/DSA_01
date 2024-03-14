Node *segregate(Node *head)
{

    // Add code here
    Node *zeroshead = new Node(-1);
    Node *zerostail = zeroshead;
    Node *oneshead = new Node(-1);
    Node *onestail = oneshead;
    Node *twoshead = new Node(-1);
    Node *twostail = twoshead;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerostail->next = temp;
            zerostail = temp;
        }
        else if (temp->data == 1)
        {
            onestail->next = temp;
            onestail = temp;
        }
        else
        {
            twostail->next = temp;
            twostail = temp;
        }
        temp = temp->next;
    }

    if (oneshead->next != NULL)
        zerostail->next = oneshead->next;
    else
        zerostail->next = twoshead->next;

    onestail->next = twoshead->next;
    twostail->next = NULL;

    head = zeroshead->next;
    delete zeroshead;
    delete oneshead;
    delete twoshead;

    return head;
}