#include <bits/stdc++.h>
using namespace std;
void dfs(int i, vector<vector<int>> &graph, vector<int> &vis, stack<int> &s)
{
    vis[i] = 1;
    for (auto &&it : graph[i])
    {
        if (!vis[it])
            dfs(it, graph, vis, s);
    }
    s.push(i);
}
void solve(vector<vector<int>> &graph)
{
    vector<int> vis(graph.size(), 0);
    stack<int> s;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
            dfs(i, graph, vis, s);
    }
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        cout << s.top() << " ";
        s.pop();
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
