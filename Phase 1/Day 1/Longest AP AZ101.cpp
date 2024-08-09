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
    int diff[n - 1];
    for (int i = 1; i < n; i++)
    {
        diff[i - 1] = a[i] - a[i - 1];
    }
    int dif[n - 2];
    for (int i = 1; i < n - 1; i++)
    {
        dif[i - 1] = diff[i] - diff[i - 1];
    }
    int x=0;
    int mx = 0;
    for( int i=0; i<n-2; i++)
    {
        if(dif[i]==0)
        {
            x++;
        }
        if(dif[i]!=0)
        {
            mx = max(x, mx);
            x=0;
        }
    }
    mx = max(x,mx);
    cout<<mx+2<<endl;
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