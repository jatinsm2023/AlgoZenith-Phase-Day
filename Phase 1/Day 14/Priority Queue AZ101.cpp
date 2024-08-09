#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        priority_queue<int> pq;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "add")
            {
                int x;
                cin >> x;
                pq.push(x);
            }
            else if (s == "remove" && !pq.empty())
            {
                pq.pop();
            }
            else if (s == "print")
            {
                if (pq.empty())
                {
                    cout << 0 << '\n';
                }
                else
                {
                    cout << pq.top() << '\n';
                }
            }
        }
    }
    return 0;
}