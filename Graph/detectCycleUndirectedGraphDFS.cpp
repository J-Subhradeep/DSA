#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &graph, vector<int> &vis, int src, int parent)
{
    vis[src] = 1;
    for (auto &&i : graph[src])
    {
        if (!vis[i])
        {
            if (
                dfs(graph, vis, i, src))
                return true;
        }
        else if (i != parent)
            return true;
    }
    return false;
}
bool has_cycle(vector<vector<int>> &graph)
{

    vector<int> vis(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            /* code */
            if (dfs(graph, vis, i, -1))
                return true;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << has_cycle(g) << endl;
    return 0;
}
