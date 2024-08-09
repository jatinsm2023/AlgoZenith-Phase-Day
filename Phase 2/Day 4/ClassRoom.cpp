#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
vector<int> a;
int check(int mid)
{
    int sol = 1;
    int r = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[r] + mid)
        {
            sol++;
            r = i;
        }
    }
    return sol >= k;
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
        a.resize(0);
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        int low = 1;
        int high = a[n - 1] - a[0];
        int ans;
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
        cout << ans << '\n';
    }
}

// 10 6
// 469 706 278 545 711 386 298 242 385 316