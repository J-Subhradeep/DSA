#include <bits/stdc++.h>
using namespace std;
void findCombinationSumWithoutDuplicates(int index, int size, vector<int> &arr, int target, vector<int> ds)
{
    if (target == 0)
    {
        for (auto &&i : ds)
        {
            cout << i << ", ";
        }
        cout << endl;
        return;
    }
    for (int i = index; i < size; i++)
    {
        if (i > index && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            return;
        ds.push_back(arr[i]);
        findCombinationSumWithoutDuplicates(i + 1, size, arr, target - arr[i], ds);
        ds.pop_back();
    }
}
int main(int argc, char const *argv[])
{
    vector<int> ds;
    vector<int> arr{1, 1, 1, 2, 2, 3, 5};
    int target = 7;
    int size = arr.size();
    findCombinationSumWithoutDuplicates(0, size, arr, target, ds);
    return 0;
}
