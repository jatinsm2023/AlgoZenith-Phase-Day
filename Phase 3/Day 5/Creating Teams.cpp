// Find Cycle
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
vector<int> vis;

// col can be 1,2.
int n, m;
bool is_odd_cycle = false;

void dfs(int node, int color)
{
    col[node] = color; 
    vis[node]= 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        { 
            dfs(v,3-color);
        }
        else if(col[v] == col[node]){
            is_odd_cycle= true;
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    vis.assign(n+1,0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i,1);
        }
    }

    if (!is_odd_cycle)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}
int main()
{
    solve();
}