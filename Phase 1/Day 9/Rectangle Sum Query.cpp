#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
#define int long long
const int m = 1e9 + 7;

signed main()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            a[i][j] = x % m;
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            a[i][j] = (a[i][j] % m + a[i][j - 1] % m) % m;
        }
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            a[i][j] = (a[i][j] % m + a[i - 1][j] % m) % m;
        }
    }

    while (q--)
    {
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        int sol = (a[r][s] % m + a[p - 1][q - 1] % m - a[p - 1][s] % m - a[r][q - 1] % m) % m;
        if(sol<0)sol+=m;
        cout << (sol) % m << endl;
    }
}