#include <bits/stdc++.h>
using namespace std;
#define int long long
const long long MOD = 1e9 + 7;
vector<int> v(200010);

int bin_pow(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int sol = (((v[n + m] % MOD) * (bin_pow(v[n], MOD - 2, MOD) % MOD))%MOD * (bin_pow(v[m], MOD - 2, MOD)) % MOD) % MOD;
    cout << sol % MOD << endl;
}
signed main()
{
    int t;
    cin >> t;
    v[0] = 1;
    for (int i = 1; i < 200010; i++)
    {
        v[i] = ((v[i - 1] % MOD) * (i % MOD)) % MOD;
    }
    while (t--)
    {
        solve();
    }
}