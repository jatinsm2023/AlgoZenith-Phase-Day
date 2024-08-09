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
        multiset<int> ms;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "add")
            {
                int x;
                cin >> x;
                ms.insert(x);
            }
            else if (s == "erase")
            {
                int x;
                cin >> x;
                if (ms.find(x) != ms.end())
                    ms.erase(ms.find(x));
            }
            else if (s == "eraseall")
            {
                int x;
                cin >> x;
                int l = ms.count(x);
                auto t1 = ms.find(x);
                while (l--)
                {
                    auto t2 = t1;
                    ++t2;
                    ms.erase(t1);
                    t1 = t2;
                }
            }
            else if (s == "find")
            {
                int x;
                cin >> x;
                if (ms.find(x) != ms.end())
                    cout << "YES" << '\n';
                else
                    cout << "NO\n";
            }
            else if (s == "count")
            {
                int x;
                cin >> x;
                cout << ms.count(x) << '\n';
            }
            else if (s == "print")
            {
                for (auto c : ms)
                {
                    cout << c << ' ';
                }
                cout << '\n';
            }
            else if (s == "empty")
            {
                ms.clear();
            }
        }
    }
    return 0;
}