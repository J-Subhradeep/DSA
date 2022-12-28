#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &graph, vector<vector<int>> &vis, int sr, int sc)
{
    if (sr >= 0 && sc >= 0 && sc < graph.size() && sr < graph.size() && !vis[sr][sc] && graph[sr][sc] == 1)
    {
        /* code */
        vis[sr][sc] = 1;
    }
    else
        return;
    dfs(graph, vis, sr + 1, sc);
    dfs(graph, vis, sr - 1, sc);
    dfs(graph, vis, sr, sc + 1);
    dfs(graph, vis, sr, sc - 1);
}
int solve(vector<vector<int>> &graph, vector<vector<int>> &vis)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[0][i] == 1 && vis[0][i] == 0)
            dfs(graph, vis, 0, i);
        if (graph[(graph.size() - 1)][i] == 1 && vis[(graph.size() - 1)][i] == 0)
            dfs(graph, vis, graph.size() - 1, i);
        if (graph[i][0] == 1 && vis[i][0] == 0)
            dfs(graph, vis, i, 0);
        if (graph[i][graph[0].size() - 1] == 1 && vis[i][graph[0].size() - 1] == 0)
            dfs(graph, vis, i, graph[0].size() - 1);
    }
    int count = 0;
    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph.size(); j++)
        {
            if ((graph[i][j] == 1) && vis[i][j] == 0)
                count++;
        }
    return count;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> graph{
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1},
    };
    vector<vector<int>> vis(graph.size(), vector<int>(graph[0].size(), 0));
    cout << solve(graph, vis);
    return 0;
}
