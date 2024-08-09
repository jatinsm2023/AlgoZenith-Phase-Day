#include <bits/stdc++.h>
using namespace std;

#define int long long
const int m = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int res = 1;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        res *= x % m;
        res %= m;
    }
    cout << (res % m + m) % m << "\n";
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