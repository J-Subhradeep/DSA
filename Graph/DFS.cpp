#include <bits/stdc++.h>
using namespace std;
void DFS(vector<int> &result, vector<vector<int>> &graph, int node, vector<int> &vis)
{
    vis[node] = 1;
    result.push_back(node);

    for (auto &&i : graph[node])
    {
        if (!vis[i])
        {
            DFS(result, graph, i, vis);
        }
    }
}
void dfs(vector<int> &result, vector<vector<int>> &graph, int n)
{

    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            DFS(result, graph, i, vis);
        }
    }
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<vector<int>> graph(n, v);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> result;
    dfs(result, graph, n);
    for (auto &&i : result)
    {
        cout << i << " ";
    }

    return 0;
}
