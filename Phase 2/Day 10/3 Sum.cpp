#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, target;
    cin >> n >> target;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    int best = a[0] + a[1] + a[2];
    for (int j = 1; j < n - 1; j++)
    {
        int i = 0;
        int k = n - 1;
        while (1)
        {
            if (abs(a[i] + a[j] + a[k] - target) < abs(best - target))
            {
                best = a[i] + a[j] + a[k];
            }
            if (a[i] + a[j] + a[k] > target)
                k--;
            else
                i++;
            if (i == j || k == j)
                break;
        }
    }
    cout << abs(best - target) << '\n';
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