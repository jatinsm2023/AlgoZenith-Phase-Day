#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        int q;
        cin >> q;
        set<int> s1;
        set<int> s2;
        for (int i = 0; i < q; i++)
        {
            int t, x;
            cin >> t >> x;
            if (t == 1)
            {
                s1.insert(x);
                if (s2.count(x))
                    s2.erase(s2.find(x));
                if (s1.count(x + 1)==0)
                    s2.insert(x + 1);
            }
            else
            {
                if (s1.count(x)==0)
                {
                    cout << x << '\n';
                }
                else
                {
                    auto it = (lower_bound(s2.begin(), s2.end(), x));
                    if (it == s2.end())
                        cout << x << '\n';
                    else
                        cout << (*it) << '\n';
                }
            }
        }
    }
    return 0;
}