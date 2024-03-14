#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define vector <vector<long, long>> vv
vv multiply(vv &x, vv &y)
{
  vv res2(2, vector<long long>(2, 0));
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < 2; k++)
      {
        res2[i][j] = (res2[i][j] + ((x[i][k]) % mod * (y[k][j]) % mod)) % mod;
      }
    }
  }

  return res2;
}
vv Exp(vv &d, int n)
{
  if (n == 0)
  {
    int sz = d.size();
    vv I(sz, vector<long long>(sz, 0));
    for (int i = 0; i < 2; i++)
    {
      I[i][i] = 1;
    }
    return I;
  }
  if (n == 1)
    return d;
  vv temp = Exp(d, n / 2);
  vv ans = multiply(temp, temp);

  if (n & 1)
    ans = multiply(ans, d);

  return ans;
}
int fibonacciNumber(int n)
{
  // Write your code here.

  vv d(2, vector<long long>(2, 1));
  d[1][1] = 0;
  vv ans = Exp(d, n);
  return ans[0][1] % mod;
}

int main()
{
  int n;
  cout << "Enter the number: ";
  cin >> n;
  cout << fibonacciNumber(n) << endl;
  return 0;
}