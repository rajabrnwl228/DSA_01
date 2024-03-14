#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int ans = helper(n);
    cout << ans << endl;
  }
  // write your code here
  return 0;
}