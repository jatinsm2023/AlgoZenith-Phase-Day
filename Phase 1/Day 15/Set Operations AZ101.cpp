#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    
    int n, m;
    cin >> n >> m;
    set<int> a, b;
    set<int> un;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
        un.insert(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.insert(x);
        un.insert(x);
    }


    set<int> in;
    set<int> diff(a);
    for (auto x : a)
    {
        if(b.find(x)!=b.end()){
            in.insert(x);
            diff.erase(x);
        }

    }

    for(auto x : un){   
        cout<<x<<' ';
    }
    cout<<'\n';
    for(auto x : in){   
        cout<<x<<' ';
    }
    cout<<'\n';
    for(auto x : diff){   
        cout<<x<<' ';
    }
    cout<<'\n';
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
        solve();
    }
}