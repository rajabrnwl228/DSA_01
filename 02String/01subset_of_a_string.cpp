#include <iostream>
#include <set>
using namespace std;
void subset(string input, string output, set<string> &ans, int index)
{
    if (index == input.size())
    {
        ans.insert(output);
        return;
    }
    // exclude
    subset(input, output, ans, index + 1);
    // include
    output.push_back(input[index]);
    subset(input, output, ans, index + 1);
}
int main()
{
    string input = "abb";
    string output = "";
    set<string> ans;
    subset(input, output, ans, 0);
    cout << ans.size();
    set<string>::iterator it;
    for (it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}