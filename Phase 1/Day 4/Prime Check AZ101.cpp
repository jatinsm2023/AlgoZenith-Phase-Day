#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    bool ans = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans = false;
            break;
        }
    }
    if (ans == true)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}