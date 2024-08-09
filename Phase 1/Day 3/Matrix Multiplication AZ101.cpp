#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
void solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    int a[n][m];
    int b[m][p];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> b[i][j];
        }
    }
    int c[n][p];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
           cout << c[i][j] << " ";
        }
        cout << "\n";

    }

}

signed main()
{
      IOS
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}