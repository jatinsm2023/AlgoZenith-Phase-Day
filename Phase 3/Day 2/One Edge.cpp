#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<int>> g;
vector<int> vis;

int temp_nodes = 0;
void dfs(int node)
{

    vis[node] = 1;
    temp_nodes++;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }
    int sumsq = 0;
    int sqsum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            temp_nodes = 0;
            dfs(i);
            sumsq += temp_nodes;
            sqsum += temp_nodes * temp_nodes;
        }
    }

    cout << (sumsq * sumsq - sqsum) / 2 << '\n';
}