Node *addPolynomial(Node *p1, Node *p2)
{
    // Your code here
    Node *t1 = p1, *t2 = p2;
    Node *ans = new Node(-1, 0);
    Node *a = ans;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->pow == t2->pow)
        {
            t1->coeff = t1->coeff + t2->coeff;
            ans->next = t1;
            ans = ans->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->pow > t2->pow)
        {
            ans->next = t1;
            ans = ans->next;
            t1 = t1->next;
        }
        else if (t1->pow < t2->pow)
        {
            ans->next = t2;
            ans = ans->next;
            t2 = t2->next;
        }
    }
    while (t1 != NULL)
    {
        ans->next = t1;
        ans = ans->next;
        t1 = t1->next;
    }
    while (t2 != NULL)
    {
        ans->next = t2;
        ans = ans->next;
        t2 = t2->next;
    }
    return a->next;
}