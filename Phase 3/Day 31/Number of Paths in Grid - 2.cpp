#include <bits/stdc++.h>
using namespace std;

#define int long long
#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << endl;
#define yes() cout << 'YES<<endl';
#define no() cout << 'NO<<endl';
using state = pair<int, int>;
const int mod = 1e9 + 7;
inline void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
inline void sub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
}
inline int mul(int a, int b) { return (int)((long long)a * b % mod); }
inline int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int dp[210][210][410];
int n, m, k;
int v[210][210];

int rec( int x, int y, int remk){
    if(x==n-1 && y==m-1)return 1;
    if(x>=n || y>=m)return 0;
    if(dp[x][y][remk]!=-1)return dp[x][y][remk];
    int ans = 0;
    if(v[x+1][y]==0){
        ans = rec(x+1, y, remk);
    }
    if(v[x][y+1]==0){
        ans += rec(x, y+1, remk);
    }
    if(remk>0){
        if(v[x+1][y]==1){
            ans += rec(x+1, y, remk-1);
        }
        if(v[x][y+1]==1){
            ans += rec(x, y+1, remk-1);
        }
    }
    ans%=mod;
    return dp[x][y][remk] = ans%mod;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        for( int i=0; i<n; i++){
            for( int j=0; j<m; j++){
                for( int l=0; l<=k; l++){
                    dp[i][j][l] = -1;
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        if(v[0][0]==1 && k==0){
            cout << 0 << endl;
            continue;
        }
        else if(v[0][0]){
            k--;
        }
        cout << rec(0, 0, k) << endl;
    }
}