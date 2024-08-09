#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define print(v) for( auto x : v)cout<<x<<' '; cout<<endl;
#define yes() cout<<'YES<<endl';
#define no() cout<<'NO<<endl';
using state = pair<int,int>;
const int mod = 1e9+7;

int sum(int n, int m){
    if(n%2==0){
        return ((n/2)%m)*((n+1)%m)%m;
    }
    return ((n)%m)*((n+1)/2)%m;
}
int get(int l, int r, int m){

    int ans = (sum(r,m)%m - sum(l-1,m)%m)%m;
    return ans%mod;
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int l,r,m;
        cin>>l>>r>>m;
        cout<<get(l,r,m)<<'\n';
    }
}