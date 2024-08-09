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
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        int sol = 0;
        while(pq.size()!=1)
        {
            int x = pq.top();
            pq.pop();
            int y = pq.top();  
            pq.pop();
            sol += x + y;
            pq.push(x + y);
        }
        cout << sol << '\n';
    }
}