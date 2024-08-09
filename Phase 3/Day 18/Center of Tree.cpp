#include <bits/stdc++.h>
using namespace std;
 
#define int long long
int n;
vector<vector<int>> g;
vector<int> depth;
vector<int> parent;

void dfs(int st, int dep, int par){
    parent[st]=par;
    depth[st] = dep;
    for(auto u : g[st]){
        if(u!=parent[st]){
            dfs(u, dep+1,st);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    g.resize(n+1);
    depth.assign(n+1,-1);
    for(int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    parent.assign(n+1,-1);
    dfs(1,0,0);
    int max_depth = -1, max_node = -1;
    for(int i = 1; i <= n; i++){
        if(depth[i] > max_depth){
            max_depth = depth[i];
            max_node = i;
        }
    }
    depth.assign(n+1,-1);
    parent.assign(n+1,-1);
    dfs(max_node,0,0);
    max_depth = -1;
    
    for(int i = 1; i <= n; i++){
        if(depth[i] > max_depth){
            max_depth = depth[i];
            max_node = i;
        }
    }
    // cout << max_depth << endl;
    if(max_depth%2!=0){
        cout<<-1<<'\n';
    }
    else{
        int center = max_node;
        for(int i = 0; i < max_depth/2; i++){
            center = parent[center];
        }
        cout<<center<<'\n';
    }
}

  