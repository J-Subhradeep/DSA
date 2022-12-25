#include <bits/stdc++.h>
using namespace std;
bool is_palindrom(string str)
{
    for (int i = 0; i <= str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            return false;
        }
    }
    return true;
}
void solve(string str, vector<string> ds, int index)
{
    if (index == str.length())
    {
        /* code */
        for (auto &&i : ds)
        {
            cout << i << ",";
        }
        cout << endl;

        return;
    }

    for (int i = index; i < str.length(); i++)
    {
        if (is_palindrom(str.substr(index, i - index + 1)))
        {
            ds.push_back(str.substr(index, i - index + 1));
            solve(str, ds, index + 1);
            ds.pop_back();
        }
    }
}
int main(int argc, char const *argv[])
{

    string s = "AABB";
    solve(s, vector<string>(), 0);
    return 0;
}
