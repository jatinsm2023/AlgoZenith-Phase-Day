#include <bits/stdc++.h>
using namespace std;

class Union{
    int n,setsize;
    vector<int> parent,rank;
    
public:
    Union(int a){
        n = a;
        setsize = a;
        parent.assign(n,0);
        rank.assign(n,1);
        for( int i=0; i<n; i++){
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
};

signed main(){
    
     ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q;
    cin>>n>>q;
    Union uf(n);
    
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        
        if(a==0){
            uf.merge(b,c);
        }
        else if(a==1) {
            if(uf.find(b)==uf.find(c)){
                cout<<1<<'\n';
            }
            else cout<<0<<'\n';
        }
    }
}