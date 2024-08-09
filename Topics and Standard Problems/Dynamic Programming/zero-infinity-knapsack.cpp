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

int value[1000];
int weight[1000];
int dp[1000][1000];
int n;

// calculating maximum value
int rec( int i, int x ){ // i - index, x - capacity remaining
    if(i==n){
        return 0; // we can't take more
    }
    if(dp[i][x]!=-1){
        return dp[i][x]; // if it's already calculated
    }
    int ans = rec(i+1,x); // don't take this item
    if(weight[i]<=x){ // can we take this item
        // if yes - then what is better
        // decide between max(donttake,cantake)
        ans = max(ans,rec(i,x-weight[i])+value[i]); 
        // don't go to the next level after we took the element, the donttake case will handle that
    }
    // cache the solution and return ans
    return dp[i][x] = ans;
}


signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for( int i=0; i<n ;i++){
        cin>>weight[i]>>value[i];
    }
    int W;
    cin>>W;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W)<<endl;
}