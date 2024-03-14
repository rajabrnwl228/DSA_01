bool compute(Node *root)
{
    // Your code goes here
    string s = "";
    Node *t = root;
    while (t != NULL)
    {
        s += t->data;
        t = t->next;
    }
    int l = s.length();
    for (int i = 0; i < l / 2; i++)
    {
        if (s[i] != s[l - i - 1])
            return false;
    }
    return true;
}
