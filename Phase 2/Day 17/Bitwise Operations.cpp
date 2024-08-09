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
        cin >> n;
        int cnt[21] = {0};
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            for (int j = 0; j < 21; j++)
            {
                if (a[i] & (1 << j))
                {
                    cnt[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int largest = 0;
            for (int j = 0; j < 21; j++)
            {
                if (cnt[j] > 0)
                {
                    largest += (1 << j);
                    cnt[j]--;
                }
            }
            ans += largest*largest;
        }
        cout<<ans<<'\n';
    }
}