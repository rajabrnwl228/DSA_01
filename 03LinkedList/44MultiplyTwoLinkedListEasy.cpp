long long multiplyTwoLists(Node *l1, Node *l2)
{
    // Your code here
    long long mod = 1000000007;
    long long ans = 0, subans = 0, carry = 0;
    while (l1 != NULL)
    {
        long long d = l1->data;
        Node *t2 = l2;
        subans = 0, carry = 0;
        while (t2 != NULL)
        {
            long long x = t2->data * d;
            carry = x / 10;
            subans = (((subans + carry) * 10) % mod + x % 10) % mod;
            t2 = t2->next;
        }
        ans = (((ans * 10) % mod) + subans) % mod;
        l1 = l1->next;
    }
    return ans;
}