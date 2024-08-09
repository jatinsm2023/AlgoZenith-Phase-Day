#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long min = INT_MAX;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long g = __gcd(a[0],a[1]);
    for( int i=2; i<n; i++)
    {
        g = __gcd(g,a[i]);
    }
    if (g>=2)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}

int main()
{
    IOS long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}