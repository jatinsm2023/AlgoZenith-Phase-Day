#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = -1;
    for (int i = 31; i >= 0; i--)
    {
        int cnt_one = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] & (1 << i))
                cnt_one++;
        }
        if (cnt_one == k)
        {
            vector<int> ne;
            for (int j = 0; j < a.size(); j++)
            {
                if (a[j] & (1 << i))
                {
                    ne.push_back(a[j]);
                }
            }
            ans = ne[0];
            for (int j = 0; j < ne.size(); j++)
            {
                ans = ans & ne[j];
            }
            return ans;
        }
        else if(cnt_one>k){
            vector<int> ne;
            for (int j = 0; j < a.size(); j++)
            {
                if (a[j] & (1 << i))
                {
                    ne.push_back(a[j]);
                }
            }
            a.resize(0);
            for (int j = 0; j < ne.size(); j++)
            {
                a.push_back(ne[j]);
            }
        }
    }
    if(ans==-1){
        ans = a[0];
        for (int i = 0; i < k; i++)
        {
            ans = ans & a[i];
        }
        return ans;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cout<<solve()<<'\n';
    }
}