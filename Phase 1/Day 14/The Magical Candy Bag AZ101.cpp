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
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            if (!pq.empty())
            {
                int l = pq.top();
                ans += l;
                pq.pop();
                if (l / 2 != 0)
                    pq.push(l / 2);
            }
            else break;
        }
        cout << ans << '\n';
    }
}