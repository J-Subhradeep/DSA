#include <bits/stdc++.h>
using namespace std;
void permutation(vector<int> arr, vector<int> mapper, vector<int> ds, int &n, int k)
{
    if (ds.size() == arr.size())
    {
        if (++n == k)
        {

            for (auto &&i : ds)
            {
                cout << i;
            }
            cout << endl;
        }
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (!mapper[i])
        {
            mapper[i] = 1;
            ds.push_back(arr[i]);
            permutation(arr, mapper, ds, n, k);
            ds.pop_back();
            mapper[i] = 0;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n = 0;
    int N = 3;
    int k = 3;
    int i = 1;
    vector<int> arr(N);
    iota(begin(arr), end(arr), 1);
    permutation(arr, vector<int>(arr.size(), 0), vector<int>(), n, k);
    return 0;
}
