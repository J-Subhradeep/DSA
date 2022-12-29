#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, int src, vector<int> &safeNodes)
{
    vis[src] = 1;
    pathVis[src] = 1;
    for (auto &&i : graph[src])
    {
        if (!vis[i])
        {
            if (dfs(graph, vis, pathVis, i, safeNodes))
                return true;
        }
        else if (pathVis[i])
            return true;
    }
    pathVis[src] = 0;
    safeNodes[src] = 1;
    return false;
}
vector<int> safeNodeList(vector<vector<int>> &graph)
{
    vector<int> vis(graph.size(), 0);
    vector<int> pathVis(graph.size(), 0);
    vector<int> safeNodes(graph.size(), 0);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            /* code */
            dfs(graph, vis, pathVis, i, safeNodes);
        }
    }

    return safeNodes;
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
    vector<int> safenodes = safeNodeList(graph);
    for (int i = 0; i < safenodes.size(); i++)
    {
        /* code */
        if (safenodes[i])
        {
            cout << i << " ";
            /* code */
        }
    }
    cout << endl;

    return 0;
}
