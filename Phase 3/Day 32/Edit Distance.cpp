#include <bits/stdc++.h>
using namespace std;

#define int long long
#define print(v)          \
    for (auto x : v)      \
        cout << x << ' '; \
    cout << endl;
#define yes() cout << "YES" << endl;
#define no() cout << "NO" << endl;
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

int dp[1000][1000];

int rec(int x, int y) {
    if (x >= s.size() && y >= t.size()) return 0; // Both strings are fully traversed
    if (x >= s.size()) return t.size() - y; // If s is exhausted, insert all remaining characters of t
    if (y >= t.size()) return s.size() - x; // If t is exhausted, delete all remaining characters of s

    if (dp[x][y] != -1) return dp[x][y];

    if (s[x] == t[y]) {
        dp[x][y] = rec(x + 1, y + 1); // Characters match, move both indices
    } else {
        int insert_op = 1 + rec(x, y + 1);    // Insert character from t
        int delete_op = 1 + rec(x + 1, y);    // Delete character from s
        int replace_op = 1 + rec(x + 1, y + 1); // Replace character from s with t

        dp[x][y] = min({insert_op, delete_op, replace_op});
    }

    return dp[x][y];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0) << endl;
}
