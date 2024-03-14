vector<int> leaders(int a[], int n)
{
    // Code here
    int max = 0;
    vector<int> subans, ans;
    int k = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= max)
        {
            max = a[i];
            subans.push_back(max);
        }
    }

    int i = 0, j = subans.size() - 1;
    while (i < j)
    {
        int t = subans[i];
        subans[i] = subans[j];
        subans[j] = t;
        i++;
        j--;
    }
    return subans;