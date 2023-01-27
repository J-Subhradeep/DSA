#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = solve(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int right = 100000000;
    if (n > 1)
        right = solve(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    return dp[n] = min(left, right);
}
int main(int argc, char const *argv[])
{
    vector<int> heights{30, 10, 60, 10, 60, 50};
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << solve(n, heights, dp);
    return 0;
}
