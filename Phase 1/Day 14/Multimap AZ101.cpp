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
        int q;
        cin >> q;
        multimap<string, int> mp;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "add")
            {
                string x;
                int y;
                cin >> x >> y;
                mp.insert({x, y});
            }
            else if (s == "erase")
            {
                string x;
                cin >> x;
                auto it = mp.find(x);
                if (it != mp.end())
                {
                    mp.erase(it);
                }
            }
            else if (s == "eraseall")
            {
                string x;
                cin >> x;
                int l = mp.count(x);
                while (l--)
                {
                    auto it = mp.find(x);
                    mp.erase(it);
                }
            }
            else if (s == "print")
            {
                string x;
                cin >> x;
                auto it = mp.find(x);
                if (it != mp.end())
                {
                    cout << it->second << '\n';
                }
                else
                    cout << 0 << '\n';
            }
        }
    }
}