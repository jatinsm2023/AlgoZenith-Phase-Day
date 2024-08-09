#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> vis;
vector<int> par;

bool finded = false;
void dfs( int node )
{
    vis[node]=1;
    for( auto v: g[node]){
        if(!vis[v]){
            par[v]= node;
            dfs(v);
        }
        else if(par[node]!=v){
            finded = true;
            return;
        }
    }
}

int main()
{
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    par.assign(n+1,0);

    for( int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for( int i=1; i<=n ;i++)
    {
        if(!vis[i]){
            dfs(i);
        }
    }
    if( finded){
        cout<<"YES"<<'\n';
    }
    else {
        cout<<"NO"<<'\n';
    }
}