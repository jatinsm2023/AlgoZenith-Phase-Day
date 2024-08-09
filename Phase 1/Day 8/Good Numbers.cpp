#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1000010;
vector<int> v(N, 0);
signed main()
{
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x]++;
        v[y + 1]--;
    }
    for (int i = 1; i < N; i++)
    {
        v[i] += v[i - 1];
    }
    for (int i = 1; i < N; i++)
    {
        if (v[i] >= k)
        {
            v[i] = 1;
        }
        else
            v[i] = 0;
    }
    for (int i = 1; i < N; i++)
    {
        v[i] += v[i - 1];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << endl;
    }
}