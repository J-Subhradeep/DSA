#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>> &graph, vector<int> &vis, int index)
{
    queue<pair<int, int>> q;
    vis[index] = 1;
    q.push({index, -1});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (auto &&i : graph[p.first])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push({i, p.first});
            }
            else if (i != p.second)
                return true;
        }
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
            if (bfs(graph, vis, i))
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
