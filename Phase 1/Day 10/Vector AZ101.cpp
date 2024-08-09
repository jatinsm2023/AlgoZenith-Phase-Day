#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;

    string s;
    int n;
    vector<int> v;
    while (q--)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> n;
            v.push_back(n);
        }
        if (s == "remove")
        {
            v.pop_back();
        }
        if (s == "print")
        {
            cin >> n;
            if (n < v.size())
            {
                cout << v[n] << "\n";
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        if (s == "clear")
        {
            v.clear();
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}