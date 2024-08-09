#include <bits/stdc++.h>
using namespace std;

#define int long long

bool comp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second < b.second;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<string, int>> v;
        for (int i = 0; i < n; i++)
        {
            string x;
            int y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end(), comp);
        for (int i=0; i<v.size(); i++)
        {
            cout << v[i].first << " " << v[i].second <<'\n';
        }
    }
}