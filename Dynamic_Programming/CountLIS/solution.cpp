#include <bits/stdc++.h>
using namespace std;

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

int dp[1010][1010];

int rec(int i, int last, vector<int> &arr)
{
    if (i == arr.size())
        return 0;

    if (dp[i][last+1] != -1)
        return dp[i][last+1];
    int ans = rec(i+1,last,arr);
    if (last==-1 || arr[i] > arr[last])
    {
        ans = max({ans,rec(i + 1, i, arr) + 1});
    }
    ans = max({ans,rec(i+1,i,arr)});
    return dp[i][last+1] = ans;
}

void solve()
{
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
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
        solve();
    }
}