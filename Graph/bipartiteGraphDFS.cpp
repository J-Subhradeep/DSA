#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &graph, vector<int> &color, int src, int parent)
{
    if (color[src] == -1)
    {
        if (parent == -1)
        {
            color[src] = 0;
        }

        else
            color[src] = !color[parent];
    }

    for (auto &&i : graph[src])
    {
        if (color[i] == -1)
        {
            /* code */
            if (!dfs(graph, color, i, src))
                return false;
        }
        else if (color[i] == color[src])
            return false;
    }

    return true;
}
bool solve(vector<vector<int>> &g, vector<int> &color)
{
    for (int i = 0; i < g.size(); i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(g, color, i, -1))
                return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> color(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << solve(g, color);
    return 0;
}
