#include <bits/stdc++.h>
#define mod 1000000007
// memoziation
int countDistinctWaysMemo_helper(int n, int *arr)
{
  if (n == 0)
  {
    arr[0] = 1;
    return arr[n];
  }
  if (n == 1 || n == 2)
  {
    arr[n] = n;
    return arr[n];
  }
  if (arr[n] != -1)
    return arr[n];
  int a = (countDistinctWaysMemo_helper(n - 1, arr) + countDistinctWaysMemo_helper(n - 2, arr)) % mod;
  arr[n] = a;
  return arr[n];
}
int countDistinctWaysMemo(int n)
{
  //  Write your code here.
  int arr[n + 1];
  for (int i = 0; i <= n; i++)
  {
    arr[i] = -1;
  }
  int ans = countDistinctWaysMemo_helper(n, arr);
  return ans;
}

// dynamic programming
int countDistinctWaysDP(int n)
{
  //  Write your code here.
  int arr[n + 1];
  arr[0] = 1, arr[1] = 1, arr[2] = 2;
  for (int i = 3; i <= n; i++)
  {
    arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
  }
  return arr[n];
}
// space optimization
int countWaysSpaceOptimized(int n)
{
  // your code here
  if (n == 2 || n == 1)
    return n;
  int a = 1, b = 2, c = 0;
  for (int i = 2; i < n; i++)
  {
    c = (a % mod + b % mod) % mod;
    a = b;
    b = c;
  }
  return c;
}