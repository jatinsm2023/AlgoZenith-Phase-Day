#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long m = 1e9 + 7;

int mul(int a, int b)
{
    int sol = ((a % m) * (b % m)) % m;
    return sol;
}

int bin_pow(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;

    int ans = n ;
    ans = mul(ans, n - 1);
    ans = mul(ans, n - 2);
    ans = mul(ans, n - 3);
    ans = mul(ans, bin_pow(24, m - 2, m));
    cout << ans << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}