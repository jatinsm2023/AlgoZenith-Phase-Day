#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    long long int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (a[i]>a[i+1])
        {
            ans += (a[i]-a[i+1]);
            a[i+1]=a[i];
        }
    }
    cout << ans << endl;
    return;
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