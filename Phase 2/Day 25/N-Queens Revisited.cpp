#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<int> a;
bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (a[i] == col || abs(i - row) == abs(a[i] - col))
            return false;
        if ((abs(i - row) * abs(i - row) + abs(a[i] - col) * abs(a[i] - col) == 5) && (abs(i - row) == 2 * abs(a[i] - col) || abs(i - row) * 2 == abs(a[i] - col)))
            return false;
    }
    return true;
}
int rec(int level)
{
    if (level == n)
        return 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (check(level, i))
        {
            a[level] = i;
            ans += rec(level + 1);
            a[level] = -1;
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
    a.resize(n, -1);
    cout << rec(0) << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}