#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int binpow(int a, int b)
{
    a %= mod;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res % mod;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        double median = 0;
        multiset<int> lower, upper;
        while (q--)
        {
            int n;
            cin >> n;
            if (abs(upper.size() - lower.size()) >= 2)
            {
                if (upper.size() > lower.size())
                {
                    int l = *upper.begin();
                    upper.erase(l);
                    lower.insert(l);
                }
                else if (upper.size() < lower.size())
                {
                    int l = *lower.rbegin();
                    lower.erase(l);
                    upper.insert(l);
                }
            }
            if (lower.size() == 0 && upper.size() == 0)
            {
                lower.insert(n);
                median = n;
            }
            else if (n >= median)
            {
                upper.insert(n);
                if (upper.size() > lower.size())
                {
                    median = *upper.begin();
                }
                else if (upper.size() < lower.size())
                {
                    median = *lower.rbegin();
                }
                else
                {
                    median = (*lower.rbegin() + *upper.begin()) * (1.0) / 2.0;
                }
            }
            else if (n < median)
            {
                lower.insert(n);
                if (upper.size() > lower.size())
                {
                    median = *upper.begin();
                }
                else if (upper.size() < lower.size())
                {
                    median = *lower.rbegin();
                }
                else
                {
                    median = (*lower.rbegin() + *upper.begin()) * (1.0) / 2.0;
                }
            }

            cout << median << " ";
        }
        cout << '\n';
    }

    return 0; 
}
