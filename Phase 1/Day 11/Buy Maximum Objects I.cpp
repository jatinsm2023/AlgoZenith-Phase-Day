#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        m -= v[i];
        if (m >= 0)
        {
            x++;
        }
    }
    cout << x << "\n";
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