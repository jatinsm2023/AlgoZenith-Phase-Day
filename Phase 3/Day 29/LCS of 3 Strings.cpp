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
inline int binpow(int a, int b){int res = 1;while (b){if (b & 1) res = mul(res, a);a = mul(a, a);b >>= 1;}return res;}

int dp[110][110][110];
string a, b,c;

int rec(int i, int j,int k){
    if(i==a.size() || j== b.size() || k==c.size())return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int ans = 0;
    if(a[i]==b[j] && b[j]==c[k])ans = 1+rec(i+1,j+1,k+1);
    ans = max(ans,rec(i+1,j,k));
    ans = max(ans,rec(i,j+1,k));
    ans=max(ans,rec(i,j,k+1));
    return dp[i][j][k]=ans;
}
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>c;
        cout<<rec(0,0,0)<<'\n';
    }
}