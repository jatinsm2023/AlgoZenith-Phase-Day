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
        int n, q;
        cin >> n >> q;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        while (q--)
        {
            int j, k;
            cin >> j >> k;
            if (j == 1)
            {
                auto it = lower_bound(v.begin(), v.end(), k);
                if (k > v[v.size() - 1])
                {
                    cout << -1 << " ";
                }
                else
                {
                    cout << *it << ' ';
                }
            }
            else if (j == 2)
            {
                if (k >= v[v.size() - 1])
                {
                    cout << -1 << " ";
                }
                else
                    cout << *upper_bound(v.begin(), v.end(), k) << ' ';
            }
            else if (j == 3)
            {

                cout << upper_bound(v.begin(), v.end(), k) - v.begin() << " ";
            }
            else if (j == 4)
            {
                int sol = lower_bound(v.begin(), v.end(), k) - v.begin() ;
                cout << max(sol, 0ll) << ' ';
            }
        }
        cout << '\n';
    }
}