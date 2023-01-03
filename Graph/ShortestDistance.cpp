#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int, int>>> &graph, stack<int> &s, int node, vector<int> &vis)
{
    vis[node] = 1;
    for (auto &&i : graph[node])
    {
        if (!vis[i.first])
            dfs(graph, s, i.first, vis);
    }
    s.push(node);
}
vector<int> shortestDistance(vector<vector<pair<int, int>>> graph, int src)
{
    vector<int> dist(graph.size(), 1e9);
    dist[src] = 0;
    vector<int> vis(graph.size(), 0);
    stack<int> s;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
            dfs(graph, s, i, vis);
    }
    while (!s.empty())
    {
        int node = s.top();
        s.pop();
        int distOfNode = dist[node];
        for (auto &&i : graph[node])
        {
            if (distOfNode + i.second < dist[i.first])
            {
                dist[i.first] = distOfNode + i.second;
            }
        }
    }

    return dist;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }
    vector<int> result = shortestDistance(graph, 5);
    for (auto &&i : result)
    {
        cout << i << " ";
    }

    return 0;
}
