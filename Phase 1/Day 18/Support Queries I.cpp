#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int q;
    cin >> q;
    map<int, int> mp;
    int sum = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            mp[x]++;
            sum += x;
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            if (mp.count(x))
            {
                if (mp[x] == 1)
                    mp.erase(x);
                else if (mp[x] > 1)
                    mp[x]--;
                sum -= x;
            }
        }
        else if (t == 3)
        {
            char c;
            cin >> c;
            if (c == '?')
            {
                if (mp.empty())
                {
                    cout << -1 << '\n';
                }
                else
                {
                    cout << mp.begin()->first << "\n";
                }
            }
        }
        else if (t == 4)
        {
            char c;
            cin >> c;
            if (c == '?')
            {
                if (mp.empty())
                {
                    cout << -1 << '\n';
                }
                else
                {
                    cout << (--mp.end())->first << '\n';
                }
            }
        }
        else if (t == 5)
        {
            char c;
            cin >> c;
            if (c == '?')
            {
                cout << sum << '\n';
            }
        }
    }
}