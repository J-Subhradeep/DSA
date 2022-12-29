#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<vector<int>> &graph, vector<int> &vis, stack<int> &s, vector<int> &indegree)
{
    queue<int> q;

    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            /* code */
            q.push(i);
        }
    }
    vector<int> v;
    while (!q.empty())
    {
        int node = q.front();
        v.push_back(node);
        q.pop();

        for (auto &&i : graph[node])
        {

            indegree[i] -= 1;
            if (indegree[i] == 0)
            {

                q.push(i);
            }
        }
    }
    return v;
}
void solve(vector<vector<int>> &graph)
{
    vector<int> vis(graph.size(), 0);
    stack<int> s;
    vector<int> indegree(graph.size(), 0);
    for (auto &&i : graph)
    {
        for (auto &&j : i)
        {
            indegree[j] += 1;
        }
    }

    vector<int> res = bfs(graph, vis, s, indegree);
    for (auto &&i : res)
    {
        cout << i << " ";
    }
    cout << endl;
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
    solve(graph);

    return 0;
}