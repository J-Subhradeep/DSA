#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, vector<int> &ngt)
{
    stack<int> s;
    for (int i = 2 * arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i % arr.size()])
        {
            s.pop();
        }
        if (!s.empty())
        {
            ngt[i % arr.size()] = s.top();
            s.push(arr[i % arr.size()]);
        }
        else
        {
            s.push(arr[i % arr.size()]);
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr{2, 3, 1, 5, 6, 4};
    vector<int> ngt(arr.size(), -1);
    solve(arr, ngt);
    for (auto &&i : ngt)
    {
        cout << i << ' ';
    }

    return 0;
}
