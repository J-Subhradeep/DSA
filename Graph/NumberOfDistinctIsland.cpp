#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &graph, vector<vector<int>> &vis, int sr, int sc, pair<int, int> base, vector<pair<int, int>> &ds)
{
    if (sr >= 0 && sr < graph.size() && sc >= 0 && sc < graph.size() && !vis[sr][sc] && graph[sr][sc])
    {
        vis[sr][sc] = 1;
        ds.push_back({base.first - sr, base.second - sc});
    }
    else
        return;
    dfs(graph, vis, sr + 1, sc, base, ds);
    dfs(graph, vis, sr, sc + 1, base, ds);
    dfs(graph, vis, sr - 1, sc, base, ds);
    dfs(graph, vis, sr, sc - 1, base, ds);
}
int solve(vector<vector<int>> &graph, vector<vector<int>> &vis)
{
    set<vector<pair<int, int>>> s;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
        {
            if (!vis[i][j] && graph[i][j] == 1)
            {
                vector<pair<int, int>> ds;
                dfs(graph, vis, i, j, {i, j}, ds);
                s.insert(ds);
            }
        }
    }

    return s.size();
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> graph{
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {1, 0, 1, 1},

    };
    vector<vector<int>> vis(graph.size(), vector<int>(graph[0].size(), 0));
    cout << solve(graph, vis);
    return 0;
}
