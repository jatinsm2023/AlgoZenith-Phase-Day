#include <bits/stdc++.h>
using namespace std;

int n;
const int mod = 1e9 + 7;
int dp[1000100][5];
inline void add(int &a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}

int rec(int length, int state)
{
    if (state == 4)
        return 0;
    if (length == 0)
        return 1;
    if (dp[length][state] != -1)
    {
        return dp[length][state];
    }
    int ans = 0;
    if (state == 0)
    {
        add(ans, rec(length - 1, 0));
        add(ans, rec(length - 1, 1));
    }
    if (state == 1)
    {
        add(ans, rec(length - 1, 0));
        add(ans, rec(length - 1, 2));
    }
    if (state == 2)
    {
        add(ans, rec(length - 1, 2));
        add(ans, rec(length - 1, 3));
    }
    if (state == 3)
    {
        add(ans, rec(length - 1, 0));
        add(ans, rec(length - 1, 4));
    }
    return dp[length][state] = ans % mod;
}


int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < 1000100; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            dp[i][j] = -1;
        }
    }
    while (t--)
    {
        cin >> n;
        cout << rec(n, 0) % mod << '\n';
    }
}