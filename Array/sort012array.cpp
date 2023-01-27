#include <bits/stdc++.h>
using namespace std;
void sortArr(vector<int> &arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;
    while (high >= mid)
    {
        /* code */
        switch (arr[mid])
        {
        case 0:
            arr[low] = arr[low] + arr[mid];
            arr[mid] = arr[low] - arr[mid];
            arr[low] = arr[low] - arr[mid];
            mid++;
            low++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            arr[high] = arr[high] + arr[mid];
            arr[mid] = arr[high] - arr[mid];
            arr[high] = arr[high] - arr[mid];
            high--;
        default:
            break;
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr{0, 1, 1, 0, 1, 0, 2, 2, 0, 1};
    sortArr(arr);
    for (auto &&i : arr)
    {
        cout << i << ",";
    }

    return 0;
}
