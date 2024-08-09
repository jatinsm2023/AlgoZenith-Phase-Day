#include <bits/stdc++.h>
using namespace std;

map<int,int> lad;
int n,m;

const int INF = 1e9;
vector<int> dis;

void bfs(){
        
    dis[1]=0;
    queue<int> pq;
    pq.push(1);
    
    while(!pq.empty()){
        int x = pq.front();
        pq.pop();
    
        for( int i=1; i<7; i++){
            int xx = x+i;
            if(xx>100)continue;
            if(lad.find(xx)==lad.end() ){
                if(dis[xx]>dis[x]+1){ 
                    dis[xx]=dis[x]+1;
                    pq.push(xx);
                }
            }
            else {
                if(dis[lad[xx]]>dis[x]+1){ 
                    dis[lad[xx]]=dis[x]+1;
                    pq.push(lad[xx]);
                }
            }
        }
    }
}


void solve(){
    dis.assign(101,INF);
    cin>>n;
    lad.clear();
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        lad[a]=b;
    }
    cin>>m;
    for( int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        lad[a]=b;
    }
    
    bfs();
    
    if(dis[100]==INF){
        cout<<-1<<'\n';
    }
    else cout<<dis[100]<<'\n';
}

signed main()
{
   int t;
   cin>>t;
   while(t--){
       solve();
   }
}