#include <bits/stdc++.h>
using namespace std;
void subseq(int n, int index, vector<int> &a, int arr[])
{
    if (index >= n)
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
        return;
    }
    a.push_back(arr[index]);
    subseq(n, index + 1, a, arr);
    a.pop_back();
    subseq(n, index + 1, a, arr);
}
int main(int argc, char const *argv[])
{

    vector<int> a;
    int arr[] = {3, 1, 2};
    subseq(3, 0, a, arr);
    return 0;
}
