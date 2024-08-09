#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1010;
int a[N][N];
int p[N][N];
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    while (q--)
    {
        int p, q, r, s, x;
        cin >> p >> q >> r >> s >> x;
        a[p][q] += x;
        a[r + 1][s + 1] += x;
        a[p][s + 1] -= x;
        a[r + 1][q] -= x;
    }
    int mx = INT_MIN;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            p[i][j] = a[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
            if (mx == p[i][j])
            {
                cnt++;
            }
            else if (mx < p[i][j])
            {
                mx = p[i][j];
                cnt = 1;
            }
        }
    }

    cout << mx << " " << cnt << endl;
}

signed main()
{
    solve();
}