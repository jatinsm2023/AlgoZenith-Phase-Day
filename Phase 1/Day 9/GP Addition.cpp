#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10;
const int m = 1e9 + 7;
vector<int> A(N);
vector<int> power(N);

int binpow(int a, int b)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


signed main()
{
    int n, q, k;
    cin >> n >> q >> k;
    power[0] = 1;
    for (int i = 1; i < N; i++)
    {
        power[i] = k * power[i - 1];
        power[i] %= m;
    }
    while (q--)
    {
        int a, l, r;
        cin >> a >> l >> r;
        int x = a * binpow(power[l], m - 2) % m;
        A[l] += x;
        A[r + 1] -= x;
    }
    for (int i = 1; i <= n; i++)
    {
        A[i] += A[i - 1] % m;
        A[i] %= m;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ((((A[i] % m)) * (power[i] % m)) % m + m) % m << " ";
    }
    cout << endl;
}