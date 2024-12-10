#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define F first
#define S second
#define int long long
#define print(v)for (auto x : v)cout << x << ' ';cout << endl;
#define yes() cout << 'YES<<endl';
#define no() cout << 'NO<<endl';
using state = pair<int, int>;
const int mod = 1e9 + 7;
inline void add(int &a, int b){a += b;if (a >= mod)a -= mod;}
inline void sub(int &a, int b){a -= b;if (a < 0)a += mod;}
inline int mul(int a, int b) { return (int)((long long)a * b % mod); }
inline int binpow(int a, int b){int res = 1;while (b){if (b & 1)res = mul(res, a);a = mul(a, a);b >>= 1;}return res;}



string s;
int dp[1010][1010];

int rec(int l, int r)
{
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];

    int ans = 1e9;
    if(s[l]==s[r]) ans = rec(l+1,r-1);
    ans = min({ans,rec(l+1,r)+1,rec(l,r-1)+1});
    return dp[l][r] = ans;
}

void solve()
{
    cin>>s;
    for(int i=0; i<1010; i++){
        for(int j=0;j<1010; j++){
            dp[i][j] = -1;
        }
    }
    int n = s.length();
    cout<<rec(0,n-1)<<'\n';
}



signed main()
{
    IOS
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}