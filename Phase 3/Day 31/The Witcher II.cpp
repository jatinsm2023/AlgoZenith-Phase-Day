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

int n, m;
int dp[210][210];
int v[210][210];

int rec(int x, int y)
{
    if (x == n - 1 && y == m - 1)
    {
        return max(1LL, 1 - v[x][y]);
    }
    if (x >= n || y >= m)
    {
        return 1e18;
    }
    if (dp[x][y] != -1)
        return dp[x][y];

    
    int ans = max(min(rec(x, y + 1), rec(x + 1, y)) - v[x][y], 1LL);

    return dp[x][y] = ans;
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
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = -1;
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> v[i][j];

        cout << rec(0, 0) << '\n';
    }
}