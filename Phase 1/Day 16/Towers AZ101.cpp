#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        for( int i=0; i< n ;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        multiset<int> ms;
        ms.insert(v[0]);
        for(int i=1; i<n;i++)
        {
            auto it = ms.upper_bound(v[i]);
            if(it==ms.end()){
                ms.insert(v[i]);
            }
            else {
                ms.erase(it);
                ms.insert(v[i]);
            }
        }
        cout<<ms.size()<<'\n';
    }
}