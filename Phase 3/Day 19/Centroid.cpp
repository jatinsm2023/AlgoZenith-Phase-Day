#include <bits/stdc++.h>
using namespace std;
 
#define int long long
int n;
vector<vector<int>> g;
vector<int> subtreesz;

void dfs( int node, int par){
    subtreesz[node] = 1;
    for(auto &child : g[node]){
        if(child == par) continue;
        dfs(child, node);
        subtreesz[node] += subtreesz[child];
    }
}

int centroid( int node, int par ){
    for(auto &child : g[node]){
        if(child == par) continue;
        if(subtreesz[child] > n/2) return centroid(child, node);
    }
    return node;
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    g.resize(n+1);
    subtreesz.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    int cent = centroid(1, 0);
    cout<<cent<<endl;
}