#include <bits/stdc++.h>
using namespace std;
int char_to_int(char c) { return c - 'a'; }
char int_to_char(int i) { return 'a' + i; }
vector<int> toposort(vector<vector<int>> &graph)
{
    vector<int> indegrees(graph.size(), 0);
    for (auto &&i : graph)
    {
        for (auto &&j : i)
        {
            indegrees[j]++;
        }
    }
    queue<int> q;
    vector<int> res;
    for (int i = 0; i < indegrees.size(); i++)
    {
        if (!indegrees[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        res.push_back(node);
        q.pop();
        for (auto &&i : graph[node])
        {

            if (!--indegrees[i])
            {
                q.push(i);
            }
        }
    }
    return res;
}
vector<char> solve(vector<string> words, int k)
{
    vector<vector<int>> graph(k);
    for (int i = 0; i < words.size() - 1; i++)
    {
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.size(), s2.size());
        for (int i = 0; i < len; i++)
        {
            if (s1.at(i) != s2.at(i))
            {
                graph[char_to_int(s1.at(i))].push_back(char_to_int(s2.at(i)));
                break;
            }
        }
    }
    vector<int> res = toposort(graph);
    vector<char> result;
    for (auto &&i : res)
    {
        result.push_back(int_to_char(i));
    }
    return result;
}
int main(int argc, char const *argv[])
{
    vector<string> words = {
        "baa",
        "abcd",
        "abca", "cab", "cad"};
    int k = 5;
    vector<char> res = solve(words, k);
    for (auto &&i : res)
    {
        cout << i << " ";
    }

    return 0;
}
