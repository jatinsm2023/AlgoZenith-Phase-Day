#include <bits/stdc++.h>
using namespace std;

#define int long long
const int m = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int g[N];
int n, q;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= m;
        g[i] = (a[i]) * i % m;
    }
    for (int i = 1; i < N; i++)
    {
        a[i] = (a[i] % m + a[i - 1] % m) % m;
        g[i] = (g[i] % m + g[i - 1] % m) % m;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sol = ((g[r] % m - g[l - 1] % m) % m) - ((l - 1) * (a[r] % m - a[l - 1] % m) % m);
        cout << (sol % m + m) % m << endl;
    }
}