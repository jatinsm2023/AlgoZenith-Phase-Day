#include <bits/stdc++.h>
using namespace std;

#define int long long

struct bag
{
    int k;
    int sumk;
    multiset<int> mt1, mt2;
    void init(int _k)
    {
        k = _k;
        sumk = 0;
        mt1.clear();
        mt2.clear();
    }

    void insert(int x)
    {
        mt1.insert(x);
        sumk += x;
        if (mt1.size() > k)
        {
            int t = *mt1.begin();
            mt1.erase(mt1.find(t));
            mt2.insert(t);
            sumk-=t;
        }
    }
    void remove( int x){
        if(mt1.find(x)!=mt1.end()){
            mt1.erase(mt1.find(x));
            sumk-=x;
        }
        else if(mt2.find(x)!=mt2.end()){
            mt2.erase(mt2.find(x));
        }
        if(mt1.size()<k && !mt2.empty()){
            int t = *mt2.rbegin();
            mt2.erase(mt2.find(t));
            mt1.insert(t);
            sumk+=t;
        }
    }
    int getsum(){
        return sumk;
    }
};

signed main()
{
    int q, k;
    cin >> q >> k;
    bag b;
    b.init(k);
    while(q--){
        int s;
        cin>>s;
        if(s==1){
            int x;
            cin>>x;
            b.insert(x);
        }
        else if(s==2){
            int x;
            cin>>x;
            b.remove(x);
        }
        else if(s==3){
            char c;
            cin>>c;
            if(c=='?'){
                cout<<b.sumk<<"\n";
            }
        }
    }
}