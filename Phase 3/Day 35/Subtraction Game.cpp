#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;

// one way to do it 
// int dp[2000010];
// int rec( int x ){
//     if(x==0)return 0;
//     int ans = 0;
//     if(dp[x]!=-1)return dp[x];
//     for( int m = 1; (1<<m)<=x; m++){
//         if(rec(x-(1<<m))==0){
//             ans = 1;
//             break;
//         }
//     }
//     return dp[x] = ans;
// }
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        // memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
        // if(rec(n))cout<<"Abhishek\n";
        // else cout<<"Vivek\n";
        if(n%3==0)cout<<"Vivek\n";
        else cout<<"Abhishek\n";
    }
}