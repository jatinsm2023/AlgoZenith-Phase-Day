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

int n;
vector<int> arr;
int dp[510][510];

int rec(int l, int r)
{
    if (l >= r)
    {
        return 0;
    }

    if (dp[l][r] != -1)
        return dp[l][r];
    int ans = 0;
    int total = 0;
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        total += arr[i];
    }
    for (int mid = l; mid <r; mid++)
    {
        sum += arr[mid];
        ans = max(rec(l, mid) + rec(mid + 1, r) + (sum % 100) * ((total - sum) % 100), ans);
    }
    return dp[l][r] = ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    memset(dp, -1, sizeof(dp));
    cout << rec(0, n) << endl;
}