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

string s, t;
int n, m;
int dp[1010][1010];

int rec(int x, int y)
{
    if (x == n || y == m)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    int ans = 0;
    if (s[x] == t[y])
        ans = 1 + rec(x + 1, y + 1);
    else
        ans = 0;
    dp[x][y] = ans;
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    while (x--)
    {
        cin >> s >> t;
        n = s.size();
        m = t.size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, rec(i, j));
            }
        }
        cout << ans << '\n';
    }
}