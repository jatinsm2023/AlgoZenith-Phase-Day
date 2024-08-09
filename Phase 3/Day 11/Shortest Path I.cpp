#include <bits/stdc++.h>
using namespace std;

#define int long long
using state = pair<int, int>;
#define F first
#define S second

// Global Variables
int n, m;
vector<vector<state>> g;

void solve() {
    cin >> n >> m;
    g.assign(n + 1, vector<state>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    vector<int> dis(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    dis[1] = 0;

    priority_queue<state, vector<state>, greater<state>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        state temp = pq.top();
        pq.pop();
        int node = temp.S;
        if (vis[node]) continue;
        vis[node] = true;

        for (auto v : g[node]) {
            int next = v.F;
            int wt = v.S;
            if (dis[next] > dis[node] + wt) {
                dis[next] = dis[node] + wt;
                pq.push({dis[next], next});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
            cout << dis[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    solve();
    
    return 0;
}
