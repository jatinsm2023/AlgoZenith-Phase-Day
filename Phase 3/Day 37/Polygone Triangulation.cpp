#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int values[101];
int dp[101][101];
int done[101][101];

int cost(int l, int r, int k)
{
    return values[l] * values[r] * values[k];
}

int rec(int l, int r)
{
    if (abs(r - l) == 1)
        return 0; // can't form a triangle
    if (done[l][r] != 0)
        return dp[l][r];
    int ans = 1e18;
    for (int k = l + 1; k <= r - 1; k++)
    {
        ans = min(ans, cost(l, r, k) + rec(l, k) + rec(k, r));
    }
    done[l][r] = 1;
    return dp[l][r] = ans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> values[i];
        }
        memset(done, 0, sizeof(dp));
        cout << rec(1, n) << '\n';
    }
    return 0;
}