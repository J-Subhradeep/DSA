#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &graph, vector<vector<int>> &vis, int row, int col)
{
    if (row >= graph.size() || col >= graph[0].size() || row < 0 || col < 0)
    {
        return;
    }
    if (!graph[row][col] || vis[row][col])
        return;
    vis[row][col] = 1;
    // dfs(graph, vis, row + 1, col);
    // dfs(graph, vis, row - 1, col);
    // dfs(graph, vis, row - 1, col - 1);
    // dfs(graph, vis, row - 1, col + 1);
    // dfs(graph, vis, row + 1, col + 1);
    // dfs(graph, vis, row + 1, col - 1);
    // dfs(graph, vis, row, col - 1);
    // dfs(graph, vis, row, col + 1);

    // instead of those 8 line we can simply write this loops
    for (int i = -1; i < 2; i++)
        for (int j = -1; j < 2; j++)
            dfs(graph, vis, row + i, col + j);
}
int traverse(vector<vector<int>> &graph, vector<vector<int>> &vis)
{
    int count = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
        {
            if (!vis[i][j] && graph[i][j])
            {
                count++;
                dfs(graph, vis, i, j);
            }
        }
    }
    return count;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> graph{
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 1},
    };
    vector<vector<int>> vis(graph.size(), vector<int>(graph[0].size(), 0));
    cout << traverse(graph, vis);
    return 0;
}
