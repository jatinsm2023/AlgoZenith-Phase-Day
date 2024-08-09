#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'N')
        {
            int b1 = a[0], b2 = a[4], b3 = a[5];
            a[0] = a[1];
            a[4] = b1;
            a[5] = b2;
            a[1] = b3;
        }
        if (s[i] == 'S')
        {
            int b1 = a[0], b2 = a[1], b3 = a[4], b4 = a[5];
            a[0] = b3;
            a[1] = b1;
            a[4] = b4;
            a[5] = b2;
        }
        if (s[i] == 'E')
        {
            int b1 = a[0], b2 = a[2], b3 = a[3], b4 = a[5];
            a[0] = b3;
            a[2] = b1;
            a[3] = b4;
            a[5] = b2;
        }
        if (s[i] == 'W')
        {
            int b1 = a[0], b2 = a[2], b3 = a[3], b4 = a[5];
            a[0] = b2;
            a[2] = b4;
            a[3] = b1;
            a[5] = b3;
        }
    }
    cout << a[0] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}