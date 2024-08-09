#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int x = -1, y = -1;
    vector<int> a(n), b(n - 1), c(n - 2);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n - 2; i++)
    {
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != b[i])
        {
            x = a[i];
            break;
        }
    }
    if (x == -1)
    {
        x = a[n - 1];
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (b[i] != c[i])
        {
            y = b[i];
            break;
        }
    }
    if (y == -1)
    {
        y = b[n - 2];
    }
    cout << x << ' ' << y << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}