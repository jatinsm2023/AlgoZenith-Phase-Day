#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
#define int long long

long long bin_pow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
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
    n%=MOD;
    int x = bin_pow(2, MOD - 2, MOD);
    cout << ((((n % MOD) * ((n - 3) % MOD))%MOD) * (x % MOD)) % MOD<< endl;
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