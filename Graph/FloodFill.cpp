#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &graph, int sr, int sc, int newColor, int initialColor)
{
    if (sr >= graph.size() || sc >= graph[0].size() || sr < 0 || sc < 0)
    {
        return;
    }
    if (graph[sr][sc] == initialColor)
    {
        /* code */
        graph[sr][sc] = newColor;
    }
    else
        return;

    solve(graph, sr + 1, sc, newColor, initialColor);

    solve(graph, sr - 1, sc, newColor, initialColor);

    solve(graph, sr, sc - 1, newColor, initialColor);

    solve(graph, sr, sc + 1, newColor, initialColor);
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> graph{
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 0, 0}};
    vector<vector<int>> ans = graph;
    solve(graph, 0, 1, 3, graph[0][1]);
    for (auto &&i : graph)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
