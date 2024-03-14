// to swap the data only
Node *zigZag(Node *head)
{
    // your code goes here
    Node *p = head;
    Node *nx = head->next;
    if (nx == NULL)
    {
        return head;
    }
    int f = 1;
    while (nx != NULL)
    {
        if (f)
        {
            if (p->data > nx->data)
            {
                int t = p->data;
                p->data = nx->data;
                nx->data = t;
            }
        }
        else if (p->data < nx->data)
        {
            int t = p->data;
            p->data = nx->data;
            nx->data = t;
        }

        f = !f;
        p = nx;
        nx = nx->next;
    }
    return head;

    // to swap the node
    Node *zigZag(Node * head)
    {
        // your code goes here
        Node *pp = new Node(-1);
        Node *hpp = pp;
        Node *p = head;
        Node *nx = head->next;
        if (nx == NULL)
        {
            return head;
        }
        int f = 1;
        while (nx != NULL)
        {
            if (f)
            {
                if (p->data > nx->data)
                {
                    p->next = nx->next;
                    nx->next = p;
                    pp->next = nx;
                    p = nx;
                    nx = nx->next;
                }
            }
            else if (p->data < nx->data)
            {
                p->next = nx->next;
                nx->next = p;
                pp->next = nx;
                p = nx;
                nx = nx->next;
            }

            f = !f;
            pp->next = p;
            pp = pp->next;
            p = nx;
            nx = nx->next;
        }
        return hpp->next;
    }