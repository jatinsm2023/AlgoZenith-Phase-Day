#include <bits/stdc++.h>
using namespace std;
 
#define int long long
int n,m;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
vector<int> vis;
bool is_cicle = false;

void dfs(int node){
    vis[node] = 1;
    for(auto it:g[node]){
        if(vis[it]==0){
            dfs(it);
        }
        else if(vis[it]==1){
            is_cicle = true;
        }
    }
    vis[node] = 2;
}
void kahn(){
    priority_queue<int,vector<int>, greater<int>> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.top();
        q.pop();
        topo.push_back(node);
        for(auto it:g[node]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
}
void TakeGraph(){
    cin>>n>>m;
    g.resize(n+1);
    indeg.resize(n+1,0);
    vis.resize(n+1,0);
    for( int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    TakeGraph();
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
    if(is_cicle){
        cout<<-1;
        return 0;
    }
    kahn();
    for(auto it:topo){
        cout<<it<<" ";
    }
}