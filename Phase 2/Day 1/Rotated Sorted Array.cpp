#include <bits/stdc++.h>
using namespace std;

#define int long long

int check(int x, int y)
{
    if (x <= y)
        return 1;
    else
        return 0;
}
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

        int lo = 0, hi = n - 1;
        int ans = hi + 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(a[mid], a[n - 1]))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << (ans) << '\n';
    }
}