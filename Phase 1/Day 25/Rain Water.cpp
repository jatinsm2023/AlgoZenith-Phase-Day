#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int psg[n];
        int nsg[n];
        psg[0] = a[0];
        nsg[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++)
        {
            psg[i] = max(psg[i - 1], a[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            nsg[i] = max(nsg[i + 1], a[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            int height = min(nsg[i],psg[i]) - a[i];
            ans += height;
        }
        cout << ans << ' ';
        cout << '\n';
    }
}