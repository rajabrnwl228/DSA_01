#include <iostream>
using namespace std;
int minstepTo1(int n)
{
  // base case
  if (n <= 1)
    return 0;
  int a = minstepTo1(n - 1);
  int b = INT16_MAX;
  int c = INT16_MAX;
  if (n % 2 == 0)
    b = minstepTo1(n / 2);
  if (n % 3 == 0)
    c = minstepTo1(n / 3);

  return 1 + min(a, min(b, c));
}
// memoziation
int minstepTo1m(int n, int *ans)
{
  // base case
  if (n <= 1)
    return 0;
  if (ans[n] != -1)
    return ans[n];
  // calculate
  int a = minstepTo1m(n - 1, ans);
  int b = INT16_MAX;
  int c = INT16_MAX;
  if (n % 2 == 0)
    b = minstepTo1m(n / 2, ans);
  if (n % 3 == 0)
    c = minstepTo1m(n / 3, ans);
  int output = 1 + min(a, min(b, c));
  // store
  ans[n] = output;
  return output;
}
// dp
int countStepsToOne(int n)
{

  int *ans = new int[n + 1];
  ans[0] = 0;
  ans[1] = 0;

  for (int i = 2; i <= n; i++)
  {
    int x, y = INT_MAX, z = INT_MAX;
    x = ans[i - 1];
    if (i % 2 == 0)
      y = ans[i / 2];
    if (i % 3 == 0)
      z = ans[i / 3];
    ans[i] = 1 + min(x, min(y, z));
  }
  int output = ans[n];
  delete[] ans;
  return output;
}
int main()
{
  int n;
  cin >> n;
  // method-1
  int a = minstepTo1(n);
  cout << a << endl;
  int *ans = new int[n + 1];
  for (int i = 0; i <= n; i++)
  {
    ans[i] = -1;
  }
  int b = minstepTo1m(n, ans);
  cout << b << endl;
  return 0;
}