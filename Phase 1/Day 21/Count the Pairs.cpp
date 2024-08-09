#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> ms;

        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            ms.push_back(y);
        }
        sort(ms.begin(), ms.end());
        int sol = 0;
        for (auto y : ms)
        {
            int p = x - y;
            int it = upper_bound(ms.begin(), ms.end(), p) - ms.begin();
            if (p >= y)
            {
                it--;
            }
            sol += it;
        }
        cout << sol << "\n";
    }
}