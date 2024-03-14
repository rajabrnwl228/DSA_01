int lps(string s)
{
    // Your code goes here
    int pre = 0, suf = 1;
    vector<int> l(s.size(), 0);
    while (suf < s.size())
    {
        if (s[pre] == s[suf])
        {
            l[suf] = pre + 1;
            suf++;
            pre++;
        }
        else
        {
            if (pre == 0)
                suf++;
            else
                pre = l[pre - 1];
        }
    }
    return l[s.size() - 1];
}