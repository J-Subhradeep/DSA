#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    set<pair<char, string>> pairs;
    set<char> pt;
    set<string> st;
    vector<string> str;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == ' ' || i == s.size() - 1)
        {
            str.push_back(temp);
            temp.clear();
        }
        else
            temp += s.at(i);
    }
    str[str.size() - 1] += s[s.size() - 1];

    if (pattern.size() != str.size())
        return false;
    for (int i = 0; i < str.size(); i++)
    {
        pairs.insert({pattern.at(i), str[i]});
    }

    for (auto i : pattern)
    {
        pt.insert(i);
    }

    for (auto i : str)
    {
        st.insert(i);
    }

    if (pairs.size() == pt.size() && pairs.size() == st.size())
        return true;
    else
        return false;
}
int main(int argc, char const *argv[])
{
    cout << wordPattern("abba", "dog cat cat dog");
    return 0;
}
