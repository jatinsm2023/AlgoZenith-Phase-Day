#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl '\n'
#define F first
#define S second
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
const int INF = 1e9;

int n, m, k;

int dp[110][110][11];
int arr[110][110];

int check(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
        return 1;
    return 0;
}

int rec(int i, int j, int l)
{
    if(!check(i,j))return -1e9;
    if (i == 0)
    {
        if ((l+arr[i][j]) % k == 0)
            return arr[i][j];
        else
            return -1e9;
    }
    if (dp[i][j][l] != -1)
        return dp[i][j][l];
    int sol = -1e9;
    sol = max(sol, rec(i - 1, j - 1, (l + arr[i][j] + k) % k) + arr[i][j]);
    sol = max(sol, rec(i - 1, j + 1, (l + arr[i][j] + k) % k) + arr[i][j]);

    return dp[i][j][l] = sol;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j] - '0';
        }
    }
    int ans = -1;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, rec(n - 1, i, 0));
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m ;j++){
    //         print(dp[i][j]);
    //     }
    //     cout<<'\n';
    // }
    cout << ans << '\n';
}

signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}