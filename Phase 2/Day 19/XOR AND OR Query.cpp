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
        int n;
        cin >> n ;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int q;
        cin >> q;
        vector<vector<int>> pre(32, vector<int>(n));
        for (int i = 0; i < 31; i++)
        {
            if ((a[0] & (1LL << i)))
                pre[i][0] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                pre[j][i] = pre[j][i - 1];
                if ((a[i] & (1LL << j)))
                    pre[j][i]++;
            }
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int ans = 0;
            int ans1 = 0;
            int ans2 = 0;
            for (int j = 0; j < 31; j++)
            {
                int cnt_one = pre[j][r] - ((l - 1 >= 0) ? pre[j][l - 1] : 0);
                if (cnt_one > 0)
                    ans2 += (1LL << j);
                if (cnt_one < (r - l + 1.0) / 2)
                {
                    ans1 += (1LL << j);
                }
                if (cnt_one != (r - l + 1.0))
                    ans += (1LL << j);
            }
            cout << ans + ans1 + ans2 << '\n';
        }
    }
}