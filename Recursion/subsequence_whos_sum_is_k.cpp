#include <bits/stdc++.h>
using namespace std;
void subseq(int n, int index, vector<int> &a, int arr[], int sum, int k)
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
        }

        return;
    }

    a.push_back(arr[index]);
    subseq(n, index + 1, a, arr, sum += arr[index], k);
    a.pop_back();
    subseq(n, index + 1, a, arr, sum -= arr[index], k);
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
