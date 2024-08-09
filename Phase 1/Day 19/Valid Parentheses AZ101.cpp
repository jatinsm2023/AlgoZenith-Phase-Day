#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        int clo = 0;
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')')
            {
                if (st.empty())
                {
                    clo++;
                }
                else
                {
                    st.pop();
                }
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
        }
        cout << st.size() + clo << '\n';
    }
}