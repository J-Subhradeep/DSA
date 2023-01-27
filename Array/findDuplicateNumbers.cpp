#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> arr)
{
    int a = arr[0];
    for (auto &&i : arr)
    {
        a = a ^ i;
    }
    return a;
}
int main(int argc, char const *argv[])
{

    vector<int> arr{3, 2, 3, 3, 4, 5};
    cout << findDuplicate(arr);
    return 0;
}
