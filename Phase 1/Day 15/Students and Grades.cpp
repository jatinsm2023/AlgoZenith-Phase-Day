#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int,int> a;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    for (auto it : b)
    {
        if (a.count(it))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
            a[it]++;
        }
    }
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