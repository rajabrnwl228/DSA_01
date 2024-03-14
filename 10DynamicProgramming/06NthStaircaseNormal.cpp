#include <iostream>
using namespace std;
// Recursion 1
void staircase_rec_M1(int n, int &ans_rec_M2)
{
    if (n < 0)
    {
        return;
    }
    if (n == 0)
    {
        ans_rec_M2++;
        return;
    }
    staircase_rec_M1(n - 1, ans_rec_M2);
    staircase_rec_M1(n - 2, ans_rec_M2);
}

// Recursion 3
int staircase_rec_M2(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    int x = 0, y = 0;
    x += staircase_rec_M2(n - 1);
    y += staircase_rec_M2(n - 2);
    return x + y;
}
int main()
{
    int n;
    cin >> n;
    // approach 1
    cout << "Recursion M-1: ";
    int ans_rec_M1 = 0;
    staircase_rec_M1(n, ans_rec_M1);
    cout << ans_rec_M1 << endl;

    // approach 2
    cout << "Recursion M-2: ";
    int ans_rec_M2 = 0;
    int ans_rec_M2 = staircase_rec_M2(n);
    cout << ans_rec_M2 << endl;

    int ans4 = staircase_norm_approach4(n, 0);
    cout << ans4 << endl;
    return 0;
}