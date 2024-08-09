#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
map<int, int> mp;
vector<int> cur;
void rec(int level)
{
    if (level == n)
    {
        for (auto x : cur)
        {
            cout << x << " ";
        }
        cout << '\n';
    }

    for (auto x : mp)
    {
        if (x.second > 0)
        {
            mp[x.first]--;
            cur.push_back(x.first);
            rec(level + 1);
            cur.pop_back();
            mp[x.first]++;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    rec(0);
}
