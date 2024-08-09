#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

using state = pair<int,int>;

// global variables
int n,m;
vector<pair<state,int>> g;
vector<int> dis;

void Bellman(){
    dis[1]=0;
    for( int i=0; i<n-1; i++){
        for( auto v : g){
            int a = v.F.F;
            int b = v.F.S;
            int c = v.S;
            
            if(dis[a]+c<dis[b]){
                dis[b]= dis[a]+c;
            }
        }
    }
    
    bool is_cycle = false;
     for( auto v : g){
        int a = v.F.F;
        int b = v.F.S;
        int c = v.S;
        
        if(dis[a]+c<dis[b]){
            is_cycle = true;
            break;
        }
    }
    
    if(is_cycle){
        cout<<-1<<'\n';
        return;
    }
    
    cout<<-dis[n]<<'\n';
    return;
}

signed main()
{
    cin>>n>>m;
    dis.assign(n+1,1e18);
    
    for( int i=0; i<m ;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g.push_back({{a,b},-c});
    }
    
    Bellman();
}