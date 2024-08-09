#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        int a1, a2;
        a1 = (x2 - x1) * (y2 - y1);
        a2 = (x4 - x3) * (y4 - y3);
        if (x1 >= x4 || x3 >= x2 || y3 >= y2 || y1 >= y4)
        {
            cout << 0 << " " << a1 + a2 << '\n';
        }
        else 
        {
            int in = (min(x4,x2) - max(x1,x3)) * (min(y2,y4) - max(y3,y1));
            cout << in << " " << a1 + a2 - in << '\n';
        }

    }
}