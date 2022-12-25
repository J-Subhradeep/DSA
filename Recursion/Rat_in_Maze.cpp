#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &graph, vector<vector<int>> &vis, string ds, int row, int col, int n)
{
    if ((row == n - 1) && (col == n - 1))
    {
        cout << ds << endl;
        return;
    }
    if (row >= n || col >= n || row < 0 || col < 0)
    {
        return;
    }
    if (graph[row][col] == 0)
    {
        return;
    }
    if (vis[row][col])
    {
        return;
    }

    vis[row][col] = 1;

    solve(graph, vis, ds + "D", row + 1, col, n);
    solve(graph, vis, ds + "L", row, col - 1, n);
    solve(graph, vis, ds + "R", row, col + 1, n);
    solve(graph, vis, ds + "U", row - 1, col, n);
    vis[row][col] = 0;
    ds.pop_back();
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> graph{
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 1},
    };
    vector<vector<int>> vis(graph.size(), vector<int>(graph.size(), 0));
    solve(graph, vis, "", 0, 0, graph.size());
    return 0;
}
