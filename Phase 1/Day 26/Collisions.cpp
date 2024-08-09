#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for( int i=0; i<n ;i++){
            int x,y;
            cin>>x>>y;
            a[i]=x*y;
        }
        for( int i=0; i<m ;i++){
            int x,y;
            cin>>x>>y;
            b[i]=x*y;
        }
        map<int,int> mp;
        for( int i=0; i<n; i++)
        {
            mp[a[i]]++;
        }
        int ans=0;
        for( int i=0; i<m ;i++)
        {
            if(mp[b[i]]>0){
                ans++;
                mp[b[i]]--;
            }
        }
        cout<<ans<<'\n';
    }
}