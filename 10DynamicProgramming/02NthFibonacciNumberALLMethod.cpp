#include <iostream>
using namespace std;

/*simple recursion
Time complexity will be 2^n;*/
int fib_Rec(int n)
{
  if (n <= 1)
  {
    return n;
  }
  int a = fib_Rec(n - 1);
  int b = fib_Rec(n - 2);
  return a + b;
}

/*memorization
Time complexity will be n
Space complexity will be n
 */
int fib_memo(int n, int *ans)
{
  if (n <= 1)
  {
    ans[n] = n;
    return n;
  }

  if (ans[n] != -1)
    return ans[n];
  int x = fib_memo(n - 1, ans);
  int y = fib_memo(n - 2, ans);
  ans[n] = x + y;
  return ans[n];
}

/* Dynamic programming
Time complexity will be n
Space complexity will be n*/
int fib_Dynam(int n)
{
  int *ans = new int[n + 1];
  ans[0] = 0;
  ans[1] = 1;
  for (int i = 2; i <= n; i++)
    ans[i] = ans[i - 1] + ans[i - 2];
  return ans[n];
}

/*space optimization
Time complexity O(N)
space complexity S(1) */
int fib_opti(int n)
{
  int f0 = 0, f1 = 1, f2 = 0;
  while (--n)
  {
    f2 = f0 + f1;
    f0 = f1;
    f1 = f2;
  }
  return f2;
}

int main()
{
  int n;
  cout << "Enter the number: ";
  cin >> n;
  cout << "Recursion: ";
  int ans_rec = fib_Rec(n);
  cout << ans_rec << endl;

  int *arr = new int[n + 1];
  for (int i = 0; i <= n; i++)
  {
    arr[i] = -1;
  }
  cout << "Memoziation: ";
  int ans_memo = fib_memo(n, arr);
  cout << ans_memo << endl;

  cout << "Dynamic: ";
  int ans_dynam = fib_Dynam(n);
  cout << ans_dynam << endl;

  cout << "Space Optimiz: ";
  int ans_opti = fib_opti(n);
  cout << ans_opti << endl;
}