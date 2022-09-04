#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> g[n+1];
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i=0;i<n;i++)
    {
        cout<<i<<"-->";
        for (auto &&j : g[i])
        {
            cout<<j<<"->";
        }
        cout<<endl;
        
    }
    
    
    
    return 0;
}