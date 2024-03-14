Node *findIntersection(Node *head1, Node *head2)
{
    // code here
    // return the head of intersection list
    Node *t1 = head1;
    Node *t2 = head2;
    unordered_map<int, int> mp;
    while (t2 != NULL)
    {
        mp[t2->data]++;
        t2 = t2->next;
    }
    Node *Nh = new Node(-1);
    Node *Nt = Nh;
    while (t1 != NULL)
    {
        if (mp[t1->data] > 0)
        {
            Node *newNode = new Node(t1->data);
            Nt->next = newNode;
            Nt = Nt->next;
        }
        t1 = t1->next;
    }
    return Nh->next;
}