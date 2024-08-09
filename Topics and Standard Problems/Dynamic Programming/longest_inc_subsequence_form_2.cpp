#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define print(v) for( auto x : v)cout<<x<<' '; cout<<endl;
#define yes() cout<<'YES<<endl';
#define no() cout<<'NO<<endl';
using state = pair<int,int>;
const int mod = 1e9+7;
inline void add(int &a, int b){a += b;if (a >= mod)a -= mod;}
inline void sub(int &a, int b){a -= b;if (a < 0)a += mod;}
inline int mul(int a, int b){return (int)((long long)a * b % mod);}

int n;
vector<int> arr;
int dp[100100];
int rec(int level, vector<int> & arr){
    if(level<0){
        return 0;
    }
    if(dp[level]!=-1){
        return dp[level];
    }
    int ans = 1;

    for( int i=0 ;i<level; i++){
        if(arr[i]<=arr[level]){
            ans=max(ans,rec(i,arr)+1);
        }
    }

    return dp[level]=ans;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for( int i=0; i<n ;i++){
        cin>>arr[i];
    }
    int ans = 0;
    for( int i=0; i<n ;i++){
        ans = max(ans,rec(i,arr));
    }
    cout<<ans<<endl;
}