#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, int src)
{
    vis[src] = 1;
    pathVis[src] = 1;
    for (auto &&i : graph[src])
    {
        if (!vis[i])
        {
            if (dfs(graph, vis, pathVis, i))
                return true;
        }
        else if (pathVis[i])
            return true;
    }
    pathVis[src] = 1;
    return false;
}
bool detectCycle(vector<vector<int>> &graph)
{
    vector<int> vis(graph.size(), 0);
    vector<int> pathVis(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            /* code */
            if (dfs(graph, vis, pathVis, i))
                return true;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    cout << detectCycle(graph);
    return 0;
}
