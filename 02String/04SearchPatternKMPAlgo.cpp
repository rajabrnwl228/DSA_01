int lps(string s, vector<int> &l)
{
    // Your code goes here
    int pre = 0, suf = 1;
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
}

public:
vector<int> search(string pat, string txt)
{

    vector<int> l(pat.size(), 0);
    lps(pat, l);
    int first = 0, second = 0;
    vector<int> ans;
    while (first < txt.size())
    {
        if (txt[first] == pat[second])
        {
            first++;
            second++;
        }
        else
        {
            if (second == 0)
                first++;
            else
            {
                second = l[second - 1];
            }
        }
        if (second == pat.size())
        {
            ans.push_back(first - second + 1);
            second = l[second - 1];
        }
    }
    return ans;
}