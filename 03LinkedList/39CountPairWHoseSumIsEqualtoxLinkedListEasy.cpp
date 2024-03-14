int countPairs(struct Node *head1, struct Node *head2, int x)
{
    // Code here
    Node *t1 = head1;
    Node *t2 = head2;
    unordered_map<int, int> mp;
    while (t2 != NULL)
    {
        mp[t2->data]++;
        t2 = t2->next;
    }
    int ans = 0;
    while (t1 != NULL)
    {
        int rem = x - t1->data;
        if (mp[rem] > 0)
            ans++;
        t1 = t1->next;
    }
    return ans;
}