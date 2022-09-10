#include <bits/stdc++.h>
using namespace std;
vector<int> BFS(vector<int> &vis, vector<vector<int>> &graph)
{
    queue<int> q;
    vector<int> result;
    q.push(0);
    vis[0] = 1;
    result.push_back(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // result.push_back(node);

        for (auto &&i : graph[node])
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
                result.push_back(i);
            }
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> vis(n, 0);
    vector<int> v;
    vector<vector<int>> graph(n, v);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    v = BFS(vis, graph);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}
