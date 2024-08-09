#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<vector<int>> g;
vector<int> subtreesz;

void dfs(int node, int par)
{
    subtreesz[node] = 1;
    for (auto &child : g[node])
    {
        if (child == par)
            continue;
        dfs(child, node);
        subtreesz[node] += subtreesz[child];
    }
}

void sum_of_distances()
{
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += subtreesz[i]*(n-subtreesz[i]);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    subtreesz.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    sum_of_distances();
}