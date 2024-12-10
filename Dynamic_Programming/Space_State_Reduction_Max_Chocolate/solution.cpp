#include <bits/stdc++.h>
using namespace std;

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


int dx[] = {0,1};
int dy[] = {1,0};
int n,m;

int check(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m)return 1;
    return 0;
}

int dp[51][51][51];
int arr[51][51];

int rec(int i,int j, int a, int b){
    // prunning
    // base case
    if(i==n-1 && j==m-1)return arr[i][j];
    if(dp[i][j][a]!=-1)
        return dp[i][j][a];
    int initial_cost = arr[i][j]+arr[a][b];
    if(i==a && j==b){
        initial_cost = arr[i][j];
    }
    int ans=0;
    for(int p=0;p<2;p++){
        for(int q=0; q<2;q++){
            int ni,nj,na,nb;
            ni = i+dx[p];
            nj = j+dy[p];
            na = a+dx[q];
            nb = b+dy[q];
            if(check(ni,nj) && check(na,nb)){
                ans = max(ans,initial_cost+rec(ni,nj,na,nb));
            }
        }
    }
    return dp[i][j][a] = ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0;j<m; j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0,0)<<endl;
}