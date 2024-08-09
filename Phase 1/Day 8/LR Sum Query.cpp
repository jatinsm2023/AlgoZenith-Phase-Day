#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long m = 1e9 + 7;

signed main()
{
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= m;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = (a[i - 1] % m + a[i] % m) % m;
        if (a[i] < 0)
        {
            a[i] += m;
            a[i] %= m;
        }
    }
    cout << endl;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sol = (a[r] % m - a[l - 1] % m) % m;
        if (sol < 0)
            sol += m;
        cout << (sol) % m << endl;
    }
}