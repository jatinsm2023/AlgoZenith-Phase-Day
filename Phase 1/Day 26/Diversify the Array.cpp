#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[i]=x;
            mp[x]++;
        }
        int x = mp.size() + k;
        int m1 = x * (x - 1) / 2;
        int m2 = n * (n - 1) / 2;
        int more =0;
        for(int i=0; i<n; i++)
        {
            if(k==0)break;
            while(mp[a[i]]>=2 && k>0){
                mp[a[i]]--;
                k--;
            }
        }
        for (auto x : mp)
        {
            if (x.second >= 2)
            {
                more += x.second * (x.second - 1) / 2;
            }
        }
        cout << m2 - more << '\n';
        
    }
}
