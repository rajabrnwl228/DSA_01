long long mod = 1000000007;
vector<long long> nthRowOfPascalTriangle(int n)
{
    // code here
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }

    vector<long long> ans;
    ans = dp[n - 1];
    return ans;
}

// more optimize
vector<long long> nthRowOfPascalTriangle(int n)
{
    // code here
    vector<long long> dp[n];
    dp[0].push_back(1);
    for (int i = 1; i < n; i++)
    {
        dp[i].push_back(1);
        for (int j = 1; j < i; j++)
        {
            long long a = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            dp[i].push_back(a);
        }
        dp[i].push_back(1);
    }

    vector<long long> ans;
    ans = dp[n - 1];
    return ans;
}