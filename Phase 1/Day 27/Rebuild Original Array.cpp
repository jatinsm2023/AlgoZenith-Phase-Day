#include <bits/stdc++.h>
using namespace std;

#define int long long

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        multiset<int> s;
        int x;
        cin >> x;
        int l = binpow(2, n);
        for (int i = 1; i < l; i++)
        {
            cin >> x;
            s.insert(x);
        }
        vector<int> v(1, 0);
        vector<int> ans;
        while (!s.empty())
        {
            vector<int> ne(0);
            int it = *s.begin();
            ans.push_back(it);
            int m = v.size();
            for( int i=0; i<m; i++){
                ne.push_back(v[i]+it);
                v.push_back(v[i]+it);
            }
            for(auto x : ne){
                if(s.find(x)!=s.end()){
                    s.erase(s.find(x));
                }
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}