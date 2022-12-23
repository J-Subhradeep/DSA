#include <bits/stdc++.h>
using namespace std;
void permutation(int index, vector<int> arr, vector<int> ds)
{
    if (index == arr.size())
    {
        for (auto &&i : arr)
        {
            cout << i << ",";
        }
        cout << endl;
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;

        permutation(index + 1, arr, ds);
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr{1, 2, 3, 4};
    permutation(0, arr, vector<int>());
    return 0;
}
