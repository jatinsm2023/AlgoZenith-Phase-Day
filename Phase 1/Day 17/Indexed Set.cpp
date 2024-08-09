#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        int i = 0;
        unordered_map<int, int> mp;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "add")
            {
                int x;
                cin >> x;
                if (mp.count(x)==0)
                {
                    mp[x] = i;
                    i++;
                }
            }
            else if (s == "remove")
            {
                int x;
                cin >> x;
                if (mp.count(x)!=0)
                {
                    mp.erase(x);
                }
            }
            else if (s == "find")
            {
                int x;
                cin >> x;
                if (x < mp.size())
                {
                    for(auto l:mp){
                        if(l.second==x-1){
                            cout<<l.first<<'\n';
                            break;
                        }
                    }
                }
                else cout<<-1<<'\n';
            }
            else if (s == "findpos")
            {
                int x;
                cin >> x;
                auto it = mp.find(x);
                if (it != mp.end())
                {
                    cout << it->second << '\n';
                }
                else
                    cout << mp.size() << '\n';
            }
        }
    }
}