#include <bits/stdc++.h>
using namespace std;

#define int long long
using state = pair<int,int>;
#define F first
#define S second

// Global Variables
int n,m;
vector<vector<state>> g;                               // 0-1 BFS IDEA

void solve(){
    cin>>n>>m;
    g.assign(n+1 , vector<pair<int,int>>());    
    for( int i=0; i<m ;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back({b,0});
        g[b].push_back({a,1});
    }
    vector<int> dis(n + 1, 1e9);
    deque<int> dq;
    
    dis[1]=0;
    
    dq.push_back(1);
    
    while(!dq.empty()){
        int node = dq.front();
        dq.pop_front();
        
        for(auto v: g[node]){
            int neigh = v.F;
            int weigh = v.S;
            
            if(dis[neigh]>dis[node]+weigh){
                dis[neigh] = dis[node]+weigh;
                if(weigh==0){
                    dq.push_front(neigh);
                }else {
                    dq.push_back(neigh);
                }
            }
        }
    }

  if (dis[n] == 1e9)cout << -1<<endl;
	else cout << dis[n]<<endl;
}

signed main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}