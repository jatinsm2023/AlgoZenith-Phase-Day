#include <bits/stdc++.h>
using namespace std;

#define int long long

using state = pair<int,int>;

class Union{
    int n,setsize;
    vector<int> parent,rank;
    
public:
    Union(int a){
        n = a;
        setsize = a;
        parent.assign(n+1,0);
        rank.assign(n+1,1);
        for( int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    
    int find(int x){
        if(x==parent[x])return x;
        else return parent[x]=find(parent[x]);
    }
    
    void merge( int x, int y){
        int xroot = find(x);
        int yroot = find(y);
        if(xroot!=yroot){
            if(rank[xroot]>=rank[yroot]){
                parent[yroot]=xroot;
                rank[xroot]+=rank[yroot];
            }
            else {
                parent[xroot]=yroot;
                rank[yroot]+=rank[xroot];
            }
            setsize-=1;
        }
    }

    int getsize(){
        return setsize;
    
    }
};

// 3 3 5
// 1 2
// 2 3
// 3 1
// 2
// 1 2
// 2
// 1 1
// 2

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m,q;
    cin>>n>>m>>q;
    
    vector<state> edges(m+1,{-1,-1});
    
    for( int i=1; i<=m;i++){
        int a,b;
        cin>>a>>b;
        edges[i]={a,b};
    }
    vector<int> marked(m+1,0);
    vector<state> queries(q);
    for( int i=0; i<q; i++){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            queries[i]={1,x};
            marked[x]=1;
        }
        else{
            queries[i]={2,-1};
        }
    }
    
    Union uf(n);
    for( int i=1; i<=m; i++){
        if(!marked[i]){
            uf.merge(edges[i].first,edges[i].second);
        }
    }
    vector<int> ans;
    
    for( int i=q-1; i>=0;i--){  // make sure about reverse thing
        if(queries[i].first==1){
            uf.merge(edges[queries[i].second].first,edges[queries[i].second].second);
        }else{
            ans.push_back(uf.getsize());
        }
    }
    reverse(ans.begin(),ans.end());
    for( auto v: ans){
        cout<<v<<'\n';
    }
}

