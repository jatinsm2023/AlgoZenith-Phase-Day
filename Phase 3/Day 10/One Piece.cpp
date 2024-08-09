#include <bits/stdc++.h>
using namespace std;

#define int long long
using state = pair<int,int>;
#define F first
#define S second

// Global Variables
int n,m;
vector<vector<int>> g;

// directions
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool is_valid( int x, int y){
    if(x>=0 && y>=0 && x<n && y<m)return true;
    return false;
}
void solve(){
    cin>>n>>m;
    g.assign(n,vector<int>(m));
    for( int i=0 ;i<n; i++){
        for( int j=0; j<m; j++){
            cin>>g[i][j];
        }
    }
    
    vector<vector<int>> dis(n,vector<int>(m,1e9));
    dis[0][0]=0;
    
    deque<state> dq;
    dq.push_back({0,0});
    
    while(!dq.empty()){
        state node = dq.front();
        dq.pop_front();
        int x = node.F;
        int y = node.S;
        for( int i=0; i<4; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            int w = (i+1==g[x][y])?0:1;
            if(is_valid(xx,yy)){
                if(dis[xx][yy]>dis[x][y]+w){
                    dis[xx][yy]=dis[x][y]+w;
                    if(w)dq.push_back({xx,yy});
                    else dq.push_front({xx,yy});
                }
            }
            
        }
    }
    // for( int i=0 ;i<n; i++){
    //     for( int j=0; j<m; j++){
    //         cout<<dis[i][j]<<'\t';
    //     }
    //     cout<<'\n';
    // }
    
    if(dis[n-1][m-1]==1e9){
        cout<<-1<<'\n';
    }
    else {
        cout<<dis[n-1][m-1]<<'\n';
    }
}

signed main()
{
    solve();

}