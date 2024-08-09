#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(k), b(k);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
        }
        vector<int> speed(k);
        for (int i = 0; i < k; i++)
        {
            speed[i] = a[i] / b[i];
        }
        vector<int> sol(n);
        auto it = upper_bound(a.begin(), a.end(), 1);
        sol[0] = 1 / speed[it - a.begin()];
        for (int i = 1; i < n; i++)
        {
            auto ti = upper_bound(a.begin(), a.end(), i + 1);
            sol[i] = sol[i - 1] + (1 / speed[ti - a.begin()]);
        }
        while (q--)
        {
            int d;
            cin >> d;
            if (d == 0)
                cout << 0 << " ";
            else
                cout << sol[d - 1] << " ";
        }
        cout << '\n';
    }
}