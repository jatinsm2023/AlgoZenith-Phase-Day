#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dp[505][505];
int a[505];

int rec(int s, int e) {

    if (s > e) return 0;
    if (dp[s][e] != -1) return dp[s][e];
    if (s == e) return dp[s][e] = 1;
    int ans = 1 + rec(s + 1, e);
    if (a[s] == a[s + 1])
        ans = min(ans, 1 + rec(s + 2, e));
    for (int k = s + 2; k <= e; ++k) {
        if (a[s] == a[k])
            ans = min(ans, rec(s + 1, k - 1) + rec(k + 1, e));
    }

    return dp[s][e] = ans;
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << rec(1, n) << "\n";
    }
    return 0;
}
