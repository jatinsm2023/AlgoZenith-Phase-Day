#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
int a[100100];
int pre[100100];

int check(int mid)
{
    int sol = 0;
    for (int i = 1; i <= n - mid + 1; i++)
    {
        sol = mid - (pre[i + mid - 1] - pre[i - 1]);
        if(sol<=k){
            return 1;
        }
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        pre[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            pre[i] = a[i] + pre[i - 1];
        }
        int high = n;
        int low = 0;
        int x = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                low = max(low, x);
                x = 0;
            }
            else
                x++;
        }
        low = max(low, x);
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << ans << endl;
    }
}