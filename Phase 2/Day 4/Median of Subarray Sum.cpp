#include <bits/stdc++.h>
using namespace std;

#define int long long

int check(int arr[], int n, int mid)
{
    int cnt = 0;
    int currSum = 0;
    int start = 0;
    int current = 0;
    while (current < n)
    {
        currSum += arr[current];
        while (start <= current and currSum > mid)
        {
            currSum -= arr[start];
            start++;
        }
        cnt += (current - start + 1);
        current++;
    }
    return cnt;
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
        int n;
        cin >> n;
        int a[n];
        int high = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            high += a[i];
        }
        int low = 0;
        int ans;
        int total = (n * (n + 1)) / 2;
        int median = (total + 1) / 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(a, n, mid) >= median)
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
