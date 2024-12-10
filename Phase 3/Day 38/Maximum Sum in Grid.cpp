#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

#define print(v) for (auto x : v) cout << x << ' '; cout << endl;

const int mod = 1e9 + 7;
inline void add(int &a, int b) { a += b; if (a >= mod) a -= mod; }
inline void sub(int &a, int b) { a -= b; if (a < 0) a += mod; }
inline int mul(int a, int b) { return a * b % mod; }
inline int binpow(int a, int b) { int res = 1; while (b) { if (b & 1) res = mul(res, a); a = mul(a, a); b >>= 1; } return res; }

int n, m;
vector<vector<int>> a, b, prefix;
vector<int> c;

void solve() {
    a.clear();
    b.clear();
    prefix.clear();
    c.clear();
    cin >> n >> m;
    b.resize(n, vector<int>(m));
    
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    
    if (n >= m) {
        a.assign(b.begin(), b.end());
    } else {
        a.resize(m, vector<int>(n)); 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = b[j][i]; 
            }
        }
        swap(n, m); 
    }

    
    prefix.assign(n, vector<int>(m, 0));
    c.assign(n, 0);

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            prefix[i][j] = a[i][j];
            if (j > 0) {
                prefix[i][j] += prefix[i][j-1];
            }
        }
    }

    int maxans = -1e9;

    
    for (int i = 0; i < m; ++i) { 
        for (int j = i; j < m; ++j) { 
            
            for (int k = 0; k < n; ++k) {
                c[k] = prefix[k][j] - (i > 0 ? prefix[k][i-1] : 0);
            }

            
            int sum = 0;
            int msum = -1e9;
            for (int k = 0; k < n; ++k) {
                sum += c[k];
                msum = max(msum, sum);
                if (sum < 0) {
                    sum = 0;
                }
            }
            maxans = max(maxans, msum);
        }
    }

    cout << maxans << '\n';
}

signed main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
