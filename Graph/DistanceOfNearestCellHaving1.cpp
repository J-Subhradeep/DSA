#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &graph, vector<vector<int>> &vis, vector<vector<int>> &dis)
{
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < graph.size(); i++)
    {
        /* code */
        for (int j = 0; j < graph[0].size(); j++)
        {
            if (graph[i][j] == 1)
            {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }
    int rowD[] = {1, -1, 0, 0};
    int colD[] = {0, 0, -1, 1};
    while (!q.empty())
    {
        /* code */
        int i = q.front().first.first;
        int j = q.front().first.second;
        int d = q.front().second;
        q.pop();
        d++;
        for (int y = 0; y < 4; y++)
        {
            /* code */
            if (i + rowD[y] >= 0 && i + rowD[y] < graph.size() && j + colD[y] >= 0 && j + colD[y] < graph[0].size() & !vis[i + rowD[y]][j + colD[y]])
            {
                vis[i + rowD[y]][j + colD[y]] = 1;
                dis[i + rowD[y]][j + colD[y]] = d;
                q.push({{i + rowD[y], j + colD[y]}, d});
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> graph{
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0}};
    vector<vector<int>> vis(graph.size(), vector<int>(graph[0].size(), 0));
    vector<vector<int>> dis(graph.size(), vector<int>(graph[0].size(), 0));

    solve(graph, vis, dis);
    for (auto &&i : dis)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
