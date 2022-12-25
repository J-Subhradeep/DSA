#include <bits/stdc++.h>
using namespace std;
bool is_valid_color(vector<vector<int>> &graph, int c, int node, vector<int> &color)
{
    for (auto &&i : graph[node])
    {
        if (color[i] == c)
        {
            return false;
        }
    }
    return true;
}
bool color_graph(vector<vector<int>> &graph, vector<int> &color, int node, int m)
{
    if (node == graph.size())
    {
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (is_valid_color(graph, i, node, color))
        {
            color[node] = i;
            if (color_graph(graph, color, node + 1, m))
            {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<int> v;
    vector<vector<int>> graph(n, v);
    vector<int> color(n, 0);
    int M;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout << "Enter the value of m :";
    cin >> M;
    cout << color_graph(graph, color, 0, M);
    return 0;
}
