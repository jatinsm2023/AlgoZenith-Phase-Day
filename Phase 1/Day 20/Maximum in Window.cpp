#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        multiset<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(v[i]);
            if (st.size() > k)
            {
                st.erase(st.find(v[i - k]));
            }
            if (st.size() == k)
            {
                cout << *(--st.end()) << " ";
            }
        }
        cout << '\n';
    }
}