#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int N = 1e3 + 10;
vector<vector<int>> A(N, vector<int> (N));
vector<vector<int>> G(N, vector<int> (N));

int max(int a, int b)
{
    return (a>b)?a:b;
}
signed main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
            A[i][j] %= mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            G[i][j] = G[i - 1][j - 1] + A[i][j] - A[i][j - 1];
            G[i][j] %= mod;
        }
    }
    while (q--)
    {
        int x, y, l;
        cin >> x >> y >> l;
        int ans = G[x][y]%mod;
        int i = max(0,x-l);
        int j = max(0,y-l);
        int sol = (((G[x][y] % mod - G[i][j] % mod) % mod) - (A[i][y] % mod - A[i][j] % mod)) % mod;
        cout << (sol % mod + mod) % mod << endl;
    }
}