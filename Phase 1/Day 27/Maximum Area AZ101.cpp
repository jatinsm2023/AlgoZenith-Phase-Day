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
        int h, w, n;
        cin >> h >> w >> n;
        int a = 0, b = w, c = 0, d = h;
        for (int i = 0; i < n; i++)
        {
            char s;
            int x;
            cin >> s >> x;
            if (s == 'H')
            {
                if (x >= c && x <= d)
                {
                    if (x <= (c + d) / 2)
                    {
                        c = x;
                    }
                    else
                        d = x;
                }
            }
            else
            {
                if (x >= a && x <= b)
                {
                    if (x <= (a + b) / 2)
                    {
                        a = x;
                    }
                    else
                        b = x;
                }
            }
            cout << (b - a) * (d - c) << '\n';
        }
    }
}