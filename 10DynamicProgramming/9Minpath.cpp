#include <iostream>
using namespace std;
int minCostPath_DP(int **input, int m, int n)
{
  int help[m][n];
  help[m - 1][n - 1] = input[m - 1][n - 1];
  // last row
  for (int i = n - 2; i >= 0; i--)
  {
    help[m - 1][i] = input[m - 1][i] + help[m - 1][i + 1];
  }

  // last col
  for (int i = m - 2; i >= 0; i--)
  {
    help[i][n - 1] = input[i][n - 1] + help[i + 1][n - 1];
  }

  for (int i = m - 2; i >= 0; i--)
  {
    for (int j = n - 2; j >= 0; j--)
    {
      help[i][j] = min(help[i][j + 1], min(help[i + 1][j + 1], help[i + 1][j])) + input[i][j];
    }
  }

  int ans = help[0][0];
  return ans;
}

int minCostPath(int **input, int m, int n, int row, int col)
{
  if (row >= m || col >= n)
    return 2147468;

  if (row == n - 1 && col == n - 1)
  {
    return input[row][col];
  }

  int a = minCostPath(input, m, n, row, col + 1);
  int b = minCostPath(input, m, n, row + 1, col + 1);
  int c = minCostPath(input, m, n, row + 1, col);

  int ans = min(a, min(b, c)) + input[row][col];
  return ans;
}

int minCostPath(int **input, int m, int n)
{
  return minCostPath(input, m, n, 0, 0);
  // Write your code here
}
int minCostPathmem(int **input, int m, int n, int row, int col, int **help)
{
  if (row == n - 1 && col == n - 1)
  {
    return input[row][col];
  }
  if (row >= m || col >= n)
    return 2147468;
  int ans = 0;
  if (help[row][col] != -1)
  {
    return help[row][col];
  }

  int a = minCostPathmem(input, m, n, row, col + 1, help);
  int b = minCostPathmem(input, m, n, row + 1, col + 1, help);
  int c = minCostPathmem(input, m, n, row + 1, col, help);
  ans = input[row][col] + min(a, min(b, c));
  help[row][col] = ans;
  return ans;
}

int minCostPathmem(int **input, int m, int n)
{
  int **help = new int *[m];
  for (int i = 0; i < m; i++)
  {
    *help = new int[n];
    for (int j = 0; j < n; j++)
    {
      help[i][j] = -1;
    }
  }

  return minCostPathmem(input, m, n, 0, 0, help);
  // Write your code here
}

int main()
{
  int **arr, n, m;
  cin >> n >> m;
  arr = new int *[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[m];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }
  cout << minCostPath(arr, n, m) << endl;
  cout << "heloo" << endl;
  cout << minCostPath_DP(arr, n, m) << endl;
  cout << "heloo2" << endl;
  cout << minCostPathmem(arr, n, m) << endl;
  return 0;
}