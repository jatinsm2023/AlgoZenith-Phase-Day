#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define print(v) for( auto x : v)cout<<x<<' '; cout<<endl;
#define yes() cout<<'YES<<endl';
#define no() cout<<'NO<<endl';
using state = pair<int,int>;
const int mod = 1e9+7;
inline void add(int &a, int b){a += b;if (a >= mod)a -= mod;}
inline void sub(int &a, int b){a -= b;if (a < 0)a += mod;}
inline int mul(int a, int b){return (int)((long long)a * b % mod);}
inline int binpow(int a, int b){int res = 1;while (b){if (b & 1) res = mul(res, a);a = mul(a, a);b >>= 1;}return res;}


signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;

        cout << n / m + n % m << "\n";
    }
}