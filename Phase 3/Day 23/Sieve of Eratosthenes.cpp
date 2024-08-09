#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define print(v) for( auto x : v)cout<<x<<' '; cout<<endl;
#define yes() cout<<'YES<<endl';
#define no() cout<<'NO<<endl';
using state = pair<int,int>;
const int MAX = 1000;
signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> sieve(MAX,1);

    for(int i=2; i<sieve.size(); i++){
        if(sieve[i]==1){
            for( int j=i*i; j<sieve.size(); j+=i){
                sieve[j] = 0;
            }
        }
    }

    for(int i=2; i<sieve.size(); i++){
        if(sieve[i]==1){
            cout<<i<<' ';
        }
    }
}