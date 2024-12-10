#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve(){
    int n;
    cin >> n;
    int ans = 1;
    for(int i=0; i<=n; i++){
        if((n>>i)&1){
            ans = ans * 2;
        }
    }
    cout<<n+1-ans<<" "<<ans<<endl;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}