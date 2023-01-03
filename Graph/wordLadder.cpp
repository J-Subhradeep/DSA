#include <bits/stdc++.h>
using namespace std;
int wordLadder(vector<string> &wordList, string start, string end)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({start, 1});
    int step = 1;
    st.erase(start);
    while (!q.empty())
    {
        string s = q.front().first;
        step = q.front().second;
        q.pop();
        if (s == end)
            return step;
        for (int i = 0; i < s.size(); i++)
        {
            char original = s[i];
            for (char j = 'a'; j <= 'z'; j++)
            {
                string s1 = s;
                s1[i] = j;
                if (st.count(s1))
                    q.push({s1, step + 1});
                st.erase(s1);
            }
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    vector<string> arr{"hot", "lot", "log", "cot", "cog"};
    cout << wordLadder(arr, "hot", "log");
    return 0;
}
