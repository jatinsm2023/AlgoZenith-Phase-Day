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

int took[3010][3010];
int dp[3010][3010];
int n, m;
string s, t;
int rec(int x, int y)
{
    if (x == n || y == m)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];
    int ans = 0;
    if (s[x] == t[y])
    {
        ans = max(ans, rec(x + 1, y + 1) + 1);
    }

    ans = max(ans, rec(x + 1, y));
    ans = max(ans, rec(x, y + 1));

    return dp[x][y] = ans;
}

string ans = "";
void generate(int x, int y)
{
    if (x == n || y == m)
    {
        return;
    }
    if (s[x] == t[y])
    {
        ans += s[x];
        generate(x + 1, y + 1);
    }
    else if (dp[x + 1][y] > dp[x][y + 1])
    {
        generate(x + 1, y);
    }
    else
    {
        generate(x, y + 1);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    n = s.size();
    m = t.size();
    memset(dp, -1, sizeof(dp));
    rec(0, 0);

    generate(0, 0);
    cout << ans << endl;
}