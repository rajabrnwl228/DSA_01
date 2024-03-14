int tribonacci(int n)
{
    unsigned int a = 0, b = 1, c = 1, d = 0;
    for (int i = 1; i <= n; i++)
    {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return a;
}