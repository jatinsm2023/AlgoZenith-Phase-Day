#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (!visited[v])
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
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited.resize(n + 1, false);
    int cnt = 0;
    for( int i=1; i<=n ;i++)
    {
        if(!visited[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt - 1 << '\n';
}