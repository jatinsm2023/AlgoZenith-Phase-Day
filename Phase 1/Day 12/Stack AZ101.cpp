#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    string s;
    stack<int> v;
    while (q--)
    {
        cin >> s;
        if (s == "add")
        {
            int n;
            cin >> n;
            v.push(n);
        }
        if (s == "remove" && !v.empty())
        {
            v.pop();
        }
        if (s == "print")
        {
            if (v.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << v.top() << "\n";
            }
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