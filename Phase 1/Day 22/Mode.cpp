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
        multiset<pair<int,int>> ms;
        map<int,int> mp;
        int mode = 0;
        while (q--)
        {
            int n;
            cin>>n;
            mp[n]++;
            auto it = ms.find({mp[n]-1,n});
            if(it==ms.end()){
                ms.insert({mp[n],n});
            }
            else {
                ms.erase(it);
                ms.insert({mp[n],n});
            }
            auto max = ms.end();
            max--;
            cout<<max->second<<"\n";
        }
    }
}