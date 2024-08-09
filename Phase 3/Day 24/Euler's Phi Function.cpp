#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define print(v) for( auto x : v)cout<<x<<' '; cout<<endl;
#define yes() cout<<'YES<<endl';
#define no() cout<<'NO<<endl';
using state = pair<int,int>;

int phi(int n){
    int ans = n;
    for( int i=2; i<=n ;i++){
        bool fein = false;
        while(n%i==0){
            n/=i;
            fein = true;
        }
        if(fein){
            ans/=i;
            ans*=(i-1);
        }
    }

    // if n is prime number then -- 
    if(n>1){
        ans/=n;
        ans*=(n-1);
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    cout<<phi(n)<<'\n';
}