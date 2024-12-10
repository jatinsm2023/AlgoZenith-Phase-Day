#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int dp[1010][1010];
string s;

int rec(int x, int y)
{
    if (y < 0)
        return 0;
    if (x == s.length())
        return (y == 0) ? 1 : 0;
  
    if (dp[x][y] != -1)
        return dp[x][y];

    int ans = 0;
    if (s[x] == '(')
        ans = rec(x + 1, y + 1) % mod;
    else if (s[x] == ')')
        ans = rec(x + 1, y - 1) % mod;
    else if (s[x] == '?')
    {
        ans = (rec(x + 1, y + 1) + rec(x + 1, y - 1)) % mod;
    }

    return dp[x][y] = ans;
}

void solve()
{
    cin >> s;

    if (s.length() % 2 != 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        for(int i=0;i<s.length(); i++){
            for(int j=0;j<s.length() ; j++){
                dp[i][j]=-1;
            }
        }
        cout << rec(0, 0) << '\n';
    }
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
        solve();
    }
}
