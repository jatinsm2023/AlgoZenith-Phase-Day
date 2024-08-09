#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[i] = x;
            mp[x]++;
        }
        int sol = 0;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]]--;
            sol += mp[a[i]-k]+mp[a[i]+k];
        }
        cout << sol << '\n';
    }
}