#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define print(v) for( auto x : v)cout<<x<<' '; cout<<endl;
#define yes() cout<<'YES<<endl';
#define no() cout<<'NO<<endl';
using state = pair<int,int>;

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> sieve(n+1);
    for(int i=2; i<=n; i++){
        sieve[i] = i;
    }

    for(int i=2; i<=n; i++){
        if(sieve[i]==i){
            for( int j=i*i; j<=n; j+=i){
                if(sieve[j]==j){
                    sieve[j] = i;
                }
            }
        }
    }

    while(n!=1){
        cout<<sieve[n]<<' ';
        n/=sieve[n];
    }
    
}