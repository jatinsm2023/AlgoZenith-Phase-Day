#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
int a[100100];

int check(int mid)
{
    int sol = 0;
    for (int i = 1; i < n; i++)
    {
        int x = a[i]-a[i-1];
        if(x%mid==0){
            sol+=x/mid-1;
        }
        else sol+=x/mid;
    }
    return sol  <= k;
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int low = 1;
        int high = 0;
        for (int i = 1; i < n; i++)
        {
            high = max(high, a[i] - a[i - 1]);
        }
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << ans << '\n';
    }
}
