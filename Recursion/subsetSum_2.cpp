#include <bits/stdc++.h>
using namespace std;
void subseqSum(int index, vector<int> arr, vector<int> ds, int sum)
{
    if (index == arr.size())
    {
        for (auto &&i : ds)
        {
            cout << "+" << i;
        }
        cout << "=" << sum << endl;
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {

        ds.push_back(arr[i]);
        subseqSum(i + 1, arr, ds, sum + arr[i]);
        ds.pop_back();
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr{1, 2, 2};
    int sum = 0;
    subseqSum(0, arr, vector<int>(), sum);
    return 0;
}
