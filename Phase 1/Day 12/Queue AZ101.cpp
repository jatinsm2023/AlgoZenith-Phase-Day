#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        queue<int> queue;
        string s;
        while (q--)
        {
            cin >> s;
            if (s == "add")
            {
                int n;
                cin >> n;
                queue.push(n);
            }
            else if (s == "remove" && !queue.empty())
            {
                queue.pop();
            }
             else if (s == "print")
            {
                if (queue.empty())
                {
                    cout << "0\n";
                }
                else
                {
                    cout << queue.front() << '\n';
                }
            }
        }
    }
    return 0;
}