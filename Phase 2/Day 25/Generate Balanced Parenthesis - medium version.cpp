#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, k;
vector<char> a;

bool is_depthk(vector<char> a)
{
    int depth = 0;
    int p = 0;
    for (auto x : a)
    {
        if (x == '(')
            p++;
        else
        {
            depth = max(depth, p);
            p--;
        }

        if (depth < 0)
            return false;
    }
    return depth == k;
}
void rec(int level, int open)
{
    if (level == n)
    {
        if (open == 0)
        {
            if (is_depthk(a))
            {
                for (auto x : a)
                    cout << x;
                cout << '\n';
            }
        }
        return;
    }
    if (!open)
    {
        a.push_back('(');
        rec(level + 1, open + 1);
        a.pop_back();
    }
    else
    {
        int rem = n - level + 1;
        if (rem > open)
        {
            a.push_back('(');
            rec(level + 1, open + 1);
            a.pop_back();
        }
        a.push_back(')');
        rec(level + 1, open - 1);
        a.pop_back();
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    rec(0, 0);
}