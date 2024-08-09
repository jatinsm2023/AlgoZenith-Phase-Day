#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, k;
vector<int> v;
vector<int> cur;
int f = 0;
void rec(int level)
{
    if (level == n)
    {
        f++;
        if (f == k)
        {
            for (auto x : cur)
            {
                cout << x << " ";
            }
            cout << '\n';
            return;
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            v[i] = 0;
            cur.push_back(i + 1);
            rec(level + 1);
            cur.pop_back();
            v[i] = 1;
        }
    }
}
void solve()
{
    cin >> n >> k;
    v.clear();
    for (int i = 0; i < n; i++)
    {
        v.push_back(1);
    }
    rec(0);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
        solve();
    
}