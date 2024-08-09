#include <bits/stdc++.h>
using namespace std;
 
#define int long long
vector<vector<int>> g;

inline int max(int a, int b){
    if(a>b)return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    g.resize(n+1);
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int max_size = 0;
    for( int i=0; i<g.size(); i++){
        max_size = max(max_size, g[i].size());
    }
    cout<<max_size+1<<'\n';
}