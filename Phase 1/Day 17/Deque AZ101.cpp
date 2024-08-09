#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        deque<int> dq;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "insertback")
            {
                int x;
                cin >> x;
                dq.push_back(x);
            }
            else if (s == "eraseback")
            {
                if (!dq.empty())
                    dq.pop_back();
            }
            else if (s == "insertfront")
            {
                int x;
                cin >> x;
                dq.push_front(x);
            }
            else if (s == "erasefront")
            {
                if (!dq.empty())
                    dq.pop_front();
            }
            else if (s == "printfront")
            {
                if (dq.empty())
                {
                    cout << 0 << '\n';
                }
                else
                {
                    cout << dq.front() << '\n';
                }
            }
            else if (s == "printback")
            {
                if (dq.empty())
                {
                    cout << 0 << '\n';
                }
                else
                {
                    cout << dq.back() << '\n';
                }
            }
            else if (s == "print")
            {
                int x;
                cin >> x;
                if ((int)dq.size() > x)
                {
                    cout << dq[x] << '\n';
                }
                else
                    cout << 0 << '\n';
            }
        }
    }
    return 0;
}