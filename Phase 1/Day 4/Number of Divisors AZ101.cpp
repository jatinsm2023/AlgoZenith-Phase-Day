#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int cnt = 0;
    int i;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        }
    }
    cnt *= 2;
    if (n % (i * i) == 0)
        cnt++;
    cout << cnt << endl;
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