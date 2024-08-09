#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    int n = 0;
    int zeros = 60;
    int ones = 0;
    while (test--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int i;
            cin >> i;
            cout<<((n>>i)&1)<<'\n';
        }
        else if (t == 2)
        {
            int i;
            cin >> i;
            n = n | (1LL<<i);
        }
        else if (t == 3)
        {
            int i;
            cin >> i;
            n = n&(~(1LL<<i));
        }
        else if (t == 4)
        {
            int i;
            cin >> i;
            n = n^(1LL<<i);
        }
        else if (t == 5)
        {
           cout<<(__builtin_popcountll(n)==60)<<'\n';
        }
        else if (t == 6)
        {
           cout<<(__builtin_popcountll(n)!=60)<<'\n';
        }
        else if (t == 7)
        {
            cout<<(__builtin_popcountll(n)==0)<<'\n';
        }
        else if (t == 8)
        {
            cout<<(__builtin_popcountll(n))<<'\n';
        }
        else if (t == 9)
        {
            cout << n << '\n';
        }
    }
}