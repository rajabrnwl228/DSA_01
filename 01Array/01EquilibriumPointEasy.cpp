int equilibriumPoint(long long a[], int n)
{

    if (n == 0)
        return -1;
    int i = 0, j = n - 1;
    int ans = -2;
    long long sum1 = a[i];
    long long sum2 = a[j];
    while (i <= j)
    {
        if (sum1 == sum2)
        {
            ans = i;
        }
        if (sum1 < sum2)
        {
            i++;
            sum1 += a[i];
        }
        else
        {
            j--;
            sum2 += a[j];
        }
    }
    if (ans == i)
        return ans + 1;

    return -1;
}