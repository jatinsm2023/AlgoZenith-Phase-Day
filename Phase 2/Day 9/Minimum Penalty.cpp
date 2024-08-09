#include <bits/stdc++.h>
using namespace std;

#define int long long
int freq[1000001];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        int dicnt = 0;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (d == 1)
            cout << 1 << '\n';
        else
        {
            int tail = 0;
            int head = d - 1;
            for (int i = 0; i < d; i++)
            {
                if (freq[a[i]] == 0)
                {
                    dicnt++;
                }
                freq[a[i]]++;
            }
            int ans = dicnt;
            while (head + 1 < n)
            {
                freq[a[tail]]--;
                if (freq[a[tail]] == 0)
                    dicnt--;
                tail++;
                head++;
                if (freq[a[head]] == 0)
                    dicnt++;
                freq[a[head]]++;
                ans = min(ans, dicnt);
            }
            cout << ans << '\n';

            for( int i=0; i<n ;i++)
            {
                freq[a[i]]=0;
            }
        }
    }
}