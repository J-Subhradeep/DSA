#include <bits/stdc++.h>
using namespace std;
bool subseq(int n, int index, vector<int> &a, int arr[], int sum, int k)
{
    if (index >= n)
    {
        if (sum == k)
        {
            for (auto &&i : a)
            {

                cout << i << " ";
            }
            if (a.size() == 0)
            {
                cout << "{}";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    a.push_back(arr[index]);
    if (subseq(n, index + 1, a, arr, sum += arr[index], k) == true)
        return true;
    a.pop_back();
    if (subseq(n, index + 1, a, arr, sum -= arr[index], k) == true)
        return true;
    //  if we want only one subsequence we need to convert the function in bool and the upper line should be executed like that
    return false;
}
int main(int argc, char const *argv[])
{

    vector<int> a;
    int arr[] = {3, 1, 2};
    int sum = 0;
    int k = 3;
    subseq(3, 0, a, arr, sum, k);
    return 0;
}
