#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long m = 1e9 + 7;

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
    return res;
}

int mul(int a, int b)
{
    return ((a % m) * (b % m)) % m;
}
int add(int a, int b)
{
    return ((a % m) + (b % m)) % m;
}

void solve()
{
    int n;
    cin >> n;
    n%=m;
    int ans1 = n;
    ans1 = mul(ans1, n - 3);
    ans1 = mul(ans1, binpow(2, m - 2, m));
    int ans2 = n;
    ans2 = mul(ans2, n - 1);
    ans2 = mul(ans2, n - 2);
    ans2 = mul(ans2, n - 3);
    ans2 = mul(ans2, binpow(24, m - 2, m));
    int ans3 = 1;

    int sol = add(ans1, add(ans2, ans3));
    cout << sol << endl;
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