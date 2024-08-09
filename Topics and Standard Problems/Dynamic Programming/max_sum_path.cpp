#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define print(v) for( auto x : v)cout<<x<<' '; cout<<endl;
#define yes() cout<<'YES<<endl';
#define no() cout<<'NO<<endl';
using state = pair<int,int>;
const int mod = 1e9+7;
const int INF = 1e9;
inline void add(int &a, int b){a += b;if (a >= mod)a -= mod;}
inline void sub(int &a, int b){a -= b;if (a < 0)a += mod;}
inline int mul(int a, int b){return (int)((long long)a * b % mod);}

int n;
int arr[10010][10010];
int dp[10010][10010];
int done[10010][10010]; // we need it to check that a particular state is done or not because sum can be -1 also so checking dp!=-1 wont help

int rec( int x, int y){
    if(x<0 || y<0)return -INF;
    if(x==0 && y==0){
        return arr[x][y];
    }
    if(done[x][y]){
        return dp[x][y];
    }
    int ans = -INF;
    if(x!=0){
        ans = max(ans,rec(x-1,y)+arr[x][y]);
    }
    if(y!=0){
        ans = max(ans,rec(x,y-1)+arr[x][y]);
    }
    done[x][y]=1;
    return dp[x][y]=ans;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for( int i=0; i<n ;i++){
        for( int j=0; j<n ;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp)); // not necessery
    memset(done,0,sizeof(done)); // necessery
    cout<<rec(n-1,n-1)<<endl;
}