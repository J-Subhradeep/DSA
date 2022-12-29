#include <bits/stdc++.h>
using namespace std;
bool bfs(vector<vector<int>> &graph, vector<int> &color, int src)
{
    color[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    while (!q.empty())
    {
        /* code */
        int node = q.front().first;
        int nodeColor = q.front().second;
        q.pop();
        for (auto &&i : graph[node])
        {
            if (color[i] == color[node])
                return false;
            else if (color[i] == -1)
            {
                color[i] = !nodeColor;
                q.push({i, color[i]});
            }
        }
    }
    return true;
}
bool solve(vector<vector<int>> &g, vector<int> &color)
{
    for (int i = 0; i < g.size(); i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(g, color, i))
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
