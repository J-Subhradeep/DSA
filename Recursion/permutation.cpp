#include <bits/stdc++.h>
using namespace std;
void permutation(int index, vector<int> arr, vector<int> ds, vector<int> mapper)
{
    if (ds.size() == arr.size())
    {
        for (auto &&i : ds)
        {
            cout << i << ",";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (!mapper[i])
        {
            mapper[i] = 1;
            ds.push_back(arr[i]);
            permutation(i, arr, ds, mapper);
            ds.pop_back();
            mapper[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr{1, 2, 3, 4};
    vector<int> mapper(arr.size(), 0);
    permutation(0, arr, vector<int>(), mapper);
    return 0;
}
