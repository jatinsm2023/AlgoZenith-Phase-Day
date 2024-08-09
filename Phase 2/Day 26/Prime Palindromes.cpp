#include <bits/stdc++.h>
using namespace std;

#define int long long
int a, b;
set<int> st;
bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void rec(int cur, int totallen, int curlen)
{
    if (curlen == (totallen + 1) / 2)
    {
        string s = to_string(cur);
        string t = s;
        if (totallen % 2 != 0)
            t.pop_back();
        reverse(t.begin(), t.end());
        s += t;
        int num = stoll(s);
        if (num >= a && num <= b && isprime(num))
        {
            st.insert(num);
        }
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        cur *= 10;
        cur += i;
        rec(cur, totallen, curlen + 1);
        cur /= 10;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    int len = to_string(b).length();
    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            rec(j, i, 1LL);
        }
    }
    cout << st.size() << '\n';
}