#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &graph, vector<vector<int>> &vis, int sr, int sc)
{
    if (sr < graph.size() && sr >= 0 && sc < graph.size() && sc >= 0 && !vis[sr][sc] && graph[sr][sc] == 'O')
        vis[sr][sc] = 1;
    else
        return;

    dfs(graph, vis, sr + 1, sc);
    dfs(graph, vis, sr - 1, sc);
    dfs(graph, vis, sr, sc - 1);
    dfs(graph, vis, sr, sc + 1);
}
void solve(vector<vector<char>> &graph, vector<vector<char>> &res, vector<vector<int>> &vis)
{
    for (int i = 0; i < graph.size(); i++)
    {
        /* code */

        if (graph[0][i] == 'O' && vis[0][i] == 0)
            dfs(graph, vis, 0, i);
        if (graph[(graph.size() - 1)][i] == 'O' && vis[(graph.size() - 1)][i] == 0)
            dfs(graph, vis, graph.size() - 1, i);
        if (graph[i][0] == 'O' && vis[i][0] == 0)
            dfs(graph, vis, i, 0);
        if (graph[i][graph[0].size() - 1] == 'O' && vis[i][graph[0].size() - 1] == 0)
            dfs(graph, vis, i, graph[0].size() - 1);
    }
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            if (graph[i][j] == 'O' && vis[i][j] == 0)
                res[i][j] = 'X';
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<vector<char>> graph{
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};
    vector<vector<int>> vis(graph.size(), vector<int>(graph[0].size(), 0));
    vector<vector<char>> res = graph;

    solve(graph, res, vis);
    for (auto &&i : res)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
