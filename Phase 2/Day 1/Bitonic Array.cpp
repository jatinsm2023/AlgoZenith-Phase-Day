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
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int low = 0, high = n - 1;
        int ans = high + 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid + 1 < n && a[mid] > a[mid + 1])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
            ans = mid;
        }

        while (q--)
        {
            vector<int> sol(0);
            int x;
            cin >> x;
            low = 0, high = ans;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (a[mid] == x)
                {
                    sol.push_back(mid + 1);
                    break;
                }
                else if (a[mid] > x)
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            low = ans+1, high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (a[mid] == x)
                {
                    sol.push_back(mid + 1);
                    break;
                }
                else if (a[mid] < x)
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            for (auto l : sol)
            {
                cout << l << ' ';
            }
            cout << '\n';
        }
    }
}