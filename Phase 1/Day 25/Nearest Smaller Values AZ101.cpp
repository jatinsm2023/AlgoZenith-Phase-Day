#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (st.empty())
            {
                cout << 0 << ' ';
            }
            else
            {
                while (!st.empty() && st.top().first >= x)
                {
                    st.pop();
                }
                if (st.empty())
                {
                    cout << 0 << " ";
                }
                else
                {
                    cout << st.top().second << " ";
                }
            }
            st.push({x, i + 1});
        }
        cout << '\n';
    }
}