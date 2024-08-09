#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++)
    {
        v[i]+=v[i-1];
    }
    while(q--)
    {
        int m;
        cin>>m;
        auto x = upper_bound(v.begin(), v.end(), m);
        cout<<x - v.begin()<<'\n';
    }
}