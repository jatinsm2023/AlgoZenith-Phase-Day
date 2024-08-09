#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
char chess[8][8];
int queen[8];

bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (queen[i] == col || abs(queen[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

int rec(int level)
{
    if (level == n)
    {
        return 1;
    }

    int ans = 0;
    for (int ch = 0; ch < n; ch++)
    {
        if (chess[level][ch] == '*')
        {
            continue;
        }
        else if (check(level, ch))
        {
            queen[level] = ch;
            ans += rec(level + 1);
            queen[level] = -1;
        }
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    n = 8;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> chess[i][j];
        }
    }
    memset(queen,-1,sizeof(queen));
    cout << rec(0) << '\n';
}