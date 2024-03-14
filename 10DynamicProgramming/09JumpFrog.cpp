#include <bits/stdc++.h>

/*recursion
 Time Complexity O(2^N)
 Space Complexity S(N) */
int frogJump_rec(int n, vector<int> &heights)
{
    if (n == 0)
        return 0;
    int y = INT_MAX;
    int x = frogJumpNormal(i - 1, heights) +
            abs(heights[i] - heights[i - 1]);
    if (i > 1)
    {
        y = frogJumpNormal(i - 2, heights) +
            abs(heights[i - 2] - heights[i]);
    }
    return min(x, y);
}
/*Time complexity O(n)
and Space complexity is O(1)*/
int frogJumpSpaceOptimization(int n, vector<int> &heights)
{
    int prev1 = 0, prev2 = 0, curr = 0;
    for (int i = 1; i < n; i++)
    {
        int x = abs(heights[i - 1] - heights[i]) + prev1;
        int y = INT_MAX;
        if (i > 1)
            y = abs(heights[i - 2] - heights[i]) + prev2;
        curr = min(x, y);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
/*Time complexity O(n)
and Space complexity is O(n)*/
int frogJumpDynamicProgramming(int n, vector<int> &heights)
{
    vector<int> ans(n, 0);
    ans[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int x = abs(heights[i - 1] - heights[i]) + ans[i - 1];
        int y = INT_MAX;
        if (i > 1)
            y = abs(heights[i - 2] - heights[i]) + ans[i - 2];
        ans[i] = min(x, y);
    }
    return ans[n - 1];
}
/*Time complexity O(n)
and Space complexity is O(n)*/
int frogJumpMemoizationHelper(int i, vector<int> &heights, vector<int> &ans)
{
    if (i == 0)
    {
        ans[0] = 0;
        return ans[0];
    }
    if (ans[i] != -1)
        return ans[i];
    int y = INT_MAX;
    int x = frogJumpMemoizationHelper(i - 1, heights, ans) +
            abs(heights[i] - heights[i - 1]);
    if (i > 1)
    {
        y = frogJumpMemoizationHelper(i - 2, heights, ans) +
            abs(heights[i - 2] - heights[i]);
    }
    ans[i] = min(x, y);
    return ans[i];
}

int frogJumpMemoization(int n, vector<int> &heights)
{
    vector<int> ans(n, -1);
    int a = frogJumpMemoizationHelper(n - 1, heights, ans);
    return a;
}
nt frogJumpNormal(int i, vector<int> &heights)
{
    if (i == 0)
    {
        return 0;
    }
    int y = INT_MAX;
    int x = frogJumpNormal(i - 1, heights) +
            abs(heights[i] - heights[i - 1]);
    if (i > 1)
    {
        y = frogJumpNormal(i - 2, heights) +
            abs(heights[i - 2] - heights[i]);
    }
    return min(x, y);
}

// Problem Statement
// Send feedback
// There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1]). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.
// For Example
// If the given 'HEIGHT' array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20 = 10 energy lost). So, the total energy lost is 20.
// Detailed explanation (Input/output format, Notes, Images)
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 100000.
// 1 <= HEIGHTS[i] <= 1000.
// Time limit: 1 sec
// Sample Input 1:
// 2
// 4
// 10 20 30 10
// 3
// 10 50 10
// Sample Output 1:
// 20