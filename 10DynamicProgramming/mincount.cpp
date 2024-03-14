#include <bits/stdc++.h>
using namespace std;
int helper(int n)
{
  if (n <= 3)
    return n;
  int b = sqrt(n);
  int a = b * b;
  if (n / a == 1 && n % a == 0)
    return 1;
  else
    return 1 + helper(n - a);
}
int main()
{

  int n;
  cin >> n;
  int ans = helper(n);
  cout << ans << endl;
  // write your code here
  return 0;
}