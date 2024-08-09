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
int dp[100][100][100];
int n;

// calculating maximum value
int rec( int i, int x, int item_left ){ // i - index, x - capacity remaining
    if(i==n){
        return 0; // we can't take more
    }
    if(dp[i][x][item_left]!=-1){
        return dp[i][x][item_left]; // if it's already calculated
    }
    int ans = rec(i+1,x,item_left); // don't take this item
    if(weight[i]<=x){ // can we take this item
        // if yes - then what is better
        // decide between max(donttake,cantake)
        ans = max(ans,rec(i+1,x-weight[i],item_left-1)+value[i]); 
    }
    // cache the solution and return ans
    return dp[i][x][item_left] = ans;
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
    int K;
    cin>>K;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W,K)<<endl;

}