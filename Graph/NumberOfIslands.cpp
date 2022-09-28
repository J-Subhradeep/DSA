#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &graph, int n, int m, vector<vector<int>> &vis)
{
    vis[n][m] = 1;
    queue<pair<int, int>> q;
    pair<int, int> p;
    q.push(make_pair(n, m));
    while (!q.empty())
    {
        p = q.front();
        q.pop();

        for (int delRow = -1; delRow <= 1; delRow++)
        {
            for (int delCol = -1; delCol <= 1; delCol++)
            {
                int neighbourRow = delRow + p.first;
                int neighbourCol = delCol + p.second;

                if (neighbourRow >= 0 and neighbourCol >= 0 and neighbourRow < graph.size() and neighbourCol < graph[0].size() and graph[neighbourRow][neighbourCol] == 1 and !vis[neighbourRow][neighbourCol])
                {
                    cout << "neighbourRow: " << neighbourRow << " neighbourCol: " << neighbourCol << endl;
                    vis[neighbourRow][neighbourCol] = 1;
                    q.push({neighbourRow, neighbourCol});
                }
            }
        }
    }
}
int traverse(vector<vector<int>> &graph, int n, int m)
{

    int count = 0;
    vector<int> v(m, 0);
    vector<vector<int>> vis(n, v);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            /* code */
            if (!vis[i][j] && graph[i][j])
            {
                bfs(graph, i, j, vis);
                count++;
            }
        }
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m, 0);
    vector<vector<int>> graph(n, v);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }
    int a = traverse(graph, n, m);
    cout << endl
         << a << endl;
    return 0;
}
