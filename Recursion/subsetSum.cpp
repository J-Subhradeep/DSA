#include <bits/stdc++.h>
using namespace std;
void subsetSum(int index, vector<int> &arr, vector<int> ds, int sum)
{
    if (index == arr.size())
    {
        for (auto &&i : ds)
        {
            cout << i << ", ";
        }
        cout << "=" << sum << endl;
        return;
    }
    ds.push_back(arr[index]);
    subsetSum(index + 1, arr, ds, sum + arr[index]);
    ds.pop_back();
    subsetSum(index + 1, arr, ds, sum);
}
int main(int argc, char const *argv[])
{
    vector<int> arr{1, 2, 3};
    subsetSum(0, arr, vector<int>(), 0);
    return 0;
}
