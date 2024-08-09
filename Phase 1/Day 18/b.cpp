#include <bits/stdc++.h>
using namespace std;

#define int long long
int check(int n)
{
    while (n > 0)
    {
        int d = n % 10;
        if (d != 0 && d != 1)
        {
            return 0;
        }
        n /= 10;
    }
    return 1;
}

int dp[100001];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<int, int> sol;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i < 100001; i++)
    {
        if (check(i))
        {
            dp[i] = 1;
            sol[i] = i;
        }
    }

    for (int i = 2; i < 100001; i++)
    {
        if (!check(i))
        {
            for (auto x : sol)
            {

                if (i % x.first == 0 && dp[x.first] && dp[i / x.first])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (check(n))
        {
            cout << "YES" << '\n';
            continue;
        }
        if (dp[n])
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
