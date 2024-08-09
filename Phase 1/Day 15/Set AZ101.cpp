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
        set<int> st;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "add")
            {
                int x;
                cin >> x;
               st.insert(x);
            }
            else if (s == "erase")
            {
                int x;
                cin >> x;
                if (st.find(x)!=st.end())
                {
                    st.erase(x);
                }
            }
            else if (s == "find")
            {
                int x;
                cin >> x;
                if (st.find(x)!=st.end())
                {
                    cout << "YES" << '\n';
                }
                else
                    cout << "NO" << '\n';
            }
            else if(s=="print")
            {
                for(auto x: st){
                    cout<<x<<" ";
                }
                cout<<'\n';
            }
            else if(s=="empty"){
                st.clear();
            }
        }
    }
}