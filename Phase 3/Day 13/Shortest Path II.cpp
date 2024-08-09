#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,m,q;

vector<vector<int>> dis;

signed main()
{
    cin>>n>>m>>q;
   
    dis.assign(n+1,vector<int>(n+1,1e18));

    for( int i=0; i<m ;i++){
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=dis[b][a] = min(dis[a][b],c);
    }

    for( int i=1; i<=n ;i++){
        dis[i][i]=0;
    }
    
    for( int k=1; k<=n; k++){
        for( int i=1; i<=n ;i++){
            for( int j=1;j<=n ;j++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    for( int i=1; i<=n ;i++){
        for( int j=1; j<=n ;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        if(dis[x][y]==1e18) cout<<-1<<endl;
        else cout<<dis[x][y]<<endl;
    }
}