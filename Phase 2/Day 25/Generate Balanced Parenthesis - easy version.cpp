#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<char> a;

void rec(int level, int open)
{
    if (level == n)
    {
        if (open == 0)
        {
            for (auto x : a)
                cout << x;
            cout << '\n';
        }
        return;
    }
    if(!open){
        a.push_back('(');
        rec(level + 1, open + 1);
        a.pop_back();
    }
    else {
        int rem = n - level + 1;
        if(rem>open){
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
    cin >> n;

    rec(0,0);
}