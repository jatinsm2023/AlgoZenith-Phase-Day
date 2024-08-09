#include <bits/stdc++.h>
using namespace std;

#define int long long

int distinctCnt = 0;
int freq[100100];
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int tail = 0, head = -1;
        int ans = 0;
        while (tail < n)
        {
            while (head + 1 < n && (freq[a[head + 1]] != 0 || distinctCnt < k))
            {
                head++;
                if (freq[a[head]] == 0)
                {
                    distinctCnt++;
                }
                freq[a[head]]++;
            }
            ans += (head - tail + 1);
            if (tail > head)
            {
                tail++;
                head = tail - 1;
            }
            else
            {
                if (freq[a[tail]] == 1)
                {
                    distinctCnt--;
                }
                freq[a[tail]]--;
                tail++;
            }
        }
        cout << ans << '\n';
    }
}