#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<vector<int>> g;
vector<vector<int>> backedge;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m; cin >> n >> m;
    g.resize(n+1);
    backedge.resize(n+1);
    int in_degree[n+1], dp[n+1];
    for(int i = 0; i <= n; i++){
        in_degree[i] = 0;
        dp[i] = 0;
    }
    dp[1] = 1;
    for(int i = 0; i < m; i++){
        int a,b; cin >> a >> b;
        g[a].push_back(b);
        backedge[b].push_back(a);
        in_degree[b]++;
    }
    
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int next : g[node]) {
            in_degree[next]--;
            if(in_degree[next] == 0) q.push(next);
        }

        for(int prev : backedge[node]) {
            dp[node] = (dp[node] + dp[prev]) % 1000000007;
        }
    }
    cout << dp[n] << endl;
    return 0;
}