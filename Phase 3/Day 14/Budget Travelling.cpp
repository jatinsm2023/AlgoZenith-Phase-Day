#include <bits/stdc++.h>
using namespace std;

#define int long long
using state = pair<int,int>;
#define F first
#define S second

int n,m,k;

vector<vector<state>> g;
vector<int> cost;
int vis[100100][110]; // first -> Node
int dis[100100][10]; // second -> Remaining Petrol at that node


void Dijkshtra(int sc, int en, int limit){
    for( int i=0; i<=n ;i++){
        for( int j=0; j<=k ;j++){
            dis[i][j] = 1e18;
            vis[i][j] = 0;
        }
    }

    priority_queue<pair<int,state>, vector<pair<int,state>>, greater<pair<int,state>>> pq;

    pq.push({0,{sc,0}});
    dis[sc][0] = 0;

    while(!pq.empty()){
        auto next = pq.top();pq.pop();
        int cur_dist = next.F;
        int u = next.S.F;
        int petrol = next.S.S;
        if(vis[u][petrol]) continue;
        vis[u][petrol] = 1;

        for( auto v : g[u]){
            int to = v.F;
            int w = v.S;
            if(petrol>=w){
                if(!vis[to][petrol-w] && dis[to][petrol-w] > cur_dist+){
                    dis[to][petrol-w] = cur_dist;
                    pq.push({dis[to][petrol-w],{to,petrol-w}});
                }
            }
        }

    if(petrol<limit)
        if(!vis[u][petrol+1] && dis[u][petrol+1]>cur_dist+cost[u]){
            dis[u][petrol+1]=cur_dist+cost[u];
            pq.push({dis[u][petrol+1],{u,petrol+1}});
        }
    }

    cout<<dis[en][0]<<'\n';
}
signed main(){
    int sc,en;

    cin>>n>>m;
    g.resize(n+1);
    cost.resize(n+1);
    for( int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    for( int i=1; i<=n; i++){
        cin>>cost[i];
    }
    cin>>sc>>en>>k;
    Dijkshtra(sc,en,k);
}