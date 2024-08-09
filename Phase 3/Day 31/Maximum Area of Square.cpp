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
inline int mul(int a, int b) { return (a * b % mod); }
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
int dp[1005][1005];
bool grid[1005][1005];
signed main(){
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while(t--) {
       int n, m;
       cin >> n >> m;
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               cin >> grid[i][j];
           }
       }
       for (int i = 0; i <= n; ++i) {
           for (int j = 0; j <= m; ++j) {
               dp[i][j] = 0;
           }
       }
       int ans = 0;
       for (int i = 1; i <= n; ++i) {
           for (int j = 1; j <= m; ++j) {
               if(grid[i-1][j-1]) {
                   dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
               }
               ans = max(ans, dp[i][j]);
           }
       }
       cout << ans*ans << "\n";
   }
   return 0;
}