#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a, b, c;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            b.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            c.push_back(a[i]-b[i]);
        }
        sort(c.begin(),c.end());
        int sol = 0;
        for( int i=0; i<n ;i++)
        {
            sol+=c.end()-upper_bound(c.begin()+i+1,c.end(),-c[i]);
        }
        cout<<sol<<'\n';
    }
}