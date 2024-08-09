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
        int n, k, d;
        cin >> n >> k >> d;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int tail = 0, head = -1;
        int ans = -1e18;
        int odds = 0;
        int pre[n];
        for (int i = 0; i < n; i++)
        {
            if (i)
                pre[i] = a[i] + pre[i - 1];
            else
                pre[i] = a[i];
        }

        while (tail < n)
        {
            while (head + 1 < n && odds + ((a[head + 1] % 2 == 0) ? 0 : 1) <= k && pre[head + 1] - ((tail > 0) ? pre[tail - 1] : 0) <= d)
            {
                head++;
                if (a[head] % 2 != 0)
                    odds++;
            }
            if (tail > head)
            {
                tail++;
                head = tail - 1;
            }
            else
            {
                ans = max(ans, pre[head] - ((tail > 0) ? pre[tail - 1] : 0));

                if (a[tail] % 2 != 0)
                    odds--;
                tail++;
            }
        }

        if (ans!=-1e18)
            cout << ans << '\n';
        else
            cout << "IMPOSSIBLE" << '\n';
    }
}