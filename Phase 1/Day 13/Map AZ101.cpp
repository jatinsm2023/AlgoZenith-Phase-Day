#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        map<string, int> mp;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "add")
            {
                string x;int y;
                cin >> x >> y;
                mp[x] = y;
            }
            else if (s == "erase")
            {
                string x;
                cin >> x;
                if (mp.count(x))
                {
                    mp.erase(x);
                }
            }
            else if (s == "print")
            {
                string x;
                cin >> x;
                if (mp.count(x))
                {
                    cout << mp[x] << '\n';
                }
                else
                    cout << 0 <<'\n';
            }
        }
    }
}