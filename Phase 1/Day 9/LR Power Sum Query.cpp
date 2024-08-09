#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int a[N];
int g[N];
int power[N];
int n, q, k;

int binpow(int a, int b, int m)
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
    return res%mod;
}
signed main()
{
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> q >> k;
    power[0] = 1;
    for (int i = 1; i <=n; i++)
    {
        power[i] = k*power[i - 1];
        power[i] %= mod;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= mod;
        g[i] = a[i] * power[i] % mod;
        g[i] %= mod;
        g[i]+=g[i-1]%mod;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = g[r] - g[l - 1];
        ans += mod%mod;
        ans *= binpow(power[l], mod - 2, mod)%mod;
        ans = ans % mod + mod;
        ans %= mod;
        cout << ans << endl;
    }
}