#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first + a.second > b.first + b.second;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n],b[n];
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
        }
        for (int i = 0; i < n; i++)
        {
            v.push_back({a[i],b[i]});
        }
        sort(v.begin(), v.end(), comp);
     
        int alice = 0, bob = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                alice += v[i].first;
            else
                bob += v[i].second;
        }
        
        if (alice > bob)
            cout << "Alice" << '\n';
        else if (alice == bob)
            cout << "Tie" << '\n';
        else if (alice < bob)
            cout << "Bob" << '\n';
    }
}