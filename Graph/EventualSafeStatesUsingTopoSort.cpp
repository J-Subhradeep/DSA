#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &g, vector<int> &indegree)
{
    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> toposort;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        toposort.push_back(node);
        for (auto &&i : g[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }
    return toposort;
}
vector<int> solve(vector<vector<int>> &graph)
{
    vector<vector<int>> g(graph.size());
    // Reverse the edges of graph.
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            g[graph[i][j]].push_back(i);
        }
    }
    // getting indegrees of nodes
    vector<int> indegree(g.size(), 0);
    for (auto &&i : g)
    {
        for (auto &&j : i)
        {
            indegree[j] += 1;
        }
    }

    // getting topological sort
    vector<int> toposort = bfs(g, indegree);
    sort(toposort.begin(), toposort.end());
    return toposort;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> graph{
        {1}, {2}, {3, 4}, {4, 5}, {}, {6}, {4}, {6}, {1, 9}, {10, 11}, {8}, {}};
    vector<int> safenodes = solve(graph);
    for (auto &&i : safenodes)
    {
        cout << i << " ";
    }

    return 0;
}
