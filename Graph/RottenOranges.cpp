#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &graph, vector<vector<int>> &vis, int &time)
{
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[0].size(); j++)
        {
            if (graph[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int m = p.first.first;
        int n = p.first.second;
        int t = p.second;
        if (t > time)
            time = t;
        t++;
        if (m + 1 < graph.size() && n < graph.size() && m + 1 >= 0 && n >= 0 && vis[m + 1][n] == 1)
        {
            vis[m + 1][n] = 2;
            q.push({{m + 1, n}, t});
        }
        if (m - 1 < graph.size() && n < graph.size() && m - 1 >= 0 && n >= 0 && vis[m - 1][n] == 1)
        {
            vis[m - 1][n] = 2;
            q.push({{m - 1, n}, t});
        }
        if (m < graph.size() && n + 1 < graph.size() && m >= 0 && n + 1 >= 0 && vis[m][n + 1] == 1)
        {
            vis[m][n + 1] = 2;
            q.push({{m, n + 1}, t});
        }
        if (m < graph.size() && n - 1 < graph.size() && m >= 0 && n - 1 >= 0 && vis[m][n - 1] == 1)
        {
            vis[m][n - 1] = 2;
            q.push({{m, n - 1}, t});
        }
    }
}
int required_time(vector<vector<int>> &graph)
{
    vector<vector<int>> vis = graph;
    int time = 0;
    solve(graph, vis, time);
    return time;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> graph{
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1},

    };
    cout << required_time(graph);
    return 0;
}
